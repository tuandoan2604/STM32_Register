#include "stm32f4xx.h"
// set bit 
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
// Address_gpiod
#define TUAN_PERIPH_BASE           0x40000000UL /*!< Peripheral base address in the alias region */
#define TUAN_AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define TUAN_GPIOD            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIO_PIN_15                0x00008000  /* Pin 15 selected   */
#define GPIO_PIN_14                0x00004000  /* Pin 14 selected   */
#define GPIO_PIN_13                0x00002000  /* Pin 13 selected   */
#define GPIO_PIN_12                0x00001000  /* Pin 13 selected   */
unsigned int Delay =0;
void GPIO_Configs(void);
 int main(){
//	 // enable bit 3 (portD)
//	 RCC->AHB1ENR |= (1<<3);
//	 /* Configure IO Direction mode (Input, Output, Alternate or Analog) */
//	 GPIOD->MODER &= ~(3 << (30));
//	 GPIOD->MODER |= ((3) << (30));
//	 /* Configure the IO Output Type */
//	 GPIOD->OTYPER = ~(1 << 15) ;
	 SystemInit();
	 GPIO_Configs();
	 while(1)
		{
			 GPIOD->ODR |= GPIO_PIN_15;
			 GPIOD->ODR |= GPIO_PIN_14;
			 GPIOD->ODR |= GPIO_PIN_13;
			 GPIOD->ODR |= GPIO_PIN_12;
			 for (Delay=0;Delay<500000;Delay++);
			 
			 GPIOD->ODR &= ~GPIO_PIN_15;
			 GPIOD->ODR &= ~GPIO_PIN_14;
			 GPIOD->ODR &= ~GPIO_PIN_13;
			 GPIOD->ODR &= ~GPIO_PIN_12;
			for (Delay=0;Delay<500000;Delay++);
		}
}

void GPIO_Configs(void)
{
	//RCC->AHB1ENR |=RCC_AHB1ENR_GPIODEN;
	// enable clocks(portD)
	RCC->AHB1ENR |= (1 << 3);
	/* Configure IO Direction mode (Input, Output, Alternate or Analog) */
	GPIOD->MODER |= (1 << 30)+(1 << 28)+(1 << 26)+ (1 << 24) ; // mode output
	//	 /* Configure the IO Output Type */
	GPIOD->OTYPER &= (1 << 15)+(1 << 14)+(1 << 13)+ (1 << 12) ; // push pull 
	GPIOD->OSPEEDR |= (1 << 31)+(1 << 29)+(1 << 27)+ (1 << 25); // high speed
	GPIOD->PUPDR &= 0x3C000000; // no pull
}

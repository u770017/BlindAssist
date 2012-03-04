#include<stdio.h>
#include<sys/io.h>

#define w83627e 0x2e
#define w83627f 0x2f
//This is code for the PmodKYPD working on an Intel Development Board

void initreg()
{
  //printf("Enter the Extended Function Mode\n");
        outb(0x87,w83627e);
        outb(0x87,w83627e);
  //printf("Select multi function pin as GPIO\n");
        outb(0x2C,w83627e);
        outb(0x02,w83627f);
  //printf("Select logic device GPIO 2-5\n");
        outb(0x07,w83627e);
        outb(0x09,w83627f);
  //printf("Activate GPIO 3, 0b00000010=0x02\n");
        outb(0x30,w83627e);
        outb(0x02,w83627f);
  //printf("Set GPIO 30-36 as output, GPIO 37 as input, 0b10000000\n");
        outb(0xF0,w83627e);
        outb(0xF0,w83627f);
  //printf("Set GPIO 30-37 inversion register as not inverted, 0b00000000\n");
        outb(0xF2,w83627e);
        outb(0x00,w83627f);
}

void exitreg(){
  //printf("Exit Extended Function Mode\n");
        outb(0xAA,w83627e);
}

void writebyte(unsigned char a){
  initreg();
        outb(0xF1,w83627e);
        outb(a,w83627f);
        exitreg();
}

unsigned char readbyte(){
  initreg();
        unsigned char a;
        outb(0xF1,w83627e);
        a=inb(w83627f);
        exitreg();
        return a;
}

int main(void)
{
  unsigned char a=0;
  int state = 0;
        return a;
}

int main(void)
{
  unsigned char a=0;
  int state = 0;
  iopl(3);

  while(1)
  {
        a=readbyte();
         switch (a){
            case 0xf0:
              switch (state){
                case 1:
                 printf("1 was pressed\n");
                 state = 0;
                 break;
                case 2:
                 printf("2 was pressed\n");
                 state = 0;
                 break;
                case 3:
                 printf("3 was pressed\n");
                 state = 0;
                 break;
                case 4:
                 printf("4 was pressed\n");
                 state =0;
                 break;
                 default:
                break;
                }
                 break;
            case 0x70:
                 state =1;
                 //printf("1 was pressed\n");
                 break;
            case 0xb0:
                 state =2;
                 //printf("2 was pressed\n");
                 break;
            case 0xd0:
                 state =3;
                 //printf("3 was pressed\n");
                 break;
            case 0xe0:
                 state = 4;
                 //printf("A was pressed\n");
                 break;
           default:
                 break;
            }
        usleep(100000);


  }
        return 0;
}

#include<stdio.h>

char *str[5]={"Sheldon","Leonard","Penny","Rajesh","Howard"};

int main()
{
    int a,b,c;
    scanf("%d",&a);
    a--;
    b=5;
    c=1;
    while(a>=0)
    {
        a-=b;
        b<<=1;
        c<<=1;
    }

    a+=b>>1;
    puts(str[a/(c>>1)]);
}
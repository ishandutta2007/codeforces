#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int min(int a,int b)
{
    if(a<b)
        return a;
    else 
        return b;
}
int main()
{
    int c,v0,v1,a,l,pages=0,possi=0,days=0;
    scanf("%d%d%d%d%d",&c,&v0,&v1,&a,&l);
    possi=v0;
    while(pages<c)
    {
        days++;
       //printf("%d %d\n",pages,min(pages,l));
        pages+=possi-(min(pages,l));
        possi+=a;
        if(possi>v1)
            possi=v1;
    }
    printf("%d",days);
}
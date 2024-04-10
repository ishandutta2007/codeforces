#include<stdio.h>

int main()
{
    int max=0;
    int now=0;
    int a,b;
    scanf("%*d");
    while(~scanf("%d%d",&a,&b))
    {
        now+=b-a;
        if(max<now)max=now;
    }
    printf("%d",max);
}
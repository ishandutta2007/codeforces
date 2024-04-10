#include<stdio.h>

int gcd(int a,int b)
{
    if(a)return gcd(b%a,a);
    return b;
}

int main()
{
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    while(n>0)
    {
        n-=gcd(a,n);
        if(n<0)return 0*puts("1");
        else if(n==0)return 0*puts("0");
        n-=gcd(b,n);
    }
    puts("1");
    return 0;
}
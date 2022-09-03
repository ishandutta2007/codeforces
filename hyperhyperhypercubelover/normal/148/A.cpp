#include<stdio.h>

int gcd(int a,int b)
{
    if(a)return gcd(b%a,a);
    return b;
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int main()
{
    int w,x,y,z;
    int a,b,c,d,e;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    w=e/a+e/b+e/c+e/d;
    x=e/lcm(a,b)+e/lcm(a,c)+e/lcm(a,d)+e/lcm(b,c)+e/lcm(b,d)+e/lcm(c,d);
    y=e/lcm(lcm(a,b),c)+e/lcm(lcm(a,b),d)+e/lcm(lcm(a,c),d)+e/lcm(lcm(b,c),d);
    z=e/lcm(lcm(lcm(a,b),c),d);
    printf("%d",w-x+y-z);
}
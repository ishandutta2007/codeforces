#include<stdio.h>
long long a,b,c,d,e,f,ans;
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&e,&f);
    ans+=(a+b+c)*(a+b+c);
    ans-=(a*a)+(c*c)+(e*e);
    printf("%I64d",ans);
}
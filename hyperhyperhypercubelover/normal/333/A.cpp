#include<cstdio>

int main()
{
	long long i,n;
	scanf("%I64d",&n);
    for(i=1;i<=n;i*=3);
    while(n%i)i/=3;
    i*=3;
    n=(n+i-1)/i*i;
    printf("%I64d",n/i);
}
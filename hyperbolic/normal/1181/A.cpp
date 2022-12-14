#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	if((a%c)<=(b%c))
	{
		if((a%c)+(b%c)>=c) printf("%lld %lld\n",(a/c)+(b/c)+1,c-(b%c));
		else printf("%lld 0\n",(a/c)+(b/c));
	}
	else
	{
		if((a%c)+(b%c)>=c) printf("%lld %lld\n",(a/c)+(b/c)+1,c-(a%c));
		else printf("%lld 0\n",(a/c)+(b/c));
	}
}
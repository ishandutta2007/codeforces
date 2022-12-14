#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	//a*h>=b
	if(b%a==0) printf("%lld",b/a);
	else printf("%lld",b/a+1);
	
}
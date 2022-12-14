#include <stdio.h>

int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if(a%b==0) printf("0");
	else
	{
		long long int e = a%b;
		long long int f = b-e;
		printf("%lld",e*d<f*c?e*d:f*c);
	}
}
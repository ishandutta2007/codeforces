#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	long long int s = 2*c;
	if(a>b)
	{
		s += 2*b;
		s++;
	}
	else if(a==b) s += 2*b;
	else
	{
		s += 2*a;
		s++;
	}
	printf("%lld",s);
}
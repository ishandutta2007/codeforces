#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		long long int b = 1;
		while(10*b<=a) b*=10;
		printf("%lld\n",a-b);
	}
}
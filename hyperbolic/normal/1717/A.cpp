#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		printf("%lld\n",a+a/2 *2+a/3 * 2);
	}
}
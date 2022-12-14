#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		long long int sum = a*(a+1)/2;
		for(long long int i=1;i<=a;i*=2) sum -= 2*i;
		printf("%lld\n",sum);
	}
}
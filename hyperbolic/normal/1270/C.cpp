#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		long long int sum1 = 0,sum2 = 0;
		for(int i=1;i<=a;i++) sum1 += x[i];
		for(int i=1;i<=a;i++) sum2 ^= x[i];
		printf("2\n");
		printf("%lld %lld\n",sum2,sum1+sum2);
	}
}
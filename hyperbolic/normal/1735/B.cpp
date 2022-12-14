#include <stdio.h>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int limit = 2*x[1]-1;
		long long int sum = 0;
		for(int i=1;i<=a;i++) if(x[i]>limit) sum += ((x[i]-1)/limit);
		printf("%lld\n",sum);
	}
}
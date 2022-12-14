#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		long long int sum = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			sum += b, sum %= a;
		}
		printf("%lld\n",(long long int)sum*(a-sum));
	}
}
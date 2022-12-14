#include <stdio.h>

int x[100010];
long long int sum[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) sum[i] = sum[i-1]+x[i];
		
		long long int ans = 0;
		for(int i=0;i<=a;i++)
		{
			long long int val = sum[i]-(long long int)i*b;
			int C = 1;
			for(int j=1;j<=30&&i+j<=a;j++)
			{
				C*=2;
				val += x[i+j]/C;
			}
			ans = ans>val?ans:val;
		}
		printf("%lld\n",ans);
	}
}
#include <stdio.h>

int x[200010];
long long int sum[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int c = b-a;
		if(c>0)
		{
			for(int i=1;i<=a;i++) x[i] += c;
			b = a;
		}
		
		long long int ans = 0;
		for(int i=1;i<=a;i++) sum[i] = sum[i-1]+x[i];
		for(int i=b;i<=a;i++)
		{
			long long int val = sum[i] - sum[i-b];
			ans = ans>val?ans:val;
		}
		printf("%lld\n",ans + (long long int)b*(b-1)/2);
	}
}
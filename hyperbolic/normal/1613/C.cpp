#include <stdio.h>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		long long int min = 1, max = (long long int)1e18;
		long long int ans = (long long int)1e18;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			
			long long int sum = h;
			for(int i=2;i<=a;i++) sum += x[i]-x[i-1]<h?x[i]-x[i-1]:h;
			if(sum>=b)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%lld\n",ans);
	}
}
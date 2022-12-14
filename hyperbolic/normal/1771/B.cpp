#include <stdio.h>

int limit[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) limit[i] = a+1;
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(c>d)
			{
				int t = d;
				d = c;
				c = t;
			}
			limit[c] = limit[c]<d?limit[c]:d;
		}
		for(int i=a-1;i>=1;i--) limit[i] = limit[i]<limit[i+1]?limit[i]:limit[i+1];
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int L = i, R = limit[i]-1;
			ans += (R-L+1);
		}
		printf("%lld\n",ans);
	}
}
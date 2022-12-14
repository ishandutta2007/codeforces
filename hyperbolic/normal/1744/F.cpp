#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			x[b] = i;
		}
		
		long long int ans = 0;
		int L = x[0], R = x[0];
		for(int i=1;i<a;i++)
		{
			int p = x[i];
			if(L<=p&&p<=R) continue;
			
			int s,t;
			if(p<L) s = L-p-1, t = a-R;
			if(p>R) s = L-1, t = p-R-1;
			int C = (R-L+1) - i;
			int limit = i-C;
			
			if(p<L)
			{
				for(int j=0;j<=s;j++)
				{
					int val = limit-j<t?limit-j:t;
					val = val>-1?val:-1;
					ans += (val+1);
				}
				L = p;
			}
			else
			{
				for(int j=0;j<=t;j++)
				{
					int val = limit-j<s?limit-j:s;
					val = val>-1?val:-1;
					ans += (val+1);
				}
				R = p;
			}
		}
		ans++;
		printf("%lld\n",ans);
	}
}
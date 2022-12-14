#include <stdio.h>

long long int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		long long int ans = 0;
		for(int i=1;i<=a-2;i++)
		{
			if(x[i]>0)
			{
				if(x[i+1]>0)
				{
					x[i+1] += x[i];
					x[i] = 0;
				}
				else
				{
					ans++;
					x[i+1] += x[i];
					x[i] = 0;
				}
			}
		}
		printf("%lld\n",ans+x[a-1]);
	}
}
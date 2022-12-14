#include <stdio.h>

long long int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		long long int b;
		scanf("%d%lld",&a,&b);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		for(int i=1;i<=a;i++) y[i] = y[i-1] + x[i];
		
		long long int ans = 0;
		for(int i=2;i<=a;i++)
		{
			if(b*y[i-1]<100*x[i])
			{
				if((100*x[i])%b==0)
				{
					long long int t = (100*x[i])/b - y[i-1];
					ans = ans>t?ans:t;
				}
				else
				{
					long long int t = (100*x[i])/b+1 - y[i-1];
					ans = ans>t?ans:t;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
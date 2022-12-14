#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int L = a-100>1?a-100:1;
		long long int ans = -1234567890;
		for(int i=L;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				long long int t = (long long int)i*j - (long long int)b*(x[i]|x[j]);
				ans = ans>t?ans:t;
			}
		}
		printf("%lld\n",ans);
	}
}
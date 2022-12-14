#include <stdio.h>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		long long int ans = 0;
		for(int i=1;i<a;i++)
		{
			long long int t = (long long int)x[i]*x[i+1];
			ans = ans>t?ans:t;
		}
		printf("%lld\n",ans);
	}
}
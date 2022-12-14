#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int p = 0;
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			ans += (long long int)(x[i]-p)*c;
			if((long long int)c*(a-i)>=b)
			{
				ans += (long long int)(x[i]-p)*b;
				p = x[i];
			}
		}
		printf("%lld\n",ans);
	}
}
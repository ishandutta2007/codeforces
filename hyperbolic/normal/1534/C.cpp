#include <stdio.h>
#define MOD 1000000007

int x[400010],y[400010],next[400010],check[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) next[x[i]] = y[i];
		
		long long int ans = 1;
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				ans *= 2, ans %= MOD;
				int v = i;
				while(check[v]==0) check[v] = 1, v = next[v];
			}
		}
		printf("%lld\n",ans);
	}
}
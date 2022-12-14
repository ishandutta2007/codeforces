#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int x[4010],y[4010];
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
		
		long long int ans = 0;
		for(int i=1;i<a;i++)
		{
			int val1 = abs(x[i]-x[i+1]) + abs(y[i]-y[i+1]);
			int val2 = abs(x[i]-y[i+1]) + abs(y[i]-x[i+1]);
			ans += (val1<val2?val1:val2);
		}
		printf("%lld\n",ans);
	}
}
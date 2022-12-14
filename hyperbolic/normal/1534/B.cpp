#include <stdio.h>

int x[400010];
int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		x[0] = x[a+1] = 0;
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int t = x[i-1]>x[i+1]?x[i-1]:x[i+1];
			if(x[i]>t)
			{
				ans += (x[i]-t);
				x[i] = t;
			}
		}
		
		for(int i=1;i<=a+1;i++) ans += abs(x[i]-x[i-1]);
		printf("%lld\n",ans);
	}
}
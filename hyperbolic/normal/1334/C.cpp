#include <stdio.h>
long long int MAX = 1;

long long int x[300010],y[300010],next[300010];
int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld%lld",&x[i],&y[i]);
		x[0] = x[a], y[0] = y[a];
		x[a+1] = x[1], y[a+1] = y[1];
		for(int i=0;i<=a;i++) next[i] = y[i]<x[i+1]? x[i+1]-y[i]:0;
		
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += next[i];
		
		long long int ans = MAX;
		for(int i=1;i<=a;i++)
		{
			long long int s = sum - next[i-1] + x[i];
			ans = ans<s?ans:s;
		}
		printf("%lld\n",ans);
	}
}
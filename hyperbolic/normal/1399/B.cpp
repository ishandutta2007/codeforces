#include <stdio.h>
#include <algorithm>
int x[110],y[110];
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
		
		int m1 = x[1] , m2 = y[1];
		for(int i=2;i<=a;i++) m1 = m1<x[i]?m1:x[i];
		for(int i=2;i<=a;i++) m2 = m2<y[i]?m2:y[i];
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int s = x[i]-m1;
			int t = y[i]-m2;
			ans += (s>t?s:t);
		}
		printf("%lld\n",ans);
	}
}
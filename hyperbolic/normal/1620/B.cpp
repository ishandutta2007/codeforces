#include <stdio.h>

long long int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%d%d",&a,&b);
		int c;
		
		long long int ans = 0;
		scanf("%d",&c);
		for(int i=1;i<=c;i++) scanf("%lld",&x[i]);
		ans = ans>(x[c]-x[1])*b?ans:(x[c]-x[1])*b;
		scanf("%d",&c);
		for(int i=1;i<=c;i++) scanf("%lld",&x[i]);
		ans = ans>(x[c]-x[1])*b?ans:(x[c]-x[1])*b;
		scanf("%d",&c);
		for(int i=1;i<=c;i++) scanf("%lld",&x[i]);
		ans = ans>(x[c]-x[1])*a?ans:(x[c]-x[1])*a;
		scanf("%d",&c);
		for(int i=1;i<=c;i++) scanf("%lld",&x[i]);
		ans = ans>(x[c]-x[1])*a?ans:(x[c]-x[1])*a;
		printf("%lld\n",ans);
	}
}
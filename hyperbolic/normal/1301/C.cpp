#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		long long int ans = a*(a+1)/2;
		
		long long int c = (a-b)/(b+1);
		
		long long int d = (a-b)-c*(b+1);
		long long int e = (b+1)-d;
		
		ans -= e*c*(c+1)/2;
		ans -= d*(c+1)*(c+2)/2;
		printf("%lld\n",ans);
	}
}
#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		long long int b2 = ((a-1)/b+1)*b;
		long long int c2 = ((a-1)/c+1)*c;
		long long int d2 = ((a-1)/d+1)*d;
		long long int ans = b2-a;
		ans = ans<c2-a?ans:c2-a;
		ans = ans<d2-a?ans:d2-a;
		printf("%lld\n",ans);
	}
}
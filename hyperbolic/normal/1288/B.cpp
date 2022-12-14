#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		long long int ans = 0;
		scanf("%d%d",&a,&b);
		for(int c=9;c<=b;c=10*c+9) ans += a;
		printf("%lld\n",ans);
	}
}
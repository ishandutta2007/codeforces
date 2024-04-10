#include <stdio.h>
#define MOD 1000000007

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		long long int ans = 1;
		for(int i=1;i<=b;i++) ans*=a, ans%=MOD;
		printf("%lld\n",ans);
	}
}
#include <stdio.h>
#define MOD 998244353
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	// (a-1) + (b-1) + 1 +1
	// a+b
	
	long long int ans = 1;
	for(int i=1;i<=a+b;i++)
	{
		ans *=2;
		ans%= MOD;
	}
	printf("%lld",ans);
}
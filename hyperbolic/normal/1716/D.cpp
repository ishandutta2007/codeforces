#include <stdio.h>
#define MOD 998244353

int a,b;
long long int DP[200010],temp[200010],ans[200010];
int main()
{
	scanf("%d%d",&a,&b);
	DP[0] = 1;
	for(int j=0;j<=700;j++)
	{
		for(int i=0;i<=a;i++) temp[i] = 0;
		for(int i=j+b;i<=a;i++)
		{
			temp[i] += DP[i-j-b] + temp[i-j-b];
			temp[i] %= MOD;
		}
		for(int i=1;i<=a;i++) ans[i] += temp[i], ans[i] %= MOD;
		for(int i=0;i<=a;i++) DP[i] = temp[i];
	}
	
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
}
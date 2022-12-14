#include <stdio.h>
#define MOD 998244353

long long int DP[1000010],sum[1000010];
int count[1000010];
int main()
{
	for(int i=1;i<=1000000;i++) for(int j=i;j<=1000000;j+=i) count[j]++;
	int a;
	scanf("%d",&a);
	
	DP[0] = 1;
	sum[0] = 1;
	for(int i=1;i<=a;i++)
	{
		DP[i] = (sum[i-1]+count[i]-1)%MOD;
		sum[i] = (sum[i-1] + DP[i])%MOD;
	}
	printf("%lld",DP[a]);
}
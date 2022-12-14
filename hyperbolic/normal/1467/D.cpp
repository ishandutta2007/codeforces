#include <stdio.h>
#define MOD 1000000007
long long int x[5010],y[5010];
long long int DP[5010][5010];

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) DP[0][i] = 1;
	for(int i=1;i<=b;i++) for(int j=1;j<=a;j++) DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])%MOD;
	
	for(int j=1;j<=a;j++)
	{
		for(int i=0;i<=b;i++)
		{
			y[j] += (DP[i][j]*DP[b-i][j])%MOD;
			y[j] %= MOD;
		}
	}
	
	long long int sum = 0;
	for(int i=1;i<=a;i++)
	{
		sum += (x[i]*y[i])%MOD;
		sum %= MOD;
	}
	
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		sum += (y[d]*(e-x[d]+MOD))%MOD;
		sum %= MOD;
		x[d] = e;
		printf("%lld\n",sum);
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXK=5005,MOD=1000000007,inv2=(MOD+1)/2;

int dp[MAXK][MAXK];

int quick_pow(int a,int x)
{
	int ret=1;
	while (x)
	{
		if (x&1) ret=(LL)ret*a%MOD;
		a=(LL)a*a%MOD;
		x>>=1;
	}
	return ret;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	dp[0][0]=1;
	for (int i=1;i<=k;i++)
		for (int j=1;j<=i;j++)
			dp[i][j]=((LL)dp[i-1][j-1]*(n-j+1)+(LL)dp[i-1][j]*j)%MOD;
	int ans=0;
	int d=quick_pow(2,n);
	for (int i=1;i<=k&&i<=n;i++)
	{
		d=(LL)d*inv2%MOD;
		ans=(ans+(LL)dp[k][i]*d)%MOD;
	}
	printf("%d",ans);
	return 0;
}
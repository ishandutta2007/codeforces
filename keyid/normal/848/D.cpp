#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=55,MOD=1000000007;

int dp[MAXN][MAXN],inv[MAXN];

int main()
{
	#ifdef KeyID
		freopen("read.txt","r",stdin);
	#endif
	int n,m;
	scanf("%d%d",&n,&m);
	dp[0][1]=1;
	inv[1]=1;
	for (int i=2;i<=n;i++)
		inv[i]=(LL)(MOD-MOD/i)*inv[MOD%i]%MOD;
	for (int i=1;i<=n;i++)
		for (int j=2;j<=i+1;j++)
		{
			int sum=0;
			for (int k=0;k<i;k++)
				for (int l=k+1;l>=j-1;l--)
					sum=(sum+(LL)dp[k][l]*dp[i-1-k][j-1])%MOD;
			(sum*=2)%=MOD;
			for (int k=0;k<i;k++)
				sum=(sum-(LL)dp[k][j-1]*dp[i-1-k][j-1]%MOD+MOD)%MOD;
			for (int k=n;k>i;k--)
				for (int l=k+1;l>=1;l--)
					for (int d=1,C=1;d*i<=k&&d*(j-1)<l;d++)
					{
						C=(LL)C*(sum+d-1)%MOD*inv[d]%MOD;
						dp[k][l]=(dp[k][l]+(LL)dp[k-d*i][l-d*(j-1)]*C)%MOD;
					}
			(dp[i][j]+=sum)%=MOD;
		}
	printf("%d",dp[n][m]);
	return 0;
}
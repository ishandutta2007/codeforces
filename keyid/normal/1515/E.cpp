#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

typedef pair <int,int> pii;

const int MAXN=405;

int pw[MAXN],C[MAXN][MAXN],dp[MAXN][MAXN],tmp[MAXN][MAXN],MOD;

int f(int n)
{
	return pw[n-1];
}

int main()
{
#ifdef KeyID
	freopen("read.txt","r",stdin);
#endif
	int n;
	scanf("%d%d",&n,&MOD);
	pw[0]=1;
	for (int i=1;i<=n;i++)
		pw[i]=pw[i-1]*2%MOD;
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	dp[0][1]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<=i;j++)
			for (int k=0;k<=i;k++)
				tmp[j][k]=0;
		for (int j=0;j<i;j++)
			for (int k=0;j+k<i;k++)
			{
				(tmp[j][k+1]+=dp[j][k])%=MOD;
				if (k)
					tmp[j+k][0]=(tmp[j+k][0]+(LL)dp[j][k]*C[j+k][k]%MOD*f(k))%MOD;
			}
		for (int j=0;j<=i;j++)
			for (int k=0;k<=i;k++)
				dp[j][k]=tmp[j][k];
	}
	int ans=0;
	for (int i=0;i<=n;i++)
		for (int j=1;i+j<=n;j++)
			ans=(ans+(LL)dp[i][j]*C[i+j][j]%MOD*f(j))%MOD;
	printf("%d\n",ans);
	return 0;
}
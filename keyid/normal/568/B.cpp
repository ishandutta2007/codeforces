#include <cstdio>

typedef long long LL;

const int MAXN=4005,MOD=1000000007;

int C[MAXN][MAXN],f[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	f[0]=1;
	for (int i=1;i<n;i++)
		for (int j=0;j<i;j++)
			f[i]=(f[i]+(LL)f[i-j-1]*C[i-1][j])%MOD;
	int ans=0;
	for (int i=0;i<n;i++) ans=(ans+(LL)f[i]*C[n][i])%MOD;
	printf("%d",ans);
	return 0;
}
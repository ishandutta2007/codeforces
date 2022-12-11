#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=55,MOD=1000000007;

int d[MAXN],f[MAXN][MAXN][MAXN],g[MAXN][MAXN],sum1[MAXN],sum2[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	for (int i=1;i<=n;i++)
	{
		sum1[i]=sum1[i-1];
		sum2[i]=sum2[i-1];
		if (d[i]==2)
			sum1[i]++;
		else
			sum2[i]++;
	}
	f[0][0][0]=1;
	for (int i=2;i<=n;i++)
		f[i][0][0]=(LL)(i-1)*f[i-2][0][0]%MOD;
	for (int j=1;j<=n;j++)
		for (int i=0;i<=n;i++)
		{
			int &ret=f[i][j][0];
			if (j>1&&i)
				ret=(LL)i*(j-1)*f[i][j-2][0]%MOD;
			if (j>2)
				ret=(ret+(LL)(j-1)*(j-2)/2*f[i+2][j-3][0])%MOD;
			if (i>1)
				ret=(ret+(LL)i*(i-1)/2*f[i-2][j-1][0])%MOD;
		}
	for (int k=1;k<=n;k++)
		for (int i=0;i<=n;i++)
			for (int j=0;j<=n;j++)
			{
				if (i) f[i][j][k]=(LL)i*f[i-1][j][k-1]%MOD;
				if (j) f[i][j][k]=(f[i][j][k]+(LL)j*f[i+1][j-1][k-1])%MOD;
			}
	g[d[1]+1][2]=1;
	for (int i=2;i<=n;i++)
		for (int j=2;j<i;j++)
		{
			int &ret=g[i][j+1];
			for (int k=2;k<=j;k++)
				ret=(ret+(LL)g[j][k]*f[sum1[j]-sum1[k-1]][sum2[j]-sum2[k-1]][i-j])%MOD;
		}
	int ans=0;
	for (int i=1;i<n;i++)
		ans=(ans+(LL)g[n][i+1]*f[sum1[n]-sum1[i]][sum2[n]-sum2[i]][0])%MOD;
	printf("%d",ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=405,MOD=1000000007;

int f[MAXN][MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	f[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		f[i][0]=1;
		for (int j=1;j<=n;j++)
		{
			int ret=0;
			for (int k=0;k<j;k++)
				ret=(ret+(LL)f[i-1][k]*f[i-1][j-1-k])%MOD;
			f[i][j]=ret;
			ret=0;
			for (int k=0;k<=j+1;k++)
				ret=(ret+(LL)f[i-1][k]*f[i-1][j+1-k])%MOD;
			f[i][j]=(f[i][j]+j*(j+1LL)*ret)%MOD;
			ret=0;
			for (int k=0;k<=j;k++)
				ret=(ret+(LL)f[i-1][k]*f[i-1][j-k])%MOD;
			f[i][j]=(f[i][j]+(2*j+1LL)*ret)%MOD;
		}
	}
	printf("%d",f[n][1]);
	return 0;
}
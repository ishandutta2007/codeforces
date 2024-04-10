#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back

const int MAXN=1000005,MOD=1000000007;

vector <int> fac[MAXN];
int dp[MAXN][20];
bool vis[MAXN];

void preprocess(int n)
{
	for (int i=2;i<=n;i++)
		if (!vis[i])
			for (int j=i;j<=n;j+=i)
			{
				vis[j]=true;
				int cnt=0,t=j;
				while (t%i==0)
				{
					t/=i;
					cnt++;
				}
				fac[j].pb(cnt);
			}
	dp[0][0]=1;
	for (int i=1;i<20;i++)
		dp[0][i]=2;
	for (int i=1;i<=1000000;i++)
	{
		int now=0;
		for (int j=0;j<20;j++)
		{
			(now+=dp[i-1][j])%=MOD;
			dp[i][j]=now;
		}
	}
}

void solve()
{
	int r,n;
	scanf("%d%d",&r,&n);
	int ret=1;
	for (int i=0;i<fac[n].size();i++)
		ret=(LL)ret*dp[r][fac[n][i]]%MOD;
	printf("%d\n",ret);
}

int main()
{
	preprocess(1000000);
	int q;
	scanf("%d",&q);
	while (q--) solve();
	return 0;
}
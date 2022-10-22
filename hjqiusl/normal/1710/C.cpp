// Lynkcat.
// Problem: C. XOR Triangle
// Contest: Codeforces - Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/C
// Memory Limit: 512 MB
// Time Limit: 4000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int vis[N][2][2][2][2][2][2],dp[N][2][2][2][2][2][2];
string st;
int calc(int dep,int la,int lb,int lc,int x,int y,int z)
{
	// cout<<dep<<","<<la<<" "<<lb<<" "<<lc<<" "<<x<<" "<<y<<" "<<z<<endl;
	if (dep==st.size())
	{
		if (x&&y&&z) return 1;
		return 0;
	}
	if (vis[dep][la][lb][lc][x][y][z]) return dp[dep][la][lb][lc][x][y][z];
	vis[dep][la][lb][lc][x][y][z]=1;
	int &res=dp[dep][la][lb][lc][x][y][z];
	for (int i=0;i<=1;i++)
		for (int j=0;j<=1;j++)
			for (int k=0;k<=1;k++)
			{
				int u=st[dep]-'0';
				if (la&&i>u||lb&&j>u||lc&&k>u) continue;
				int o=(i^j),oo=(j^k),ooo=(i^k);
				if (o&&oo)
					res=(res+calc(dep+1,la&&(i==u),lb&&(j==u),lc&&(k==u),1,y,z))%mod;
				else
				if (oo&&ooo)
					res=(res+calc(dep+1,la&&(i==u),lb&&(j==u),lc&&(k==u),x,1,z))%mod;
				else if (ooo&&o)
					res=(res+calc(dep+1,la&&(i==u),lb&&(j==u),lc&&(k==u),x,y,1))%mod;
				else
					res=(res+calc(dep+1,la&&(i==u),lb&&(j==u),lc&&(k==u),x,y,z))%mod;
			}
	return res;
}
void BellaKira()
{
	cin>>st;
	cout<<calc(0,1,1,1,0,0,0)<<endl;
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
// Lynkcat.
// Problem: C. Even Number Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms

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
// #define N 
using namespace std;
int dp[105][105][2];
int n;
void BellaKira()
{
	int x=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int y;
		cin>>y;
		x+=(y&1);
	}
	if (dp[n-x][x][0]) cout<<"Alice"<<'\n';
	else cout<<"Bob\n";
}
signed main()
{
	dp[0][0][0]=1;
	for (int i=0;i<=100;i++)
		for (int j=0;j<=100;j++)
			for (int k=0;k<2;k++)
			{
				if (i>0&&dp[i-1][j][!(k^(j%2))]==0)
				{
					dp[i][j][k]=1;
				}
				if (j>0&&dp[i][j-1][!(k^(j%2))]==0)
				{
					dp[i][j][k]=1;
				}
			}
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
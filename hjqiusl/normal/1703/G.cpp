// Lynkcat.
// Problem: G. Good Key, Bad Key
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/G
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
#define N  200005
using namespace std;
int n,k,a[N],dp[N][65];
void BellaKira()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=60;j++) dp[i][j]=-inf;
	dp[0][0]=0;
	for (int i=1;i<=n;i++)
	{
		int x=a[i];
		for (int j=0;j<=60;j++)
		{
			dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+x/2);
			if (j==60)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j]+x/2);
			}
			// if (dp[i-1][j]>=k)
				dp[i][j]=max(dp[i][j],dp[i-1][j]+x-k);
			// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			x/=2;
		}
	}
	int ans=0;
	for (int j=0;j<=60;j++)
		ans=max(ans,dp[n][j]);
	cout<<ans<<endl;
			
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
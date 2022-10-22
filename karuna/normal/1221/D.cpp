#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll n, m, k, ans, mod=1e9+7;
pii p[303030];
ll dp[303030][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, temp=0;
	ll t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>p[i].first>>p[i].second;
		for(i=0;i<n;i++) for(j=0;j<3;j++) dp[i][j]=9e18;
		for(j=0;j<3;j++)
			dp[0][j]=j*p[0].second;
		for(i=0;i<n;i++)
		{
			for(j=0;j<3;j++)
			{
				for(k=0;k<3;k++)
				{
					if(p[i].first+j==p[i+1].first+k) continue;
					dp[i+1][k]=min(dp[i+1][k], dp[i][j]+k*p[i+1].second);
				}
			}
		}
		cout<<min(dp[n-1][0], dp[n-1][1])<<'\n';
	}
}
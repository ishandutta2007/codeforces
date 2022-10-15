#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
ll x[110][110];
ll dp[110][110];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>x[i][j];
				x[i][j]-=(i+j-1);
			}
		ll ans=1ll*inf*inf;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				for(int ii=1;ii<=n;ii++)
					for(int jj=1;jj<=m;jj++)
						dp[ii][jj]=1ll*inf*inf;
				ll mn=x[i][j];
				if(mn>x[1][1])
					continue;
				dp[1][1]=x[1][1]-mn;
				for(int ii=1;ii<=n;ii++)
					for(int jj=1;jj<=m;jj++)
					{
						if(ii!=n&&x[ii+1][jj]>=mn)
							dp[ii+1][jj]=min(dp[ii+1][jj],dp[ii][jj]+x[ii+1][jj]-mn);
						if(jj!=m&&x[ii][jj+1]>=mn)
							dp[ii][jj+1]=min(dp[ii][jj+1],dp[ii][jj]+x[ii][jj+1]-mn);
					}
				ans=min(ans,dp[n][m]);
			}
		cout<<ans<<endl;
	}
	return 0;
}
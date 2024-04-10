//Author: Kevin5307
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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
ll dp[200200][33];
ll mn[200200];
ll s[200200];
vector<int> G[200200];
void dfs1(int u)
{
	for(auto v:G[u])
	{
		mn[v]=mn[u]/sz(G[u]);
		dfs1(v);
	}
}
void dfs2(int u)
{
	for(auto v:G[u])
		dfs2(v);
	if(sz(G[u]))
	{
		for(int i=0;i<33;i++)
		{
			ll tot=mn[u]+i;
			int cnt=tot%sz(G[u]);
			ll x=tot/sz(G[u]);
			x-=mn[G[u][0]];
			vector<ll> vec;
//			cout<<u<<" "<<i<<" "<<x<<endl;
			for(auto v:G[u])
			{
				dp[u][i]+=dp[v][x];
				vec.pb(dp[v][x+1]-dp[v][x]);
			}
			rsrt(vec);
			for(int ii=0;ii<cnt;ii++)
				dp[u][i]+=vec[ii];
		}
	}
//	for(int i=0;i<5;i++)
//		printf("dp[%d][%d]=%lld\n",u,i,dp[u][i]);
//	cout<<u<<" "<<mn[u]<<" "<<s[u]<<endl;
	for(int i=0;i<33;i++)
		dp[u][i]+=(mn[u]+i)*s[u];
//	for(int i=0;i<5;i++)
//		printf("dp[%d][%d]=%lld\n",u,i,dp[u][i]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		ll k;
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<33;j++)
				dp[i][j]=0;
			G[i].clear();
		}
		for(int i=2;i<=n;i++)
		{
			int p;
			scanf("%d",&p);
			G[p].pb(i);
		}
		for(int i=1;i<=n;i++)
			scanf("%lld",s+i);
		mn[1]=k;
		dfs1(1);
		dfs2(1);
		printf("%lld\n",dp[1][0]);
	}
	return 0;
}
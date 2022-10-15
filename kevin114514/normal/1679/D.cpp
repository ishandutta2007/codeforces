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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int a[200200];
vector<int> G[200200];
int vis[200200];
ll dp[200200];
void dfs(int x,int tar)
{
	dp[x]=0;
	vis[x]=1;
	for(auto y:G[x]) if(a[y]<=tar)
	{
		if(vis[y]==1)
			dp[x]=max(dp[x],1ll*inf*inf);
		if(vis[y]==0)
			dfs(y,tar);
		dp[x]=max(dp[x],dp[y]+1);
	}
	vis[x]=2;
}
int main()
{
	int n,m;
	ll k;
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
	}
	int l=1,r=1e9+1;
	while(l<r)
	{
		int mid=(l+r)/2;
		memset(vis,0,sizeof(vis));
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++) if(a[i]<=mid) if(!vis[i]) dfs(i,mid);
		if(*max_element(dp+1,dp+n+1)>=k-1)
			r=mid;
		else	l=mid+1;
	}
	if(l>1e9)
		die("-1");
	cout<<l<<endl;
	return 0;
}
#include<bits/stdc++.h>
//AtCoder Library
//#define ATCODER
#ifdef ATCODER
#include<atcoder/convolution.hpp>
#include<atcoder/dsu.hpp>
#include<atcoder/fenwicktree.hpp>
#include<atcoder/internal_bit.hpp>
#include<atcoder/internal_math.hpp>
#include<atcoder/internal_queue.hpp>
#include<atcoder/internal_scc.hpp>
#include<atcoder/internal_type_traits.hpp>
#include<atcoder/lazysegtree.hpp>
#include<atcoder/math.hpp>
#include<atcoder/maxflow.hpp>
#include<atcoder/mincostflow.hpp>
#include<atcoder/modint.hpp>
#include<atcoder/scc.hpp>
#include<atcoder/segtree.hpp>
#include<atcoder/string.hpp>
#include<atcoder/twosat.hpp>
using namespace atcoder;
#endif
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
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[110];
ll dp[110][110];
const ll mod=1e9+7;
void upd(ll &a,ll b)
{
	a+=b;
	a%=mod;
}
vector<int> dfs(int u,int fa)
{
	vector<int> res(100);
	for(int i=0;i<sz(G[u]);i++)
	{
		int v=G[u][i];
		if(v==fa)
			continue;
		vector<int> tmp=dfs(v,u);
		for(int j=0;j<99;j++)
			res[j+1]+=tmp[j];
	}
	res[0]=1;
	return res;
}
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		G[i].resize(0);
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	if(k==2)
	{
		cout<<n*(n-1)/2<<endl;
		return ;
	}
	ll res=0;
	for(int root=0;root<n;root++)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<100;i++)
			dp[i][0]=1;
		for(int i=0;i<sz(G[root]);i++)
		{
			int v=G[root][i];
			vector<int> x=dfs(v,root);
			for(int l=0;l<100;l++)
				for(int j=n-1;j>=0;j--)
					upd(dp[l][j+1],dp[l][j]*x[l]);
		}
		ll ans=0;
		for(int i=0;i<100;i++)
			upd(ans,dp[i][k]);
		upd(res,ans);
	}
	cout<<res<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
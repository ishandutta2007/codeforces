#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,m,cntr,a[N],sz[N],vis[N],col[N],mark[N],cnt0[N],cnt1[N],cnt2[N],mark1[N],mark2[N];
ll ans;
vector<int> alw,mv,vec[N];
vector<pair<int,int>> g[N];

void dfs1(int u,int p){
	sz[u]=1;
	for(auto [v,w] : g[u]){
		if(v==p || vis[v]) continue ;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
	if(2*sz[u]>=m && cntr==-1) cntr=u;
}
void dfs2(int u,int p){
	sz[u]=1;
	for(auto [v,w] : g[u]){
		if(v==p || vis[v]) continue ;
		col[v]=w;
		mark[w]++;
		dfs2(v,u);
		if(mark2[w]==0) mark2[w]=1,alw.pb(w);
		mark[w]--;
		sz[u]+=sz[v];
		if(mark[w]==0) cnt0[w]-=sz[v];
	}
	
}
void dfs3(int u,int p){
	if(mark1[col[u]]==0){
		mark1[col[u]]=1;
		mv.pb(col[u]);
	}
	mark[col[u]]++;
	if(mark[col[u]]==1) ans+=1ll*sz[u]*cnt0[col[u]],cnt1[col[u]]+=sz[u];
	if(mark[col[u]]==2) ans-=1ll*sz[u]*cnt0[col[u]],cnt1[col[u]]-=sz[u],cnt2[col[u]]+=sz[u];
	for(auto [v,w] : g[u]){
		if(v==p || vis[v]) continue ;
		dfs3(v,u);
	}
	mark[col[u]]--;
}
void solve(int X,int _m){
	alw.clear();
	m=_m,cntr=-1;
	dfs1(X,X);
	X=cntr;
	//eror(X);
	dfs2(X,X);
	//sort(all(alw));
	//alw.resize(unique(all(alw))-alw.begin());
	for(auto x : alw) cnt0[x]+=m,mark2[x]=0;
	for(auto [v,w] : g[X]){
		if(vis[v]) continue ;
		mv.clear();
		dfs3(v,X);
		//sort(all(mv));
		//mv.resize(unique(all(mv))-mv.begin());
		for(auto x : mv){
			mark1[x]=0;
			ans-=1ll*cnt1[x]*(sz[v]-cnt1[x]-cnt2[x]);
			cnt1[x]=0;
			cnt2[x]=0;
		}
		//cout<<v<<" : "<<ans<<endl;
	}
	//cout<<X<<" -> "<<ans<<endl;
	for(auto x : alw) cnt0[x]=0;
	vis[X]=1;
	for(auto [v,w] : g[X]){
		if(vis[v]) continue ;
		solve(v,sz[v]);
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	f(i,1,n){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	solve(1,n);
	cout<<ans;
}
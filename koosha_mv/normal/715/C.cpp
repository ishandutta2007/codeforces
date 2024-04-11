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
#define int ll

const int N=4e5+99;

int n,t,mod,cent,a[N],dp[N],pd[N],sz[N],vis[N],Pow[N];
ll ans;
vector<int> Dp,Pd;
vector<pair<int,int>> g[N];

void dfs1(int u,int p,int n){
	sz[u]=1;
	for(auto v : g[u]){
		if(v.F==p || vis[v.F]==1) continue ;
		dfs1(v.F,u,n);
		sz[u]+=sz[v.F];
	}
	if(2*sz[u]>=n && cent==-1) cent=u;
}
void dfs2(int u,int p,int h){
	sz[u]=1;
	for(auto v : g[u]){
		if(v.F==p || vis[v.F]==1) continue ;
		dp[v.F]=(dp[u]+1ll*Pow[n+h+1]*v.S)%mod;
		pd[v.F]=(pd[u]+1ll*Pow[n-h]*v.S)%mod;
		ans+=(dp[v.F]==0)+(pd[v.F]==0);
		dfs2(v.F,u,h+1);
		sz[u]+=sz[v.F];
	}
}
void dfs3(int u,int p){
	Dp.pb(dp[u]);
	Pd.pb(pd[u]);
	for(auto v : g[u]){
		if(v.F==p || vis[v.F]==1) continue ;
		dfs3(v.F,u);
	}
}
void solve(int rt,int n){
	cent=-1;
	dfs1(rt,rt,n);	
	rt=cent;
	vis[cent]=1;
	dp[cent]=pd[cent]=0;
	dfs2(cent,cent,0);
	map<int,int> mark1,mark2;
	for(auto v : g[cent]){
		if(vis[v.F]) continue ;
		Dp.clear();
		Pd.clear();
		dfs3(v.F,cent);
		for(auto x : Dp){
			ans+=mark2[(mod-x)%mod];
		}
		for(auto x : Pd){
			ans+=mark1[(mod-x)%mod];
		}
		for(auto x : Dp){
			mark1[x]++;
		}
		for(auto x : Pd){
			mark2[x]++;
		}
	}
	for(auto v : g[cent]){
		if(vis[v.F]) continue ;
		solve(v.F,sz[v.F]);
	}
}

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>mod;
	Pow[0]=1;
	f(i,1,N) Pow[i]=10ll*Pow[i-1]%mod;
	f(i,1,n){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	solve(0,n);
	cout<<ans;
}
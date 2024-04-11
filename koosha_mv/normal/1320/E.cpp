#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
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
#define pii pair<int,int>
 
const int N=2e5+99,lg=20;
 
int n,t,k,m,cnt,a[N],vrs[N],imp[N],spd[N],mark[N],h[N],st[N],ft[N],par[lg][N];
vector<int> g[N];
pii dp[N],ans[N];
 
pii Min(pair<int,int> u,pair<int,int> v){
	if(mp((u.S+spd[u.F]-1)/spd[u.F],u.F)<=mp((v.S+spd[v.F]-1)/spd[v.F],v.F)) return u;
	return v;
}
int lca(int u,int v){
	if(h[u]>h[v]) swap(u,v);
	f_(l,lg-1,0) if(h[par[l][v]]>=h[u]) v=par[l][v];
	if(u==v) return u;
	f_(l,lg-1,0) if(par[l][u]!=par[l][v]) u=par[l][u],v=par[l][v];
	return par[0][u];
}
void dfs1(int u,int p){
	par[0][u]=p;
	f(l,1,lg) par[l][u]=par[l-1][par[l-1][u]];
	a[cnt]=u;
	st[u]=cnt++;
	for(auto v : g[u]){
		if(v==p) continue ;
		h[v]=h[u]+1;
		dfs1(v,u);
	}
	ft[u]=cnt;
}
void dfs2(int u){
	for(auto v : g[u]){
		int w=h[v]-h[u];
		dfs2(v);
		dp[u]=Min(dp[u],{dp[v].F,dp[v].S+w});
	}
	ans[u]=dp[u];
}
void dfs3(int u){
	for(auto v : g[u]){
		int w=h[v]-h[u];
		ans[v]=Min(ans[v],{ans[u].F,ans[u].S+w});
		dfs3(v);
	}
	g[u].clear();
}
void Main(){
	vector<int> vec;
	set<int> s;
	cin>>k>>m;
	f(i,1,k+1){
		cin>>vrs[i]>>spd[i];
		vec.pb(vrs[i]);
		s.insert(st[vrs[i]]);
	}
	f(i,1,m+1){
		cin>>imp[i];
		vec.pb(imp[i]);
		s.insert(st[imp[i]]);
	}
	sort(all(vec), [&](int u, int v){ return st[u]<st[v]; });
	f(i,0,vec.size()-1) s.insert(st[lca(vec[i],vec[i+1])]);
	vec.clear();
	int rt=a[*s.begin()],now=*s.rbegin();
	while(1){
		dp[a[now]]={0,N};
		while(*s.rbegin()!=now && *s.upper_bound(now)<ft[a[now]]){
			g[a[now]].pb(a[*s.upper_bound(now)]);
			s.erase(*s.upper_bound(now));
		}
		if(rt==a[now]) break;
		now=*prev(s.lower_bound(now));
	}
	f(i,1,k+1) dp[vrs[i]]={i,0};
	dfs2(rt);
	dfs3(rt);
	f(i,1,m+1) cout<<ans[imp[i]].F<<" ";
	cout<<endl;
}
 
int main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	spd[0]=1;
	cin>>n;
	f(i,1,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs1(1,1);
	f(i,1,n+1) g[i].clear();
	cin>>t;
	while(t--) Main();
}
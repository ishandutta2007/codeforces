#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
#define int ll

const int N=3e5+99;
const ll inf=1e18;

struct edge{
	int u;
	int v;
	int w;
};

int n,m,s,u,v,w,sub[N],par[N],ans[N];
ll dist[N];
edge e[N];
vector<pair<int,int> > g[N];
set<pair<ll,int> > vr;
vector<int> topo,adj[N];

void mv(int x,int y){
	vr.erase(mp(dist[x],x)),dist[x]=y,vr.insert(mp(dist[x],x));
}
void dijkstra(int x){
	fill(dist,dist+N,inf); dist[x]=0;
	f(i,1,n+1) vr.insert(mp(dist[i],i));
	while(vr.size()){
		u=(*vr.begin()).S;
		if(dist[u]==inf) return ; topo.pb(u),vr.erase(*vr.begin());
		f(i,0,g[u].size()) if(dist[g[u][i].F]>dist[u]+g[u][i].S) mv(g[u][i].F,dist[u]+g[u][i].S);
	}
}
void solve(int x){
	f(i,0,adj[x].size()) if(adj[x][i]==s || (i>0 && par[adj[x][i]]!=par[adj[x][i-1]])){ par[x]=x; return ; }
	par[x]=par[adj[x][0]];
}

main(){
	cin>>n>>m>>s;
	f(i,0,m){
		Gett(u,v);
		gett(w);
		g[u].pb(mp(v,w));
		g[v].pb(mp(u,w));
		e[i]={u,v,w};
	}
	dijkstra(s);
	f(i,0,m){
		if(dist[e[i].u]-dist[e[i].v]==e[i].w) adj[e[i].u].pb(e[i].v);
		if(dist[e[i].v]-dist[e[i].u]==e[i].w) adj[e[i].v].pb(e[i].u);
	}
	par[s]=s;
	f(i,1,1ll*topo.size()) solve(topo[i]);
	f(i,1,n+1) ans[par[i]]++; ans[s]=0;
	f(i,2,n+1) maxm(ans[i],ans[i-1]);
	cout<<ans[n];
}
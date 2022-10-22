#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

struct edge{
	int x;
	int y;
	int w;	
};

int n,k,m,u,v,l,c,p,lc,sz,cnt,s[N],a[N],h[N],par[N],type[N];
vector<pair<int,int> > g[N],rem[N],add[N];
set<pair<int,int> > el[N];
vector<int> dist[N];
vector<edge> e;
ll ans;

void merges(int u,int v){
	while(el[u].size()){
		el[v].insert(*el[u].begin());
		el[u].erase(*el[u].begin());
	}
}
int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void merge(int u,int v,int s){
	g[u].pb(mp(v,s)),g[v].pb(mp(u,s));
	u=Get_par(u),v=Get_par(v);
	if(u>v) swap(u,v);
	par[u]+=par[v],par[v]=u;
}
void dfs(int x,int par){
	int mx=0,an=x;
	f(i,0,g[x].size())
		if(g[x][i].F!=par){
			dfs(g[x][i].F,x);
			if(el[a[g[x][i].F]].size()>mx)
				mx=el[a[g[x][i].F]].size(),an=a[g[x][i].F];
		}
	a[x]=an;
	f(i,0,g[x].size())
		if(a[g[x][i].F]!=an)
			merges(a[g[x][i].F],a[x]);
	f(i,0,add[x].size())
		el[a[x]].insert(add[x][i]);
	f(i,0,rem[x].size())
		el[a[x]].erase(rem[x][i]);
	if(type[x]){
		if(el[a[x]].size())
			ans+=(*el[a[x]].begin()).F;
		else{
			cout<<-1;
			exit(0);
		}
	}
}
void dfs1(int x,int par,int fa){
	s[x]=++c,h[x]=fa;
	dist[fa].pb(x);
	f(i,0,g[x].size())
		if(g[x][i].F!=par)
			dfs1(g[x][i].F,x,fa+1),type[g[x][i].F]=g[x][i].S;
}
int check(int d,int u,int v){
	int l=0,r=dist[d].size(),mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(s[dist[d][mid]]<=s[v]) l=mid;
		else r=mid;
	}
	if(s[dist[d][l]]<=s[u]) return dist[d][l];
	return 0;
}
int lca(int u,int v){
	if(s[u]>s[v]) swap(u,v);
	int l=0,r=min(h[u],h[v])+1,mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(check(mid,u,v)) l=mid;
		else r=mid;
	}
	return check(l,u,v);
}

main(){
	cin>>n>>k>>m;
	fill(par,par+N,-1);
	f(i,0,k){
		Gett(u,v);
		merge(u,v,1);
	}
	f(i,0,m){
		Gett(u,v);
		gett(l);
		if(Get_par(u)!=Get_par(v)) merge(u,v,0);
		else{
			e.pb(edge()),sz=e.size()-1;
			e[sz].x=u,e[sz].y=v,e[sz].w=l;
		}
	}
	dfs1(1,0,0);
	f(i,0,e.size()){
		u=e[i].x,v=e[i].y;
		lc=lca(u,v);
		if(u!=lc) rem[lc].pb(mp(e[i].w,++p)),add[u].pb(mp(e[i].w,p));
		if(v!=lc) rem[lc].pb(mp(e[i].w,++p)),add[v].pb(mp(e[i].w,p));
	}
	dfs(1,0);
	cout<<ans;
}
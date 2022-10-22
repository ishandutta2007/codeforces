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
	int u;
	int v;
	int an;
};

int n,m,q,x,y,k,l,sz,ans,b[N],par[N],mark[N],vis[N],a[N][2];
map<pair<int,int>,int> mv;
pair<int,int> p[N];
vector<edge> e[N];
vector<int> g[N];

void clear(int x){
	mv.clear();
	f(i,0,x)
		g[a[b[i]][0]].clear(),g[a[b[i]][1]].clear(),vis[a[b[i]][0]]=vis[a[b[i]][1]]=0;
}
int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void merge(int u,int v){
	if(u==v) return ;
	if(par[u]>par[v]) swap(u,v);
	par[u]+=par[v],par[v]=u;
}
void dfs(int x,int par){
	vis[x]=1;
	f(i,0,g[x].size())
		if(vis[g[x][i]] && g[x][i]!=par)
			ans=0;
	f(i,0,g[x].size())
		if(!vis[g[x][i]])
			dfs(g[x][i],x);
}

int main(){
	fill(par,par+N,-1);
	cin>>n>>m;
	f(i,0,m){
		Gett(a[i][0],a[i][1]);
		get(l);
		e[l].pb(edge());sz=e[l].size()-1;
		e[l][sz].u=a[i][0],e[l][sz].v=a[i][1],e[l][sz].an=i;
	}

	f(i,1,N){
		f(j,0,e[i].size()){
			p[e[i][j].an]=mp(Get_par(e[i][j].u),Get_par(e[i][j].v));
			if(Get_par(e[i][j].u)!=Get_par(e[i][j].v)) mark[e[i][j].an]=1;
		}
		f(j,0,e[i].size()){
			merge(Get_par(e[i][j].u),Get_par(e[i][j].v));
			if(p[e[i][j].an].F<p[e[i][j].an].S) swap(p[e[i][j].an].F,p[e[i][j].an].S);
		}
	}
	
	cin>>q;
	f(io,0,q){
		ans=1;
		gett(k);
		f(i,0,k){
			gett(x);--x,b[i]=x;
			if(mv[p[x]]) ans=0;
			else mv[p[x]]=1;
			if(!mark[x]) ans=0;
			g[a[x][0]].pb(a[x][1]),g[a[x][1]].pb(a[x][0]);
		}
		f(i,0,k)
			if(!vis[a[b[i]][0]])
				dfs(a[b[i]][0],0);
		clear(k);
		cout<<(ans ? "YES":"NO")<<'\n';
	}
}
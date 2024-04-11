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
 
const int N=2e5+9;

int n,u,v,w,t,p,sub[N],par[N],mark[N];
vector<pair<int,int> > g[N];
vector<pair<int,pair<int,int> > > edge[N];
pair<pair<int,int>,pair<int,int> > ed[N];
ll mx,ans[N];
set<int> s;
 
int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void merge(int u,int v){
	u=Get_par(u),v=Get_par(v);
	if(par[v]<par[u]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
void dfs1(int x){
	sub[x]=par[x]*-1,mark[x]=1;
	f(i,0,g[x].size())
		if(!mark[g[x][i].F])
			dfs1(g[x][i].F),sub[x]+=sub[g[x][i].F];
}
void dfs2(int x,int rt,int e){
	mark[x]=2;
	ans[e]=1ll*sub[x]*(sub[rt]-sub[x]);
	f(i,0,g[x].size())
		if(mark[g[x][i].F]<2)
			dfs2(g[x][i].F,rt,g[x][i].S);
}
 
int main(){
	fill(par,par+N,-1);
	cin>>n;
	f(i,1,n){
		Gett(ed[i].S.F,ed[i].S.S);
		gett(ed[i].F.F);
		ed[i].F.S=i;
	}
	sort(ed+1,ed+n);
	f(i,1,n){
		if(i!=1 && ed[i].F.F!=ed[i-1].F.F) p++;
		edge[p].pb(mp(ed[i].F.S,mp(ed[i].S.F,ed[i].S.S)));
	}
	f(k,0,N){
		f(i,0,edge[k].size()){
			edge[k][i].S.F=Get_par(edge[k][i].S.F),edge[k][i].S.S=Get_par(edge[k][i].S.S);
			g[edge[k][i].S.F].clear(),g[edge[k][i].S.S].clear();
		}
		f(i,0,edge[k].size())
			g[edge[k][i].S.F].pb(mp(edge[k][i].S.S,edge[k][i].F)),g[edge[k][i].S.S].pb(mp(edge[k][i].S.F,edge[k][i].F)),mark[edge[k][i].S.F]=mark[edge[k][i].S.S]=0;
		f(i,0,edge[k].size())
			if(!mark[edge[k][i].S.F])
				dfs1(edge[k][i].S.F);
		f(i,0,edge[k].size()){
			merge(edge[k][i].S.F,edge[k][i].S.S);
			if(mark[edge[k][i].S.F]<2)
				dfs2(edge[k][i].S.F,edge[k][i].S.F,0);
		}
	}
	f(i,1,n) maxm(mx,ans[i]);
	f(i,1,n) t+=(ans[i]==mx);
	cout<<mx*2<<" "<<t<<endl;
	f(i,1,n)
		if(ans[i]==mx)
			cout<<i<<" ";
}
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

const int N=1005;

int n,m,q,u,v,w,l,r,ans,par[N],col[N],mark[N];
vector<pair<int,pair<int,int> > > yal,edge[N*N];
vector<int> cmp[N];

void add(int x){
	f(i,0,edge[x].size()) yal.pb(edge[x][i]);
}
int Get_par(int u){
	if(par[u]<0) return u;
	return par[u]=Get_par(par[u]);
}
void query(int l, int r){
	r++;
	for (l += m, r += m; l < r; l >>= 1, r >>= 1) {
   	if(l&1) add(l++);
   	if(r&1) add(--r);
	}
}
void reset(int x){
	cmp[x].clear();
	cmp[x].pb(x);
}
void merge(int u,int v,int s){
	u=Get_par(u),v=Get_par(v);
	if(par[u]>par[v]) swap(u,v);
	f(i,0,cmp[v].size())
		cmp[u].pb(cmp[v][i]),col[cmp[v][i]]^=s;
	par[u]+=par[v],par[v]=u;
}
void solve(int x){
	vector<pair<int,pair<int,int> > > vec;
	f(i,0,edge[x].size()) par[edge[x][i].S.F]=par[edge[x][i].S.S]=-1,reset(edge[x][i].S.F),reset(edge[x][i].S.S);
	f(i,0,edge[x].size()){
		u=edge[x][i].S.F,v=edge[x][i].S.S;
		if(Get_par(u)==Get_par(v)){
			if(col[u]==col[v]){
				vec.pb(edge[x][i]);
				break;
			}
		}
		else
			merge(u,v,col[u]==col[v]),vec.pb(edge[x][i]);
	}
	edge[x].clear();
	edge[x]=vec;
}
void merge_t(int u,int v,int an){
	int p1=0,p2=0;
	while(p1<edge[u].size() || p2<edge[v].size()){
		if(p2==edge[v].size() || (p1<edge[u].size() && edge[u][p1].F>edge[v][p2].F)) edge[an].pb(edge[u][p1++]);
		else edge[an].pb(edge[v][p2++]);
	}
}
void build(){
	f_(i,m-1,1){
		merge_t(i*2,i*2+1,i);
		solve(i);
	}
}
void clear(){
	ans=-1,yal.clear();
	fill(col,col+N,0);
	fill(par,par+N,-1);
	f(i,1,n+1) reset(i);
}

int main(){
	cin>>n>>m>>q;
	f(i,0,m){
		Gett(u,v);
		gett(w);
		edge[i+m].pb(mp(w,mp(u,v)));
	}
	build();
	f(io,0,q){
		clear();
		Gett(l,r);--l,--r;
		query(l,r);
		sort(yal.begin(),yal.end());
		reverse(yal.begin(),yal.end());
		f(i,0,yal.size()){
			u=yal[i].S.F,v=yal[i].S.S;
			if(Get_par(u)==Get_par(v)){
				if(col[u]==col[v]){
					ans=yal[i].F;
					break;
				}
			}
			else
				merge(u,v,col[u]==col[v]);
		}
		cout<<ans<<'\n';
	}
}
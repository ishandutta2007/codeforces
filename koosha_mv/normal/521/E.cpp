#include <bits/stdc++.h>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=5e5+99;

int n,m,u,v,t,rt,h[N],par[N];
bool mark[N];
vector<int> vec,path[3],g[N];
vector<pair<int,int> > backedge[N];

void merge(int u,int v){
	for(int i=0;i<sz(backedge[v]) && sz(backedge[u])<2;i++)
		if(backedge[v][i].S!=u)
			backedge[u].pb(backedge[v][i]);
}
void dfs(int x){
	mark[x]=1;
	f(i,0,g[x].size())
		if(mark[g[x][i]] && g[x][i]!=par[x] && sz(backedge[x])<2)
			backedge[x].pb(mp(x,g[x][i]));
	f(i,0,g[x].size()){
		if(!mark[g[x][i]]){
			h[g[x][i]]=h[x]+1;
			par[g[x][i]]=x;
			dfs(g[x][i]);
			merge(x,g[x][i]);
		}
	}
	if(sz(backedge[x])==2 && !u) u=x; 
		
}
void print_ans(){
	fill(mark,mark+N,0);
	if(h[backedge[u][0].S]<h[backedge[u][1].S]) swap(backedge[u][0],backedge[u][1]);
	int x=backedge[u][0].S;
	for(v=u;v!=x;v=par[v])
		path[2].pb(v); path[2].pb(x);
	f(i,0,2){
		vec.clear();
		for(v=backedge[u][i].F;v!=u;v=par[v])
			path[i].pb(v); path[i].pb(u);
		for(v=x;v!=backedge[u][i].S;v=par[v])
			vec.pb(v); vec.pb(backedge[u][i].S);
		reverse(vec.begin(),vec.end());
		reverse(path[i].begin(),path[i].end());
		f(j,0,vec.size()) path[i].pb(vec[j]);
	}
	cout<<"YES"<<'\n';
	f(i,0,3){
		cout<<sz(path[i])<<" ";
		f(j,0,path[i].size())
			cout<<path[i][j]<<" ";
		cout<<'\n';
	}
	exit(0);
}

int main(){
	cin>>n>>m;
	f(i,0,m){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	u=0;
	f(i,1,n+1)
		if(!mark[i]){
			rt=i;
			dfs(i);
			if(u)
				print_ans();
		}
	cout<<"NO"<<'\n';
}
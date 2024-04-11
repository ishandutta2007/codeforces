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

const int N=1e5+9,sq=325;

int n,m,q,u,v,c,num,vis[N];
vector<pair<int,int> > col[N];
vector<int> ver,g[N];
map<int,int> t[N];
bool mark[sq][N];

void algo1(){
	f(i,0,ver.size())
		f(j,0,i)
			t[ver[i]][ver[j]]++,t[ver[j]][ver[i]]++;
}
void algo2(){
	f(i,0,ver.size())
		mark[num][ver[i]]=1;
	num++;
}
void dfs(int u){
	vis[u]=1;
	ver.pb(u);
	f(i,0,g[u].size())
		if(!vis[g[u][i]])
			dfs(g[u][i]);
}
void solve(int an){
	f(i,0,col[an].size()){
		u=col[an][i].F,v=col[an][i].S;
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,0,col[an].size())
		if(!vis[col[an][i].F]){
			ver.clear();
			dfs(col[an][i].F);
			if(ver.size()<=sq)
				algo1();
			else
				algo2();
		}
	f(i,0,col[an].size()){
		u=col[an][i].F,v=col[an][i].S;
		g[u].clear(),g[v].clear();
		vis[u]=vis[v]=0;
	}
}

int main(){
	cin>>n>>m;
	f(i,0,m){
		cin>>u>>v>>c;
		col[c].pb(mp(u,v));
	}
	f(i,1,m+1)
		solve(i);
	cin>>q;
	f(i,0,q){
		cin>>u>>v;
		int res=0;
		res+=t[u][v];
		f(i,0,sq)
			if(mark[i][u] && mark[i][v])
				res++;
		cout<<res<<'\n';
	}
}
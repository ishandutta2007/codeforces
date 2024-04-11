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

const int N=1e6+9,inf=1e9;

int n,m,x,y,s,t,dist[N],deg[N];
vector<int> g[N],io;

void bfs(vector<int> v){
	if(!v.size()) return ;
	vector<int> q;
	f(i,0,v.size()){
		int u=v[i];
		f(j,0,g[u].size()){
			if(--deg[g[u][j]]==0 && dist[g[u][j]]>dist[u])
				v.pb(g[u][j]),dist[g[u][j]]=dist[u];
		}
	}
	f(i,0,v.size()){
		int u=v[i];
		f(j,0,g[u].size()){
			if(dist[u]+1<dist[g[u][j]])
				dist[g[u][j]]=dist[u]+1,q.pb(g[u][j]);
		}
	}
	bfs(q);
}

int main(){
	fill(dist,dist+N,inf);
	Gett(n,m);
	f(i,0,m){
		Gett(x,y);
		g[y].pb(x);
		deg[x]++;
	}
	Gett(s,t);
	io.pb(t);
	dist[t]=0;
	bfs(io);
	cout<<(dist[s]==inf ? -1 : dist[s]);
}
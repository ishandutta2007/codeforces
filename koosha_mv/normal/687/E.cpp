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
#define ops(x) cout<<x<<" !"<<endl
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
 
const int N=5005,p=998,inf=1e9;
 
int n,m,u,v,t,ans,w[N],dist[N];
vector<int> g[N];
bool deg[N],vis[N],mark[N];
 
void read(){
	cin>>n>>m;
	f(i,0,m){
		Gett(u,v);
		g[v].pb(u);
		deg[u]=1;
	}
}
void bfs(int source){
	fill(dist,dist+N,inf);
	queue<int> q;
	if(!deg[source]) return ;
	w[source]=inf;
	dist[source]=1;
	q.push(source);
	while(q.size()){
		u=q.front();
		q.pop();
		f(i,0,g[u].size()){
			if(dist[u]+1<dist[g[u][i]]){
				q.push(g[u][i]);
				dist[g[u][i]]=dist[u]+1;
			}
			if(g[u][i]==source)
				minm(w[source],dist[u]);
		}
	}
	w[source]=w[source]*p+1;
}
void find_costs(){
	f(i,1,n+1)
		bfs(i);
}
void dfs(int x,int rt){
	vis[x]=1;
	f(i,0,g[x].size())
		if(!vis[g[x][i]])
			dfs(g[x][i],rt);
	if(x!=rt && w[x]>=w[rt]) mark[x]=0;
}
void solve(){
	fill(mark,mark+N,1);
	f(i,1,n+1){
		fill(vis,vis+N,0);
		if(mark[i])
			dfs(i,i);
	}
	vector<pair<int,int> > v;
	f(i,1,n+1)
		if(mark[i])
			v.pb(mp(w[i],i));
	fill(vis,vis+N,0);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	f(i,0,v.size())
		if(!vis[v[i].S]){
			ans+=w[v[i].S];
			dfs(v[i].S,0);
		}
	cout<<ans+n;
}
 
int main(){
	read();
	find_costs();
	solve();
}
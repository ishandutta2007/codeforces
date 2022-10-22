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

const int N=1e5+99,inf=1e9;

int n,m,u,v,c,dist[N],dp[N],edge[N][3];
vector<int> dis,ver;
vector<pair<int,int> > g[N];
vector<pair<int,int> > ans;
map<int,int> mark[N];
void dfs(int x){
	if(x==n) return ;
	f(i,0,g[x].size()){
		if(dp[g[x][i].F]==dp[x]-g[x][i].S && dist[g[x][i].F]==dist[x]+1){
			if(g[x][i].S==1) ans.pb(mp(x,g[x][i].F));
			mark[x][g[x][i].F]=1,mark[g[x][i].F][x]=1;
			dfs(g[x][i].F);
			return ;
		}
	}
}
void bfs(){
	fill(dist,dist+N,inf);
	fill(dp,dp+N,inf);
	queue<int> q;
	q.push(1),ver.pb(1);
	dist[1]=0;
	while(q.size()){
		u=q.front();
		q.pop();
		f(i,0,g[u].size())
			if(dist[u]+1<dist[g[u][i].F])
				dist[g[u][i].F]=dist[u]+1,q.push(g[u][i].F),ver.pb(g[u][i].F);
	}
}
int main(){
	cin>>n>>m;
	f(i,0,m){
		cin>>u>>v>>c;
		edge[i][0]=u,edge[i][1]=v,edge[i][2]=c;
		g[u].pb(mp(v,1-c));
		g[v].pb(mp(u,1-c));
	}
	bfs();
	dp[n]=0;
	f_(i,ver.size()-1,0){
		u=ver[i];
		f(j,0,g[u].size())
			if(dist[g[u][j].F]==dist[u]-1)
				minm(dp[g[u][j].F],dp[u]+g[u][j].S);
	}
	dfs(1);
	f(i,0,m)
		if(!mark[edge[i][0]][edge[i][1]] && edge[i][2]==1)
			ans.pb(mp(edge[i][0],edge[i][1]));
	cout<<ans.size()<<endl;
	f(i,0,dp[1])
		cout<<ans[i].F<<" "<<ans[i].S<<" "<<1<<endl;
	f(i,dp[1],ans.size())
		cout<<ans[i].F<<" "<<ans[i].S<<" "<<0<<endl;
}
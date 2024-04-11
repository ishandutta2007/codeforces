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
 
const int N=1002,inf=2000;

int n,m,u,v,c,sum,ans[N],dist[N],mark[N];
vector<int> g[N];

int solve(int x){
	fill(dist,dist+N,inf);
	queue<int> q;
	q.push(x);
	dist[x]=0;
	int res=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		maxm(res,dist[u]);
		f(i,0,g[u].size()){
			if(dist[g[u][i]]==dist[u]) return -1;
			if(dist[u]+1<dist[g[u][i]])
				dist[g[u][i]]=dist[u]+1,q.push(g[u][i]);
		}
	}
	return res;
}
void dfs(int x,int col){
	mark[x]=col;
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i],col);
}
int main(){
	fill(ans,ans+N,-1);
	cin>>n>>m;
	f(i,0,m){
		Gett(u,v);
		g[u].pb(v);
		g[v].pb(u);
	}
	f(i,1,n+1)
		if(!mark[i])
			dfs(i,++c);
	f(i,1,n+1)
		maxm(ans[mark[i]],solve(i));
	f(i,1,c+1){
		if(ans[i]==-1) return cout<<-1,0;
		sum+=ans[i];
	}
	cout<<sum;
}
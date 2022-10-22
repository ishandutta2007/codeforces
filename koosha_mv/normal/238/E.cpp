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

const int N=102,inf=1000;

int n,m,k,a,b,u,v,flag=1,dist[N],Dist[N],mark[N],s[N][2];
vector<int> g[N],g1[N];
vector<pair<int,int> > c[N];

void bfs(int s){
	queue<int> q;
	fill(dist,dist+N,inf);
	if(!mark[s]) q.push(s),dist[s]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		f(i,0,g1[u].size())
			if(dist[u]+1<dist[g1[u][i]] && !mark[g1[u][i]])
				dist[g1[u][i]]=dist[u]+1,q.push(g1[u][i]);
	}
}
void bfs1(int s,int t,int an){
	queue<int> q;
	vector<int> v;
	fill(dist,dist+N,inf);
	fill(mark,mark+N,0);
	dist[s]=0;
	q.push(s),v.pb(t);
	while(q.size()){
		int u=q.front();
		q.pop();
		f(i,0,g[u].size())
			if(dist[u]+1<dist[g[u][i]])
				dist[g[u][i]]=dist[u]+1,q.push(g[u][i]);
	}
	if(dist[t]==-1) return ;
	f(j,0,v.size()){
		int u=v[j];
		f(i,0,g1[u].size())
			if(dist[g1[u][i]]==dist[u]-1 && mark[g1[u][i]]==0)
				v.pb(g1[u][i]),mark[g1[u][i]]=1;
	}
	f(i,0,v.size())
		if((i==0 || dist[v[i]]!=dist[v[i-1]]) && (i==v.size()-1 || dist[v[i]]!=dist[v[i+1]]))
			c[an].pb(mp(v[i],-1));
	fill(mark,mark+N,0);
	bfs(t);
	f(i,0,c[an].size())
		c[an][i].S=dist[c[an][i].F];

}
void solve(int fa){
	vector<int> v;
	f(i,0,k){
		bfs(s[i][1]);
		f(j,0,c[i].size())
			if(dist[c[i][j].F]>c[i][j].S && Dist[c[i][j].F]>fa)
				Dist[c[i][j].F]=fa,v.pb(c[i][j].F);
	}
	f(i,0,v.size())
		mark[v[i]]=1;
	if(!v.size()) flag=0;
}

int main(){
	cin>>n>>m>>a>>b;
	f(i,0,m){
		cin>>u>>v;
		g[u].pb(v);
		g1[v].pb(u);
	}
	cin>>k;
	f(i,0,k)
		cin>>s[i][0]>>s[i][1];
	f(i,0,k)
		bfs1(s[i][0],s[i][1],i);
	fill(Dist,Dist+N,inf);
	fill(mark,mark+N,0);
	mark[b]=1;
	Dist[b]=0;
	for(int i=1;flag;i++)
		solve(i);
	cout<<(Dist[a]<inf ? Dist[a]:-1);
}
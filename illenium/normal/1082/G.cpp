#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

struct node{ll from,to,cap,flow;};
vector <node> edges;
vector <int> mp[maxn];
int n,m,s,t,d[maxn],cur[maxn];
bool vis[maxn];
queue <int> que;

inline void add_edge(int u,int v,ll w)
{
	edges.push_back((node){u,v,w,0});
	edges.push_back((node){v,u,0,0});
	int pp=edges.size();
	mp[u].push_back(pp-2);
	mp[v].push_back(pp-1);
}

inline bool bfs()
{
	for(int i=0;i<=t;i++) d[i]=inf,vis[i]=0; d[s]=0; vis[s]=1; que.push(s);
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			node v=edges[mp[u][i]];
			if(v.cap-v.flow>0&&!vis[v.to])
			{
				d[v.to]=d[u]+1;
				vis[v.to]=1; que.push(v.to);
			}
		}
	}
	if(vis[t]) return true;
	return false;
}

inline ll dfs(int u,ll w)
{
	ll flow=0,r=0;
	if(u==t||w==0) return w;
	for(int i=0;i<mp[u].size();i++)
	{
		node &v=edges[mp[u][i]];
		if(d[v.to]==d[u]+1&&(r=dfs(v.to,min(v.cap-v.flow,w)))>0)
		{
			flow+=r;
			edges[mp[u][i]].flow+=r;
			edges[mp[u][i]^1].flow-=r;
			w-=r;
			if(w==0) break;
		}
	}
	return flow;
}

inline ll max_flow()
{
	ll ff=0;
	while(bfs())
	{
		memset(cur,0,sizeof(cur));
		ff+=dfs(s,inf);
	}
	return ff;
}

int a[maxn];

int main()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),add_edge(s,i,a[i]);
	ll ans=0; s=0; t=n+m+1;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		ans+=w;
		add_edge(u,n+i,inf);
		add_edge(v,n+i,inf);
		add_edge(n+i,t,w);
	}
	cout<<ans-max_flow()<<endl;
	return 0;
}
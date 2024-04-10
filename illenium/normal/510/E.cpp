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

struct node{int from,to,cap,flow;};
vector <node> edges;
vector <int> mp[maxn];
int n,m,s,t,d[maxn],cur[maxn];
bool vis[maxn];
queue <int> que;

inline void add_edge(int u,int v,int w)
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

inline int dfs(int u,int w)
{
	int flow=0,r=0;
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

inline int max_flow()
{
	int ff=0;
	while(bfs())
	{
		memset(cur,0,sizeof(cur));
		ff+=dfs(s,inf);
	}
	return ff;
}

int a[maxn],prime[maxn],cnt,cnt2;
bool pri[maxn],vis2[maxn];
vector <int> ans[maxn];

inline void dfs2(int u)
{
	vis2[u]=1; ans[cnt2].push_back(u);
	for(int i=0;i<mp[u].size();i++)
	{
		node v=edges[mp[u][i]];
		if(vis2[v.to]||v.flow==0) continue;
		else dfs2(v.to);
	}
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=2;i<=100005;i++)
	{
		if(pri[i]==0) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=100005;j++)
		{
			pri[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	s=0; t=n+1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2==0) add_edge(s,i,2);
		else add_edge(i,t,2);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]%2==0)
			for(int j=1;j<=n;j++)
				if(pri[a[i]+a[j]]==0) add_edge(i,j,1);
	}
	if(max_flow()!=n) puts("Impossible");
	else
	{
		vis2[0]=1; vis2[n+1]=1;
		for(int i=0;i<mp[s].size();i++)
		{
			node v=edges[mp[s][i]];
			if(v.flow==2&&vis2[v.to]==0)
			{
				cnt2++;
				dfs2(v.to);
			}
		}
		cout<<cnt2<<endl;
		for(int i=1;i<=cnt2;i++)
		{
			printf("%d ",ans[i].size());
			for(int j=0;j<ans[i].size();j++)
				printf("%d ",ans[i][j]);
			puts("");
		}
	}
	return 0;
}
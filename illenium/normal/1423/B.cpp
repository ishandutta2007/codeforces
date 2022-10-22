#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
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

struct node2{int u,v,w;}p[maxn];

inline bool cmp(node2 a,node2 b){return a.w<b.w;}

int main()
{
	n=read(); m=read(); s=2*n+1; t=2*n+2; int X=0;
	rep(i,1,m) p[i].u=read(),p[i].v=read(),p[i].w=read();
	sort(p+1,p+m+1,cmp);
	
	int l=1,r=m,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		
		rep(i,1,n) add_edge(s,i,1),add_edge(n+i,t,1);
		rep(i,1,mid) add_edge(p[i].u,n+p[i].v,1);
		if(max_flow()==n) ans=p[mid].w,r=mid-1;
		else l=mid+1;
		
		rep(i,0,t) mp[i].clear(); edges.clear();
	}
	cout<<ans<<endl;
	return 0;
}
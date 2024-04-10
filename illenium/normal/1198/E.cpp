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

struct node2{int a,b,c,d;}p[maxn];
int x[maxn],y[maxn],cnt1,cnt2,totx,toty;
int q[1005][1005];

struct node{int from,to,cap,flow;};
vector <node> edges;
vector <int> mp[maxn];
int n,m,s,t,d[maxn],cur[maxn];
bool vis[maxn];
queue <int> que;

inline void add_edge(int u,int v,int w)
{
	//cout<<u<<" "<<v<<" "<<w<<endl;
	edges.push_back((node){u,v,w,0});
	edges.push_back((node){v,u,0,0});
	int pp=edges.size();
	mp[u].push_back(pp-2);
	mp[v].push_back(pp-1);
}

inline bool bfs()
{
	for(int i=s;i<=t;i++) d[i]=inf,vis[i]=0; d[s]=0; vis[s]=1; que.push(s);
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

int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		p[i].a=read(); p[i].c=read(); p[i].b=read(); p[i].d=read();
		p[i].b++; p[i].d++;
		x[++cnt1]=p[i].a; x[++cnt1]=p[i].b;
		y[++cnt2]=p[i].c; y[++cnt2]=p[i].d;
	}
	sort(x+1,x+cnt1+1); sort(y+1,y+cnt2+1);
	totx=unique(x+1,x+cnt1+1)-x-1;
	toty=unique(y+1,y+cnt2+1)-y-1;
	for(int z=1;z<=m;z++)
	{
		int tx1=lower_bound(x+1,x+totx+1,p[z].a)-x;
		int tx2=lower_bound(x+1,x+totx+1,p[z].b)-x;
		int ty1=lower_bound(y+1,y+toty+1,p[z].c)-y;
		int ty2=lower_bound(y+1,y+toty+1,p[z].d)-y;
		for(int i=tx1+1;i<=tx2;i++)
			for(int j=ty1+1;j<=ty2;j++) q[i][j]=1;
	}
	for(int i=1;i<=totx;i++) for(int j=1;j<=toty;j++) if(q[i][j]) add_edge(i,totx+j,inf);
	t=totx+toty+1; s=0;
	for(int i=2;i<=totx;i++) add_edge(s,i,x[i]-x[i-1]);
	for(int i=2;i<=toty;i++) add_edge(totx+i,t,y[i]-y[i-1]);
	cout<<max_flow()<<endl;
	return 0;
}
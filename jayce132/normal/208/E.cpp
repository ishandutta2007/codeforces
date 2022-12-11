#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;

struct node {
	int v,next;
};
node e[maxn];
int cnt,start[maxn];
inline void addedge(int u,int v){e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,m;
int p[maxn][20];

struct Query {
	int x,dep;
};

Query qu[maxn];

vector<int> to[maxn];

int rt[maxn],tot;

inline void init()
{
	n=read();
	REP(i,1,n)
	{
		int &x=p[i][0];x=read();
		if(x)addedge(x,i);
		else rt[++tot]=i;
	}
	REP(j,1,19)REP(i,1,n)p[i][j]=p[p[i][j-1]][j-1];
	m=read();
	REP(i,1,m)
	{
		int x=read(),dep=read();
		DREP(j,19,0)if(dep>>j&1)x=p[x][j];
		qu[i]=(Query){x,dep};
		to[x].push_back(i);
	}
}

int deep[maxn],sz[maxn],son[maxn];

int s[maxn];

void dfs(int u)
{
	sz[u]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		deep[v]=deep[u]+1;
		dfs(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}

int ans[maxn];

inline void Add(int x,int d){ s[deep[x]]+=d;}

void update(int u,int fa,int op)
{
	Add(u,op);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		update(v,u,op);
	}
}

void dfs1(int u,int fa)
{
	EREP(i,u)
	{
		int v=e[i].v;
		if(son[u]==v)continue;
		dfs1(v,u);
	}
	if(son[u])dfs1(son[u],u);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==son[u])continue;
		update(v,u,1);
	}
	Add(u,1);

	for(int v:to[u])
	{
		int dep=deep[u]+qu[v].dep;
		ans[v]=s[dep]-1;
	}
	if(son[fa]!=u)update(u,fa,-1);
	
}


inline void doing()
{
	deep[1]=1;
	REP(i,1,tot)dfs(rt[i]);
	REP(i,1,tot)dfs1(rt[i],0);
	REP(i,1,m)printf("%d ",ans[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cousin.in","r",stdin);
	freopen("cousin.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
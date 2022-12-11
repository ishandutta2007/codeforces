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
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,col[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)col[i]=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
}

int sz[maxn],son[maxn];

void dfs(int u,int fa)
{
	sz[u]=1;
	int Son=0;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[Son])Son=v;
	}
	son[u]=Son;
}

int Col[maxn],num[maxn];
ll sum[maxn];
int Max;

inline void Add(int col,int d)
{
	num[Col[col]]--;sum[Col[col]]-=col;
	Col[col]+=d;
	num[Col[col]]++;sum[Col[col]]+=col;
	if(d>0)Max=max(Max,Col[col]);
	else if(!num[Max] )Max--;
}

void update(int u,int fa,int f)
{
	Add(col[u],f);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		update(v,u,f);
	}
}

ll ans[maxn];

void dfs1(int u,int fa)
{
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa || v==son[u])continue;
		dfs1(v,u);
	}
	if(son[u])dfs1(son[u],u);
	EREP(i,u)
	{
		int v=e[i].v;;
		if(v==fa || v==son[u])continue;
		update(v,u,1);
	}
	Add(col[u],1);
	ans[u]=sum[Max];
	if(son[fa]!=u)update(u,fa,-1);
}

inline void doing()
{
	dfs(1,0);
	dfs1(1,0);
	REP(i,1,n)printf("%lld ",ans[i]);puts("");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
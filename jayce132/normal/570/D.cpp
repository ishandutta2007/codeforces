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

const int maxn=5e5+20;

int n,m;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt=1,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int deep[maxn],col[maxn];
int sz[maxn],son[maxn];
int f[maxn];

struct Query {
	int x,dep;
};
Query qu[maxn];

vector<int>to[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,2,n)addedge(read(),i);
	REP(i,1,n)col[i]=1<<(getchar()-'a');
	REP(i,1,m)
	{
		int x=read(),dep=read();
		qu[i]=(Query){x,dep};
		to[x].push_back(i);
	}
}

bool ans[maxn];

void dfs(int u,int fa)
{
	sz[u]=1;
	deep[u]=deep[fa]+1;
	f[u]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		f[u]=max(f[u],f[v]+1);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}

int s[maxn];

inline void Add(int x)
{
	s[deep[x]]^=col[x];
}

void update(int u,int fa)
{
	Add(u);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		update(v,u);
	}
}

void dfs1(int u,int fa)
{
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa || v==son[u])continue;
		dfs1(v,u);
	}
	if(son[u])dfs1(son[u],u);
	Add(u);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa || v==son[u])continue;
		update(v,u);
	}
	for(int v:to[u])
	{
		int dep=qu[v].dep;
		REP(i,0,25)if(s[dep]==(1<<i))
		{
			ans[v]=1;break;
		}
		if(!s[dep])ans[v]=1;
	}
	if(son[fa]!=u)update(u,fa);
	
}

inline void doing()
{
	dfs(1,0);
	dfs1(1,0);
	REP(i,1,m)if(ans[i])puts("Yes");
	else puts("No");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define int ll
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n;

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
}

int f[maxn],g[maxn],sz[maxn];
ll ans;

void dfs(int u,int fa)
{
	f[u]=0;g[u]=0;sz[u]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		f[u]+=f[v]+sz[v]-g[v];
		g[u]+=sz[v]-g[v];
	}
}

ll pref[maxn],suff[maxn],preg[maxn],sufg[maxn];
int st[maxn],top,size[maxn];

void dfs1(int u,int fa)
{
	
	top=0;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		st[++top]=v;
		size[top]=sz[v];
	}
	if(fa)st[++top]=u,size[top]=n-sz[u];
	pref[0]=preg[0]=0;
	suff[top+1]=sufg[top+1]=0;
	
	REP(i,1,top)pref[i]=pref[i-1]+f[st[i]]+size[i]-g[st[i]],preg[i]=preg[i-1]+size[i]-g[st[i]];
	DREP(i,top,1)suff[i]=suff[i+1]+f[st[i]]+size[i]-g[st[i]],sufg[i]=sufg[i+1]+size[i]-g[st[i]];
	ans+=pref[top];
	REP(i,1,top-(fa>0))
	{
		f[st[i]]=pref[i-1]+suff[i+1];
		g[st[i]]=preg[i-1]+sufg[i+1];
	}
	EREP(i,u)if(e[i].v!=fa)dfs1(e[i].v,u);
}

inline void doing()
{
	dfs(1,0);
	dfs1(1,0);
	printf("%lld\n",ans>>1);
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
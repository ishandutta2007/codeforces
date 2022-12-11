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
#include<cassert>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int mod=998244353;
const int maxn=3e5+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];

inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,g[maxn][3];

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

int pre[maxn],st[maxn],suf[maxn],top;

void dfs(int u,int fa)
{
	g[u][0]=g[u][2]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		g[u][2]=(ll)g[u][2]*(g[v][1]*2%mod+g[v][0])%mod;
		g[u][0]=(ll)g[u][0]*(g[v][1]+g[v][0])%mod;
	}
	top=0;
	EREP(i,u)if(e[i].v!=fa)st[++top]=e[i].v;
	pre[0]=1; suf[top+1]=1;
	REP(i,1,top)pre[i]=(ll)pre[i-1]*(g[st[i]][0]+g[st[i]][1]*2%mod)%mod;
	DREP(i,top,1)suf[i]=(ll)suf[i+1]*(g[st[i]][0]+g[st[i]][1]*2%mod)%mod;
	REP(i,1,top)g[u][1]=(g[u][1]+(ll)pre[i-1]*suf[i+1]%mod*g[st[i]][2])%mod;
}

inline void doing()
{
	dfs(1,0);
	printf("%d\n",(g[1][0]+g[1][1])%mod);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
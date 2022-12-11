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

const int maxn=2e5+20;
const int maxp=2e5;
const int mod=1e9+7;

inline int power(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=(ll)ans*a%mod;
		b>>=1;
		a=(ll)a*a%mod;
	}
	return ans;
}

int mark[maxp+20],prime[maxp+20],tot,phi[maxp+20],mu[maxp+20],F[maxp+20],G[maxp+20],inv[maxp+20];

inline void prepare()
{
	mu[1]=phi[1]=1;
	REP(i,2,maxp)
	{
		if(!mark[i])prime[++tot]=i,phi[i]=i-1,mu[i]=-1;
		for(int j=1;j<=tot&&i*prime[j]<=maxp;j++)
		{
			int k=i*prime[j];
			mark[k]=1;
			if(i%prime[j])phi[k]=phi[i]*(prime[j]-1),mu[k]=-mu[i];
			else {phi[k]=phi[i]*prime[j];break;}
		}
	}
	inv[1]=1;REP(i,2,maxp)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	REP(j,1,maxp)REP(i,1,maxp/j)F[i*j]=(F[i*j]+(ll)mu[j]*i*inv[phi[i]]%mod+mod)%mod;
}

int n,p[maxn];

vector<int>to[maxn];
int dfn[maxn],times,top[maxn],deep[maxn],sz[maxn],son[maxn],fa[maxn],low[maxn];

void dfs(int u)
{
	sz[u]=1;
	for(int v:to[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;
		deep[v]=deep[u]+1;
		dfs(v);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}

void dfs1(int u)
{
	dfn[u]=++times;
	if(son[u])top[son[u]]=top[u],dfs1(son[u]);
	for(int v:to[u])
	{
		if(v==fa[u] || v==son[u])continue;
		top[v]=v;
		dfs1(v);
	}
	low[u]=times;
}

inline int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(deep[top[u]]>deep[top[v]])swap(u,v);
		v=fa[top[v]];
	}
	if(deep[u]>deep[v])swap(u,v);
	return u;
}

inline void init()
{
	n=read();
	REP(i,1,n)p[i]=read();
	REP(i,1,n-1)
	{
		int u=p[read()],v=p[read()];
		to[u].push_back(v);
		to[v].push_back(u);
	}
	deep[1]=1;
	dfs(1);
	top[1]=1;
	dfs1(1);
}

int a[maxn<<1],vis[maxn];

inline bool cmp(int a,int b){ return dfn[a]<dfn[b];}

struct node {
	int v,next,w;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}

int st[maxn],Top,k,K,d;
int size[maxn];

void dfs2(int u)
{
	size[u]=vis[u]?phi[u]:0;
	EREP(i,u)
	{
		int v=e[i].v;
		dfs2(v);
		size[u]=(size[u]+size[v])%mod;
		G[d]=(G[d]+(ll)e[i].w*(size[v])%mod*(K-size[v]+mod)*2%mod)%mod;
	}
}

inline void doing()
{
	for(d=1;d<=n;d++)
	{
		k=n/d;K=0;
		REP(j,1,k)a[j]=j*d,vis[j*d]=1,K=(K+phi[j*d])%mod;
		a[++k]=1;
		sort(a+1,a+k+1,cmp);
		REP(i,1,k-1)a[++k]=lca(a[i],a[i+1]);
		sort(a+1,a+k+1,cmp);
		k=unique(a+1,a+k+1)-(a+1);
		st[Top=1]=1;
		REP(i,2,k)
		{
			int u=a[i];
			while(Top>1 && (dfn[u]<dfn[st[Top]] || dfn[u]>low[st[Top]]))Top--;
			addedge(st[Top],u,deep[u]-deep[st[Top]]);
			st[++Top]=u;
		}
		dfs2(1);
		cnt=0;REP(i,1,k)vis[a[i]]=0,start[a[i]]=0;
	}
	int ans=0;
	REP(i,1,n)ans=(ans+(ll)G[i]*F[i]%mod)%mod;
	printf("%lld\n",(ll)ans*power((ll)n*(n-1)%mod,mod-2)%mod);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("surprise.in","r",stdin);
	freopen("surprise.out","w",stdout);
#endif
	prepare();
	init();
	doing();
	return 0;
}
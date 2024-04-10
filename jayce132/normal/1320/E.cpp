// luogu-judger-enable-o2
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
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
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

const int inf=0x3f3f3f3f;
const int maxn=4e5+20;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}
int dfn[maxn],fa[maxn],sz[maxn],deep[maxn],top[maxn],son[maxn],low[maxn],times,p[maxn][20];
int n;
vector<int>to[maxn];

void dfs(int u)
{
	sz[u]=1;int Son=0;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		deep[v]=deep[u]+1;
		p[v][0]=fa[v]=u;
		dfs(v);
		sz[u]+=sz[v];
		if(sz[Son]<sz[v])Son=v;
	}
	son[u]=Son;
}

void dfs1(int u)
{
	dfn[u]=++times;
	if(son[u])
	{
		top[son[u]]=top[u];
		dfs1(son[u]);
	}
	EREP(i,u)
	{
		int v=e[i].v;
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
		if(deep[top[u]]<deep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	if(deep[u]<deep[v])swap(u,v);
	return v;
}

inline bool In(int u,int v){ return dfn[u]<=dfn[v] && dfn[v]<=low[u];}

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	deep[1]=1;
	dfs(1);
	top[1]=1;
	dfs1(1);
	REP(j,1,19)REP(i,1,n)p[i][j]=p[p[i][j-1]][j-1];
}

int a[maxn<<1],vis[maxn],tot;

int ans[maxn];
inline bool cmp(const int a,const int b){ return dfn[a]<dfn[b];}



int V[maxn],S[maxn],bb[maxn];

#define pii pair<int,int>

pii f[maxn];

inline pii merge(pii a,pii b)
{
	if(!a.fi)return b;
	else if(!b.fi)return a;
	else if(a.fi==b.fi)return mkr(a.fi,min(a.se,b.se));
	{
		if(a.fi>b.fi)swap(a,b);
		int x=a.fi,y=b.fi;
		int da=a.se,db=b.se;
		return (da+S[x]-1)/S[x]<=(db+S[y]-1)/S[y]?a:b;
	}
}

void dfs2(int u)
{
	if(vis[u])f[u]=mkr(vis[u],0);
	for(int v:to[u])
	{
		dfs2(v);
		f[u]=merge(f[u],mkr(f[v].fi,f[v].se+deep[v]-deep[u]));
	}
}

  
void dfs3(int u)
{
	static int st[maxn],Top;
	static pii stw[maxn],pre[maxn],suf[maxn];
	Top=0;
	for(int v:to[u])
	{
		st[++Top]=v;
		stw[Top]=mkr(f[v].fi,f[v].se+(deep[v]-deep[u]));
	}
	st[++Top]=u,stw[Top]=f[u];
	pre[0]=mkr(0,0);
	REP(i,1,Top)pre[i]=merge(pre[i-1],stw[i]);
	suf[Top+1]=mkr(0,0);
	DREP(i,Top,1)suf[i]=merge(suf[i+1],stw[i]);
	ans[u]=pre[Top].fi;
	REP(i,1,Top-1)
	{
		pii mg=merge(pre[i-1],suf[i+1]);
		f[st[i]]=merge(f[st[i]],mkr(mg.fi,mg.se+deep[st[i]]-deep[u]));//chkmin(f[st[i]],min(pre[i-1],suf[i+1])+(deep[st[i]]-deep[u]));
	}
	for(int v:to[u])dfs3(v);
}

inline void doing()
{
	int q=read();
	//REP(i,1,n)f[i]=(Node){0,inf};
	REP(i,1,q)
	{
		int A=read(),B=read();
		tot=0;
		a[++tot]=1;
		REP(j,1,A)V[j]=read(),S[j]=read(),a[++tot]=V[j],vis[V[j]]=j;
		REP(j,1,B)bb[j]=read(),a[++tot]=bb[j];
		
		sort(a+1,a+tot+1,cmp);
		tot=unique(a+1,a+tot+1)-(a+1);
		REP(j,1,tot-1)a[++tot]=lca(a[j],a[j+1]);
		sort(a+1,a+tot+1,cmp);
		tot=unique(a+1,a+tot+1)-(a+1);

		static int st[maxn],Top;
		
		st[Top=1]=a[1];
		REP(j,2,tot)
		{
			while(!In(st[Top],a[j]))Top--;
			to[st[Top]].push_back(a[j]);
			st[++Top]=a[j];
		}
		
		dfs2(1);
		dfs3(1);
		REP(j,1,B)printf("%d ",ans[bb[j]]); puts("");
		REP(j,1,tot)vis[a[j]]=0,ans[a[j]]=0,to[a[j]].clear(),f[a[j]]=mkr(0,0);
		
		//REP(j,1,tot)f[a[j]]=(Node){0,inf};
		
		/*int total=tot=read();
		REP(j,1,tot)vis[a[j]=read()]=j;
		if(!vis[1])a[++tot]=1;
		sort(a+1,a+tot+1,cmp);
		REP(j,1,tot-1)a[++tot]=lca(a[j],a[j+1]);
		sort(a+1,a+tot+1,cmp);
		tot=unique(a+1,a+tot+1)-(a+1);
		st[Top=1]=a[1];
		REP(j,2,tot)
		{
			while(!In(st[Top],a[j]))Top--;
			to[st[Top]].push_back(a[j]);
			st[++Top]=a[j];
		}
		
		dfs2(1);
		dfs3(1);
		dfs4(1);
		REP(j,1,tot)if(vis[a[j]])Ans[vis[a[j]]]=ans[a[j]];
		REP(j,1,total)printf("%d ",Ans[j]);puts("");
		REP(j,1,tot)vis[a[j]]=0,ans[a[j]]=0,to[a[j]].clear();
		REP(j,1,tot)f[a[j]]=(Node){0,inf};*/
		
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
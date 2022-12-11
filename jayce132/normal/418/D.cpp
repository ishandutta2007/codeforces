#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    char ch=getchar(); int x=0,q=0;
    while(ch<'0'||ch>'9') q=ch=='-'?1:q,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return q?-x:x;
}

const int maxn=1e5+20;
const int inf=0x3f3f3f3f;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

const int maxp=16;

int n;
int deep[maxn],fa[maxn],dfn[maxn],top[maxn],son[maxn],sz[maxn],times;
int p[maxn][17],pm[maxn][17],pmm[maxn][17];

struct Max {
	int mx,cmx,ccmx;
	//Max(){ mx=cmx=-inf;}
	/*inline void chk(Max b) {
		if(b.mx>mx)cmx=max(mx,b.cmx),mx=b.mx; 
		else chkmax(cmx,b.mx);
		}*/

	inline void chk(int b) {
		if(b>mx)ccmx=cmx,cmx=mx,mx=b;
		else if(b>cmx)ccmx=cmx,cmx=b;
		else chkmax(ccmx,b);
	}

	inline int exe(int x){ return x==mx?cmx:mx;}
}f[maxn];
int g[maxn];

inline Max operator + (Max a,int b){ return (Max){a.mx+b,a.cmx+b};}

void dfs(int u)
{
	sz[u]=1; f[u]=(Max){0,-inf};

	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		p[v][0]=fa[v]=u;
		deep[v]=deep[u]+1;
		dfs(v);
		f[u].chk(f[v].mx+1);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])son[u]=v;
	}
}

void dfs1(int u)
{
	dfn[u]=++times;
	if(son[u])top[son[u]]=top[u],dfs1(son[u]);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u] || v==son[u])continue;
		top[v]=v;
		dfs1(v);
	}
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

int hbit[maxn];

inline void Get_P()
{
	REP(j,1,maxp)REP(i,1,n)p[i][j]=p[p[i][j-1]][j-1];
	REP(i,1,n)if(p[i][0])pm[i][0]=f[fa[i]].exe(f[i].mx+1)+1,pmm[i][0]=f[fa[i]].exe(f[i].mx+1)-1;
	REP(j,1,maxp)REP(i,1,n)if(p[i][j])
	{
		pm[i][j]=max(pm[i][j-1],pm[p[i][j-1]][j-1]+(1<<j-1));
		pmm[i][j]=max(pmm[i][j-1],pmm[p[i][j-1]][j-1]-(1<<j-1));
	}
}

void dfs2(int u)
{
	Max tmp=(Max){g[u],-inf};
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		tmp.chk(f[v].mx+1);
	}
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		g[v]=tmp.exe(f[v].mx+1)+1;
		dfs2(v);
	}
}

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	deep[1]=1; dfs(1);
	top[1]=1; dfs1(1);
	Get_P();
	REP(i,1,n)DREP(j,maxp,0)if(i>>j&1){hbit[i]=j;break;}
	dfs2(1);
}

inline int Dis(int u,int v){ return deep[u]+deep[v]-2*deep[lca(u,v)];}

inline void doing()
{
	int ans=0;ll Ans=0;
	f[0]=(Max){-inf,-inf,-inf};
	int m=read();
	REP(i,1,m)
	{
		int u=read(),v=read(),t=lca(u,v),sum=0;
		if(deep[u]<deep[v])swap(u,v);
		int dis=deep[u]+deep[v]-(deep[t]<<1)>>1,now=u,rs=0;
		chkmax(sum,f[u].mx); 
		for(int tmp=dis-(deep[u]==deep[v]);tmp;tmp-=1<<hbit[tmp])
			chkmax(sum,rs+pm[now][hbit[tmp]]),now=p[now][hbit[tmp]],rs+=1<<hbit[tmp];
		rs=deep[now]+deep[v]-(deep[t]<<1);
		for(int tmp=deep[now]-deep[t]-1;tmp>0;tmp-=1<<hbit[tmp])
			chkmax(sum,rs+pmm[now][hbit[tmp]]),now=p[now][hbit[tmp]],rs-=1<<hbit[tmp];
		int T1=now,T2;
		if(v!=t)chkmax(sum,f[v].mx); rs=0; now=v;
		for(int tmp=deep[v]-deep[t]-1;tmp>0;tmp-=1<<hbit[tmp])
			chkmax(sum,rs+pm[now][hbit[tmp]]),now=p[now][hbit[tmp]],rs+=1<<hbit[tmp];
		T2=now;
		chkmax(sum,g[t]+deep[v]-deep[t]);
		if(T1==t )T1=0; if(T2==t) T2=0;
		if(f[t].mx!= max(f[T2].mx+1,f[T1].mx+1))chkmax(sum,f[t].mx+deep[v]-deep[t]);
		else if(f[t].cmx!= min(f[T1].mx+1,f[T2].mx+1)) chkmax(sum,f[t].cmx+deep[v]-deep[t]);
		else chkmax(sum,f[t].ccmx+deep[v]-deep[t]);
		
		ans=sum;
		printf("%d\n",sum);
	}
	
}

int main()
{
	init();
	doing();
	return 0;
}
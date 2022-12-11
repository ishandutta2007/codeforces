#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,u) for(int i=start[u];i;i=e[i].next)
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=2e5+20;
const int inf=0x3f3f3f3f;

struct node {
	int v,next,w;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}

int n;
int w[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)w[i]=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
}

void get_ans(int u,int fa,ll dis,double &ans)
{
	ans+=w[u]*pow(dis,1.5);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		get_ans(v,u,dis+e[i].w,ans);
	}
}

void get_ans1(int u,int fa,ll dis,double &ans)
{
	ans+=w[u]*pow(dis,0.5);
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		get_ans1(v,u,dis+e[i].w,ans);
	}
}

int vis[maxn],sz[maxn];
int mn,sum,rt;

void findroot(int u,int fa)
{
	sz[u]=1; int mx=0;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa || vis[v])continue;
		findroot(v,u);
		sz[u]+=sz[v];
		chkmax(mx,sz[v]);
	}
	chkmax(mx,sum-sz[u]);
	if(mx<mn)mn=mx,rt=u;
}

double Ans=1e200; int wz;

void solve(int u)
{
	vis[u]=1; 
	int V=u;
	double now=0;
	get_ans(u,0,0,now);
	if(now<Ans)Ans=now,wz=u;
	double all=0,mxto=0;
	get_ans1(u,0,0,all);
	EREP(i,u)
	{
		int v=e[i].v;
		if(vis[v])continue;
		double to=0;
		get_ans1(v,u,e[i].w,to);
		if(to>mxto)mxto=to,V=v;
	}
	if(mxto*2>all)
	{
		sum=sz[u]>=sz[V]?sz[V]:sum-sz[V];
		mn=inf; findroot(V,0);
		solve(rt);
	}
}

inline void doing()
{
	mn=inf,sum=n; findroot(1,0);
	solve(rt);
	printf("%d %.10lf\n",wz,Ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("566C.in","r",stdin);
	freopen("566C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
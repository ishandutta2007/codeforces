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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e5+20;
const int inf=0x3f3f3f3f;

struct node {
	int v,next,w;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}

int n,q;

inline int bfs(int S)
{
	static int dis[maxn];
	memset(dis,inf,sizeof(int)*(n+1));
	queue<int>q;
	q.push(S); dis[S]=0;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		EREP(i,u)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				q.push(v);
			}
		}
	}
	int mx=0,mxid=0;
	REP(i,1,n)if(dis[i]>mx)mx=dis[i],mxid=i;
	return mxid;
}

struct TREE {
	int RT;
	int dist[maxn],dep[maxn],son[maxn],fa[maxn],faw[maxn],top[maxn],down[maxn];
	int p[maxn][20];
	
	void dfs(int u) {
		EREP(i,u)
		{
			int v=e[i].v;
			if(v==fa[u])continue;
			p[v][0]=fa[v]=u; faw[v]=e[i].w;
			dist[v]=dist[u]+e[i].w;
			dfs(v);
			if(dep[u]<dep[v]+e[i].w)
				dep[u]=dep[v]+e[i].w,son[u]=v;
		}
	}

#define pii pair<int,int>
	
	pii chain[maxn<<1];int ctp;
	
	void dfs1(int u,bool tp) {
		if(tp)
		{
			top[u]=u;
			chain[++ctp]=mkr(faw[u]+dep[u],u);
		}else top[u]=top[fa[u]];             
		if(son[u])dfs1(son[u],0),down[u]=down[son[u]];
		else down[u]=u;
		
		EREP(i,u)
		{
			int v=e[i].v;
			if(v==fa[u] || v==son[u])continue;
			dfs1(v,1);
		}
	}

	int pre[maxn<<1];
	int f[maxn];

	void dfs2(int u) {
		EREP(i,u)
		{
			int v=e[i].v;
			if(v==fa[u])continue;
			dfs2(v);
			chkmin(f[u],f[v]);
		}
	}
	
	inline void Init() {
		dfs(RT);
		dfs1(RT,1);
		sort(chain+1,chain+ctp+1); reverse(chain+1,chain+ctp+1);
		REP(i,1,2*n-1)pre[i]=pre[i-1]+chain[i].fi;
		REP(i,1,n)f[i]=inf;
		REP(i,1,ctp)f[down[chain[i].se]]=i;
		dfs2(RT);
		REP(j,1,18)REP(i,1,n)p[i][j]=p[p[i][j-1]][j-1];
	}

	inline int Up(int x,int k) {
		DREP(i,18,0)if(f[p[x][i]]>k)x=p[x][i];
		x=fa[x];
		return x;
	}
	
	inline int Ask(int x,int y) {
		int k=2*y-1;
		int ans=pre[k];
		if(f[x]<=k)return ans;
		else {
			int t=Up(x,k);
			ans=pre[k-1]+(dist[down[x]]-dist[t]);
			chkmax(ans,pre[k]+(dist[down[x]]-dist[down[t]]));
			return ans;
		}
	}
	
}T1,T2;

inline void init()
{
	n=read();q=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	int S=bfs(1),T=bfs(S);
	T1.RT=S; T2.RT=T;
	T1.Init(); T2.Init();
}

inline void doing()
{
	int lstans=0;
	while(q--)
	{
		int x=(read()+lstans-1)%n+1,y=(read()+lstans-1)%n+1;
		int ans=max(T1.Ask(x,y),T2.Ask(x,y));
		printf("%d\n",lstans=ans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("526G.in","r",stdin);
	freopen("526G.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
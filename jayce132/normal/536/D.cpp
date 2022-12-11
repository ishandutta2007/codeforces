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

const int maxn=2e3+20;
const ll inf=1ll<<60;

struct node {
	int v,next,w;
};
node e[(1<<18)+20];
int cnt,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;} 

int n,m;
int s,t;
int val[maxn];
ll a[maxn],b[maxn],ax[maxn],bx[maxn];
int na,nb;

struct point {
	ll pos;int id;
};
point pa[maxn],pb[maxn];
inline bool operator < (point a,point b){ return a.pos<b.pos;}

#define pli pair<ll,int>

inline void DIJ(ll *dist,int S)
{
	static priority_queue<pli ,vector<pli >,greater<pli > >q; 
	static int vis[maxn];
	REP(i,1,n)dist[i]=inf,vis[i]=0;
	q.push(mkr(dist[S]=0,S));
	while(!q.empty())
	{
		int u=q.top().se;q.pop();
		if(vis[u])continue;
		EREP(i,u)
		{
			int v=e[i].v;
			if(dist[v]>dist[u]+e[i].w)
			{
				dist[v]=dist[u]+e[i].w;
				q.push(mkr(dist[v],v));
			}
		}
	}
}

inline int LSH(ll *a,ll *sx,int n)
{
	int tx;
	tx=n;
	REP(i,1,tx)sx[i]=a[i];
	sort(sx+1,sx+tx+1); tx=unique(sx+1,sx+tx+1)-sx-1;
	REP(i,1,n)a[i]=lower_bound(sx+1,sx+tx+1,a[i])-sx;
	return tx;
}


inline void init()
{
	n=read();m=read();
	s=read(); t=read();
	
	REP(i,1,n)val[i]=read();
	REP(i,1,m)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	DIJ(a,s); DIJ(b,t);

	na=LSH(a,ax,n); nb=LSH(b,bx,n);
	REP(i,1,n)pa[i]=(point){a[i],i}; sort(pa+1,pa+n+1);
	REP(i,1,n)pb[i]=(point){b[i],i}; sort(pb+1,pb+n+1);
	
}

ll sum[2][maxn][maxn];
ll cut[2][maxn][maxn];

ll dp[2][maxn][maxn];

inline void doing()
{
	REP(i,1,n)sum[0][a[i]][b[i]]+=val[i],sum[1][a[i]][b[i]]+=val[i],cut[0][a[i]][b[i]]++,cut[1][a[i]][b[i]]++;
	DREP(i,na,1)DREP(j,nb,1)
	{
		sum[0][i][j]+=sum[0][i+1][j],cut[0][i][j]+=cut[0][i+1][j];
		sum[1][i][j]+=sum[1][i][j+1];cut[1][i][j]+=cut[1][i][j+1];
	}
	
	DREP(i,na,0)DREP(j,nb,0)
	{

		if(cut[1][i+1][j+1])
		{
			dp[0][i][j]=max(dp[0][i+1][j],-dp[1][i+1][j])+sum[1][i+1][j+1];
		}else dp[0][i][j]=dp[0][i+1][j];
		if(cut[0][i+1][j+1])
		{
			dp[1][i][j]=max(dp[1][i][j+1],-dp[0][i][j+1])+sum[0][i+1][j+1];
		}else dp[1][i][j]=dp[1][i][j+1];
	}
	//printf("%lld\n",dp[0][1][1]);
	cerr<<dp[0][0][0]<<endl;
	if(dp[0][0][0]>0)puts("Break a heart");
	else if(dp[0][0][0]<0)puts("Cry");
	else puts("Flowers");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("CF536D.in","r",stdin);
	freopen("CF536D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
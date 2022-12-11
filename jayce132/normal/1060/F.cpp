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
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=120;

struct node {
	int v,next;
};
node e[maxn];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}
int n;
double C[maxn][maxn];

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	C[0][0]=1;
	REP(i,1,n)REP(j,0,i)C[i][j]=((j?C[i-1][j-1]:0)+C[i-1][j]);
}

double dp[maxn][maxn];
int sz[maxn];
double tmp[maxn];

void dfs(int u,int fa)
{
	sz[u]=0; dp[u][0]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		tmp[0]=0; REP(a,1,sz[v])tmp[a]=tmp[a-1]+dp[v][a-1];
		REP(a,0,sz[v])tmp[a]=tmp[a]*0.5+dp[v][a]*(sz[v]-a);
		
		DREP(a,sz[u],0)
		{
			double tmp1=dp[u][a]; dp[u][a]=0;
			DREP(b,sz[v],0)dp[u][a+b]+=(tmp1*tmp[b]*C[a+b][a]*C[sz[u]+sz[v]-a-b][sz[u]-a]);
		}
		sz[u]+=sz[v];
	}
	sz[u]++;
}

inline void doing()
{
	double fac=1; REP(i,1,n-1)fac*=i;
	REP(i,1,n)
	{
		memset(dp,0,sizeof(dp));
		dfs(i,0);
		printf("%.8lf\n",dp[i][n-1]/fac);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("bullshit.in","r",stdin);
	freopen("bullshit.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
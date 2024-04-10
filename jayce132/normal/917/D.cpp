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

const int maxn=120;
const int mod=1e9+7;

inline void pls(int &a,int b){ a+=b;if(a>=mod)a-=mod;}

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n,jc[maxn],inv[maxn],jcn[maxn];
int g[maxn],dp[maxn][maxn][maxn],sz[maxn],f[maxn];

inline void init()
{
	n=read();
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	inv[1]=jc[0]=jc[1]=jcn[0]=jcn[1]=1;
	REP(i,2,n)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jc[i]=(ll)i*jc[i-1]%mod,jcn[i]=(ll)inv[i]*jcn[i-1]%mod;
}

void dfs(int u,int fa)
{
	dp[u][0][1]=1;
	sz[u]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		DREP(a,sz[u],0)DREP(b,sz[u],0)
		{
			if(dp[u][a][b])
			{
				int t=dp[u][a][b];
				dp[u][a][b]=0;
				DREP(c,sz[v],0)DREP(d,sz[v],0)
				{
					pls(dp[u][a+c][b+d],(ll)t*dp[v][c][d]%mod);
					pls(dp[u][a+c+1][b],(ll)t*dp[v][c][d]%mod*d%mod);
				}
			}
		}
		sz[u]+=sz[v];
	}
}

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

inline int C(int n,int m){ return (ll)jc[n]*jcn[m]%mod*jcn[n-m]%mod;}

inline void doing()
{
	dfs(1,0);
	REP(i,0,n-1)REP(j,1,n)g[i]=(g[i]+(ll)dp[1][i][j]*(i>0?j:1))%mod;
	REP(i,2,n-1)g[i]=(ll)g[i]*power(n,i-1)%mod;
	REP(i,0,n-1)
	{
		REP(j,0,i)f[i]=(f[i]+(ll)(i-j&1?-1:1)*g[j]*C(n-1-j,n-1-i))%mod;
		f[i]=(f[i]+mod)%mod;
	}
	reverse(f,f+n);
	REP(i,0,n-1)printf("%d ",f[i]);
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
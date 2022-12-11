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
#include<bitset>
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

const int maxn=5e5+20;
const int mod=998244353;
const int inv2=mod+1>>1;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];

inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int n;

#define pii pair<int,int>

inline pii operator * (pii a,pii b){ return mkr((1ll*a.fi*b.se+1ll*b.fi*a.se)%mod,(ll)a.se*b.se%mod);}
inline pii operator + (pii a,pii b){ return mkr((a.fi+b.fi)%mod,(a.se+b.se)%mod);}
inline pii operator * (pii a,int b){ return mkr((ll)a.fi*b%mod,(ll)a.se*b%mod);}

pii dp[maxn][2];
int p2[maxn],sz[maxn];

void dfs(int u,int fa)
{
	dp[u][0]=mkr(0,1);sz[u]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		dp[u][1]=(dp[u][1]*(dp[v][0]+dp[v][1])*2+dp[u][0]*dp[v][0]+mkr((ll)dp[u][0].se*dp[v][0].se%mod,0));
		dp[u][0]=(dp[u][0]*(dp[v][0]+dp[v][1]*2));
		
//dp[u][1]=(dp[u][1]+(ll)(dp[v][0]+dp[v][1]) + dp[u][0]+ (ll)inv2*(dp[v][0]+dp[v][1]+1) + (ll)inv2*)
		//dp[u][0]=(dp[u][0]+(ll)(dp[v][1]) + )%mod;
	}
}

inline void init()
{
	n=read(); p2[0]=1; REP(i,1,n)p2[i]=p2[i-1]<<1,p2[i]>=mod?p2[i]-=mod:0;
	REP(i,1,n-1)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
}

inline void doing()
{
	dfs(1,0);
	printf("%lld\n",(ll)(dp[1][0].fi+dp[1][1].fi)*2%mod);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
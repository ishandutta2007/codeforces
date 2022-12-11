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

int n,D;

const int maxn=3e3+20;
const int mod=1e9+7;

struct node {
	int v,next;
};
node e[maxn<<1];
int cnt,start[maxn];
inline void addedge(int u,int v){ e[++cnt]=(node){v,start[u]};start[u]=cnt;}

int jc[maxn],jcn[maxn],inv[maxn];

inline void init()
{
	n=read();D=read();
	REP(i,2,n)addedge(read(),i);
	inv[1]=jc[0]=jc[1]=jcn[0]=jcn[1]=1;
	REP(i,2,n)jc[i]=(ll)i*jc[i-1]%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jcn[i]=(ll)inv[i]*jcn[i-1]%mod;
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

int dp[maxn][maxn];

inline void pls(int &a,int b){ a+=b;if(a>=mod)a-=mod;}

void dfs(int u,int fa)
{
	REP(i,1,n)dp[u][i]=1;
	EREP(i,u)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		REP(j,1,n)dp[u][j]=(ll)dp[u][j]*dp[v][j]%mod;
	}
	REP(i,1,n)pls(dp[u][i],dp[u][i-1]);
}

inline int Calc(int x,int n,int *a)
{
	if(x<=n)return a[x];
	int ans=0,fh=(n&1)?-1:1,now=1;
	REP(i,0,n)now=(ll)now*(x-i)%mod;
	REP(i,0,n)ans=(ans+(ll)fh*now*jcn[i]%mod*jcn[n-i]%mod*power(x-i,mod-2)%mod*a[i]%mod+mod)%mod,fh=-fh;
	return ans;
}

inline void doing()
{
	dfs(1,0);
	printf("%d\n",Calc(D,n,dp[1]));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("company.in","r",stdin);
	freopen("company.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
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
	int s=0,f=1; char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=1e4+20;
const int mod=998244353;
int jc[maxn],jcn[maxn],inv[maxn];

inline void prepare()
{
	jc[0]=jcn[1]=inv[1]=jc[1]=jcn[0]=1;
	REP(i,2,1e4)jc[i]=(ll)i*jc[i-1]%mod,inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod,jcn[i]=(ll)jcn[i-1]*inv[i]%mod;
}

int n,k,l;

inline void init()
{
	n=read();k=read();l=read();
}

int dp[maxn],f[maxn];

inline int C(int n,int m){ return 1ll*jc[n]*jcn[m]%mod*jcn[n-m]%mod;}

inline void doing()
{
	dp[0]=1;
	DREP(th,n,1)
	{
		DREP(j,2*n,0)
		{
			dp[j+2]=(dp[j+2]-(ll)dp[j]*2)%mod;
			dp[j+1]=(dp[j+1]+(ll)dp[j]*2)%mod;
			dp[j]=0;
		}
	}
	int ans=0;
	REP(i,0,n-k)
	{
		REP(j,0,2*n)ans=(ans+(ll)inv[j+1]*C(n,i)%mod*dp[j])%mod;
		memcpy(f,dp,sizeof(dp));
		DREP(j,2*n,0)
		{
			dp[j]=(dp[j+1]-(ll)f[j+2]*inv[2])%mod;
		}
		DREP(j,2*n,0)
		{
			dp[j+2]=(dp[j+2]+(ll)dp[j]*2)%mod;
			dp[j+1]=(dp[j+1]-(ll)dp[j]*2)%mod;
		}
	}
	ans=(ans+mod)%mod;
	ans=(ll)ans*l%mod;
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
#endif
	prepare();
	init();
	doing();
	return 0;
}
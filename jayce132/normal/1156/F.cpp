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

const int mod=998244353;
const int maxn=5e3+20;
int inv[maxn];

inline void prepare()
{
	inv[1]=1;
	REP(i,2,5e3)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
}

int n,a[maxn],num[maxn];
int t;

inline void init()
{
	n=read();
	REP(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
	t=1;num[1]=1;
	REP(i,2,n)
	{
		if(a[i]!=a[t])a[++t]=a[i];
		num[t]++;
	}
}

int dp[maxn][maxn];
int s[maxn];

inline void doing()
{
	int ans=0;
	dp[0][0]=1;
	REP(i,1,t)
	{
		int numinv=inv[n-i+1];
		s[0]=(ll)dp[i-1][0]*numinv%mod;
		REP(j,1,t)s[j]=(s[j-1]+(ll)dp[i-1][j]*numinv%mod)%mod;
		REP(j,1,t)dp[i][j]=(ll)s[j-1]*num[j]%mod;
		REP(j,1,t)ans=(ans+(ll)dp[i][j]*inv[n-i]%mod*(num[j]-1))%mod;
	}
	printf("%d\n",ans);
}

int main()
{
	prepare();
	init();
	doing();
	return 0;
}
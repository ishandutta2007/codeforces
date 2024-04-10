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

const int maxn=20;

int f[maxn][maxn];

vector<ll>dp[maxn][1<<14];
int cnt[1<<14];
ll ans[1<<14];
int n;


inline void init()
{
	n=read();
	REP(i,1,n)
	{
		static char str[maxn];
		scanf("%s",str+1);
		REP(j,1,n)f[i][j]=str[j]=='1';
	}
	REP(i,1,(1<<n)-1)cnt[i]=cnt[i^(i&(-i))]+1;
	REP(i,1,n)REP(j,1,(1<<n)-1)
		dp[i][j].resize(1<<cnt[j]-1);
	REP(i,1,n)dp[i][1<<i-1][0]=1;
	REP(S,1,(1<<n)-2)
	{
		REP(i,1,n)REP(j,0,(1<<cnt[S]-1)-1)
		{
			REP(k,1,n)if(~S>>k-1&1)
				dp[k][S|(1<<k-1)][j|(f[i][k]<<cnt[S]-1)]+=dp[i][S][j];
		}
	}
	
	REP(i,1,n)REP(j,0,(1<<n-1)-1)
		ans[j]+=dp[i][(1<<n)-1][j];//ans[j]=(ans[j]+dp[i][(1<<n)-1][j])%mod;
	REP(j,0,(1<<n-1)-1)printf("%lld ",ans[j]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("f.in","r",stdin);
	freopen("f1.out","w",stdout);
#endif
	init();
	return 0;
}
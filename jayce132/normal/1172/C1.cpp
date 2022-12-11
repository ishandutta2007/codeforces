#include <bits/stdc++.h>
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
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int mod=998244353;
const int maxn=2e5+20;

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

int a[maxn],n,m;
int w[maxn];

int Inv[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,n)w[i]=read();
}

int dp[3020][3020];
int a0,a1;

inline void doing()
{

	
	REP(i,1,n)if(a[i]==0)a0+=w[i];else a1+=w[i];
	REP(i,-m,m)
	{
		int all=a0+a1+i;
		if(all>=0)Inv[i+m]=power(all,mod-2);
	}
	
	dp[0][0]=1;
	REP(i,1,m)
	{
		REP(j,0,i-1)if(dp[i-1][j])
		{
			int all=a0+a1+j-(i-j),s=Inv[j-(i-1-j)+m];
			//0
			dp[i][j]=(dp[i][j]+(ll)dp[i-1][j]*s%mod*(a0-(i-1-j)))%mod;
			dp[i][j+1]=(dp[i][j+1]+(ll)dp[i-1][j]*s%mod*(a1+j))%mod;
		}
	}

	int ad0=0,ad1=0;
	REP(j,0,m)ad0=(ad0+(ll)j*dp[m][j])%mod;
	REP(j,0,m)ad1=(ad1+(ll)(m-j)*dp[m][j])%mod;
	REP(i,1,n)
	{
		if(a[i]==1)
		{
			int ans=(w[i]+(ll)ad0*power(a1,mod-2)%mod*w[i])%mod;
			printf("%d\n",ans);
		}else
		{
			int ans=(w[i]-(ll)ad1*power(a0,mod-2)%mod*w[i])%mod;
			ans=(ans+mod)%mod;
			printf("%d\n",ans);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
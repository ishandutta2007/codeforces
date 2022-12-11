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

const int maxn=1e5+20;
const int mod=998244353;

int a[maxn],n;
int dp[maxn][220][3];
int s[maxn][220][3];

inline void init()
{
	n=read();
	REP(i,1,n)a[i]=read();
}

inline void doing()
{
	dp[0][0][0]=1; REP(j,0,200)REP(op,0,2)s[0][j][op]=((j>0?s[0][j-1][op]:0)+(dp[0][j][op]))%mod;
	REP(i,1,n)
	{
		REP(j,1,200)if(a[i]==-1 || a[i]==j)
		{
			dp[i][j][0]=(1ll*s[i-1][200][0]-s[i-1][j][0]+s[i-1][200][2]-s[i-1][j][2]+mod*2)%mod;

			dp[i][j][1]=((ll)s[i-1][j-1][0]+s[i-1][j-1][1]+s[i-1][j-1][2])%mod;

			dp[i][j][2]=((ll)dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%mod;
			
		}
		REP(j,0,200)REP(op,0,2)s[i][j][op]=((j?s[i][j-1][op]:0)+(j>-1?dp[i][j][op]:0))%mod;
	}
	printf("%lld\n",((ll)s[n][200][0]+s[n][200][2])%mod);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
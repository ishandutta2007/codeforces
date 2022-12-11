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
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int mod=1e9+7;
const int maxn=720;

int n;
char str[maxn];
int dp[maxn][maxn][2];
int p[maxn];

inline void pls(int &a,int b){ a+=b;if(a>=mod)a-=mod;}

inline void init()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	int ten=10;
	p[1]=1; REP(i,2,n)p[i]=(p[i-1]+ten)%mod,ten=(ll)ten*10%mod;
}

inline void doing()
{
	int ans=0;
	REP(num,1,9)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0][1]=1;
		int sum=0;
		REP(i,1,n)
		{
			REP(j,0,sum)REP(op,0,1)if(dp[i-1][j][op])
			{
				int t=dp[i-1][j][op];
				REP(x,0,op?str[i]-'0':9)
				{
					pls(dp[i][j+(x>=num)][op&(str[i]-'0'==x)],t);
				}
			}
			++sum;
		}
		REP(i,0,sum)ans=(ans+(ll)(dp[n][i][0]+dp[n][i][1])*p[i])%mod;
	}
	printf("%d\n",ans);
	
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("order.in","r",stdin);
	freopen("order.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
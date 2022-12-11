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

const int maxn=1e6+20;
const int maxp=6;

int n,m,tag[maxn];

inline void init()
{
	n=read();m=read();
	REP(i,1,n)tag[read()]++;
}

int dp[maxn][7][7];

const int inf=0x3f3f3f3f;

inline void doing()
{
	memset(dp,inf,sizeof(dp));
	dp[0][0][0]=0;
	REP(i,0,m+3)
	{
		REP(j,0,6)REP(k,0,6)if(dp[i][j][k]!=inf)
		{
			int now=tag[i]; if(now>9){ now%=9; while(now+3<=9)now+=3; }
			REP(l,0,min(j,min(k,now)))
			{
				int rest=j-l; int NOW=now-l; if(NOW>6){NOW%=6; while(NOW+3<=6)NOW+=3;} 
				chkmin(dp[i+1][k-l][NOW],dp[i][j][k]+(rest%3));
			}
		}
	}
	int ans=(n-dp[m+3][0][0])/3;
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
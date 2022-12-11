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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
    int s=0,f=1; char ch=getchar();
    while(!isdigit(ch) && ch!='-')ch=getchar();
    if(ch=='-')ch=getchar(),f=-1;
    while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
    return ~f?s:-s;
}

const int maxn=3e3+20;
const int mod= 998244353;

int n,m;
char S[maxn];
char T[maxn];

inline void init()
{
    scanf("%s",S+1); n=strlen(S+1);
    scanf("%s",T+1); m=strlen(T+1);
}

int dp[maxn][maxn];
inline void pls(int &a,int b){ a+=b; a-=a>=mod?mod:0; }

inline void doing()
{
    int ans=0;
    DREP(i,n,1)
    {
	if(i>=m)pls(dp[i+1][0],1);
	REP(j,0,n)
	{
	    if(j+1>m || S[i]==T[j+1])pls(dp[i][j+1],dp[i+1][j]);
	    if(i+j>m || S[i]==T[i+j])pls(dp[i][j],dp[i+1][j]);
	}
    }
    REP(j,0,n)pls(ans,dp[1][j]);
    printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}
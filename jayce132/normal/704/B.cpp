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
inline void myassert(bool a,string s){ if(!a)cerr<<s<<endl,exit(0);}
inline int read()
{
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(isdigit(ch))s=s*10+ch-'0',ch=getchar();
	return ~f?s:-s;
}

const int maxn=5e3+20;
const ll inf=1ll<<60;

int n,x[maxn],a[maxn],b[maxn],c[maxn],d[maxn],S,T;

inline void init()
{
	n=read(); S=read(); T=read();
	REP(i,1,n)x[i]=read();
	REP(i,1,n)a[i]=read()+x[i];
	REP(i,1,n)b[i]=read()-x[i];
	REP(i,1,n)c[i]=read()+x[i];
	REP(i,1,n)d[i]=read()-x[i];
}

//A:
//B:
//C:
//D:

ll dp[2][maxn];

inline void doing()
{
	int u=0;
	memset(dp[u],63,sizeof(dp));
	dp[0][0]=0;
	int sp1=0,sp2=0;
	REP(i,1,n)
	{
		u^=1;
		memset(dp[u],63,sizeof(dp[u]));
		REP(j,0,i)
		{
			if(i==S)
			{
				if(j && (i==n || j>sp2))chkmin(dp[u][j],dp[u^1][j]+c[i]);
				chkmin(dp[u][j+1],dp[u^1][j]+d[i]);
				sp1=1;
			}
			else if(i==T)
			{
				if(j && (i==n || j>sp1))chkmin(dp[u][j],dp[u^1][j]+a[i]);
				chkmin(dp[u][j+1],dp[u^1][j]+b[i]);
				sp2=1;
			}
			else {
				chkmin(dp[u][j+1],dp[u^1][j]+b[i]+d[i]);
				if(j)
				{
					if(j>sp1)chkmin(dp[u][j],dp[u^1][j]+b[i]+c[i]);
					if(j>sp2)chkmin(dp[u][j],dp[u^1][j]+a[i]+d[i]);
					if(j>1 && (i==n || j>sp1+sp2))chkmin(dp[u][j-1],dp[u^1][j]+a[i]+c[i]);
				}
			}
		}
		//REP(j,1,n)cerr<<dp[u][j]<<" ";cerr<<endl;
	}
	printf("%lld\n",dp[u][1]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("704b.in","r",stdin);
	freopen("704b.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
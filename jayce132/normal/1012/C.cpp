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

const int maxn=5e3+20;

int a[maxn],dp[maxn][maxn],n;
int s[maxn][maxn];

inline void init()
{
	n=read();REP(i,1,n)a[i]=read();
}

const int inf=0x3f3f3f3f;

inline int Calc(int x,int y){ return max(y-a[x]+1,0);}

inline void doing()
{
	memset(dp,inf,sizeof(dp));memset(s,inf,sizeof(s));
	REP(i,1,n)dp[1][i]=Calc(i,a[i+1])+Calc(i,a[i-1]),s[1][i]=min(s[1][i-1],dp[1][i]);
	REP(i,2,(n+1)/2)
	{
		REP(j,3,n)
		{
			dp[i][j]=min(s[i-1][j-3]+Calc(j,a[j-1])+Calc(j,a[j+1]),dp[i-1][j-2]+Calc(j,a[j+1])+Calc(j,min(a[j-2]-1,a[j-1])));
			s[i][j]=min(s[i][j-1],dp[i][j]);
		}
	}
	REP(i,1,(n+1)/2)
	{
		int ans=inf;
		REP(j,1,n)ans=min(ans,dp[i][j]);
		printf("%d ",ans);
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
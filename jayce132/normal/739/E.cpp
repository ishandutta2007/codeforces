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

const int maxn=2e3+20;

int n,A,B;
double a[maxn],b[maxn],c[maxn];

#define pri pair<double,int>
#define mkr(a,b) make_pair(a,b)
#define fi first
#define se second

pri dp[maxn][maxn];

inline void init()
{
	n=read();A=read();B=read();
	REP(i,1,n)scanf("%lf",a+i);
	REP(i,1,n)scanf("%lf",b+i);
	REP(i,1,n)c[i]=1-(1-a[i])*(1-b[i]);
}

double eps=1e-8;

inline pri operator +(pri a,pri b) { return mkr(a.fi+b.fi,a.se+b.se);} 

template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}

pri check(double x)
{
	REP(i,1,n)
	{
		REP(j,0,min(i,A))
		{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j]+mkr(b[i]+x,1));
			if(j)chkmax(dp[i][j],max(dp[i-1][j-1]+mkr(a[i],0),dp[i-1][j-1]+mkr(c[i]+x,1) ));
		}
	}
	pri ans=mkr(-1e10,0);
	REP(i,0,A)ans=max(ans,dp[n][i]);
	return ans;
}

inline void doing()
{
	double l=-1,r=0;
	while(l+eps<r)
	{
		double mid=(l+r)*0.5;
		if(check(mid).se>=B)r=mid;
		else l=mid;
	}
	pri tmp=check(l);
	printf("%.8lf\n",tmp.fi-l*B);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("hunt.in","r",stdin);
	freopen("hunt.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
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

const int maxn=4e3+20;
const int inf =0x3f3f3f3f;

int n,k,a[maxn][maxn],g[maxn][maxn];

inline void init()
{
	n=read();k=read();
	REP(i,1,n)REP(j,1,n)a[i][j]=read()+a[i][j-1];
	REP(i,1,n)REP(j,i,n)g[i][j]=a[j][j]-a[j][i-1]+g[i][j-1];
}

#define pri pair<ll,int>
#define mkr(a,b) make_pair(a,b)
#define fi first
#define se second

pri dp[maxn];

inline pri operator +(pri a,pri b){ return mkr(a.fi+b.fi,a.se+b.se);}
//inline bool operator <(pri a,pri b){ return a.fi==b.fi?a.se>b.se:a.fi<b.fi;}

int q[maxn],beg[maxn],head,tail;

inline int Calc(int x,int y)
{
	int l=y,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(dp[x]+mkr(g[x+1][mid]+x,1) >=dp[y]+mkr(g[y+1][mid]+x,1) ) r=mid;
		else l=mid+1;
	}
	return l;
}

inline pri check(int x)
{
	q[head=tail=1]=0;beg[1]=0;
	REP(i,1,n)
	{
		while(head<tail && beg[head+1]<=i)head++;
		dp[i]=dp[q[head]]+mkr(g[q[head]+1][i]+x,1);
		while(head<tail && beg[tail]>=Calc(q[tail],i))--tail;
		q[++tail]=i; beg[tail]=Calc(q[tail-1],q[tail]);
	}
	return dp[n];
}


inline void doing()
{
	int l=0,r=g[1][n];
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid).se<=k)r=mid;
		else l=mid+1;
	}
	printf("%lld\n",check(l).fi-(ll)l*k);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("fish.in","r",stdin);
	freopen("fish.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
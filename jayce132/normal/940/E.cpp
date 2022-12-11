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
#define int ll
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;


int n,k,a[maxn],st[maxn][20],dp[maxn],Log[maxn];
ll s;

void init()
{
	n=read();k=read();
	REP(i,1,n)st[i][0]=read(),s+=st[i][0];
	for(int j=1;(1<<j)<=n;j++)
	{
		REP(i,1,n-(1<<j)+1)st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	REP(i,2,n)Log[i]=Log[i>>1]+1;
}

int query(int l,int r)
{
	int k=Log[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}

void doing()
{
	dp[0]=0;

	ll mx=0;
	REP(i,1,n)
	{
		dp[i]=max(dp[i],dp[i-1]);
		if(i-k>=0)dp[i]=max(dp[i],dp[i-k]+query(i-k+1,i));
		mx=max(mx,dp[i]);
	}
	printf("%lld\n",s-mx);
}

#undef int
int main()
{
	//freopen("e.in","r",stdin);
	//freopen("e.out","w",stdout);
	init();
	doing();
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
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

const int maxn=1e5+20;

int n,a[maxn],dp[maxn],k;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
#endif
	n=read();k=read();
	REP(i,1,n)
	{
		int x=__gcd(read()%k,k);
		a[i]=x;
	}
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-(a+1);
	int now=0;
	REP(i,1,n)now=__gcd(now,a[i]);
	for(int st=0;st<k;st+=now)dp[st]=1;
	int ans=0;
	REP(i,0,k-1)if(dp[i])ans++;
	printf("%d\n",ans);
	REP(i,0,k-1)if(dp[i])printf("%d ",i);
	return 0;
}
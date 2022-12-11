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

const int maxn=120;

int a[maxn],s,n,s1,zs;
int dp[120][10020];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	n=read();
	REP(i,1,n)a[read()]++;
	dp[0][0]=1;
	REP(i,1,100)if(a[i])
	{
		DREP(j,s1,0)DREP(l,s,0)if(dp[j][l])
		{
			chkmin(dp[j][l],2);
			REP(t,1,a[i])
			{
				dp[j+t][l+t*i]+=dp[j][l];
				chkmin(dp[j+t][l+t*i],2);
			}
		}
		s1+=a[i]; s+=i*a[i];
		zs++;
	}

	if(zs==1)printf("%d\n",n),exit(0);

	int mx=0;
	REP(i,1,100)if(a[i])
		REP(l,1,a[i])if(dp[l][l*i]==1)
			chkmax(mx,l+(l==a[i]&&zs==2?n-l:0));
	printf("%d\n",mx);
	
	return 0;
}
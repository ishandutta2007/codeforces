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

const int inf=0x3f3f3f3f;
const int maxn=5e4+20;

int n,k,a[maxn];
int dp[52][maxn];

inline void init()
{
	n=read();k=read();
	REP(i,1,n)a[i]=read();
}

int s[maxn],vis[maxn],tim;
int res;

int ql,qr;

void solve(int l,int r,int L,int R,int t,int op)
{
	int mid=(l+r)>>1;
	int mxid=mid-1;

	int GL=min(R,mid)+1,GR=mid;
	
	while(ql<GL)if(!--s[a[ql++]])res--;
	while(ql>GL)if(!s[a[++ql]]++)res++;
	while(qr>GR)if(!--s[a[qr--]])res--;
	while(qr<GR)if(!s[a[++qr]]++)res++;
	
	DREP(i,min(R,mid),L)
	{
		//if(vis[a[i]]!=tim)vis[a[i]]=tim,s[a[i]]=0;
		if(!s[a[--ql]]++)++res;
		//dp[t][l]=max(dp[t][l],res+dp[t-1][i-1]);
		if(res+dp[t-1][i-1]>dp[t][mid])dp[t][mid]=res+dp[t-1][i-1],mxid=i;
	}
	if(l==r)return;
	solve(l,mid,L,mxid,t,1); solve(mid+1,r,mxid,R,t,2);
}
	
inline void doing()
{
	dp[0][0]=0;REP(i,1,n)dp[0][i]=-inf;
	REP(i,1,k)
	{
		memset(dp[i],-63,sizeof(dp[i]));
		res=0; ql=n/2;qr=n/2-1;memset(s,0,sizeof(s));
		solve(i,n,i,n,i,0);
	}
	printf("%d\n",dp[k][n]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
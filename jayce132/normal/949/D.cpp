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

const int maxn=1e5+20;

int n,d,b;
ll a[maxn];

inline ll S(int l,int r){ return a[r]-a[l-1];}

int ans;

inline void init()
{
	n=read();d=read();b=read();
	REP(i,1,n)a[i]=read()+a[i-1];
}


inline bool check(ll x)
{
	int a1=0,a2=0,MID=(n+1)>>1,n1=0,n2=0;
	REP(i,1,MID)
	{
		if(min(S(1,min(i+(ll)d*i,(ll)n)),x)<(n1+1)*b)a1++;else n1++;
		if(i<MID || ~n&1)if(min(S(max(1ll,n-i+1-(ll)i*d),n),(ll)n*b-x)<(n2+1)*b)a2++;else n2++;
	}
	ans=min(ans,max(a1,a2));
	return a1<=a2;
}

inline void doing()
{
	ans=n+1;
	ll l=0,r=(ll)n*b;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("curfew.in","r",stdin);
	freopen("curfew.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}
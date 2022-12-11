#include <bits/stdc++.h>
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
#define SZ(A) ((int)A.size())
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=2e5+20;

ll a[maxn],b[maxn],n,m,ta,tb,k;

inline bool check(ll x)
{
	int mn=k+1,t=0;
	int j=1,lim=0;
	REP(i,1,m)t+=a[1]<=b[i] && b[i]<x,j+=a[1]>b[i],lim+=b[i]<x; a[n+1]=1ll<<60;
	chkmin(mn,t);
	REP(i,1,n)
	{
		++t;
		while(j<=lim && b[j]<a[i+1])j++,t--;
		chkmin(mn,t);
	}
	return mn<=k;
}

int main()
{
	n=read();m=read();ta=read();tb=read();k=read();
	REP(i,1,n)a[i]=read()+ta+tb;
	sort(a+1,a+n+1);
	REP(i,1,m)b[i]=read()+tb;
	sort(b+1,b+m+1);
	ll l=0,r=1e10;
	while(l<r)
	{
		ll mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	if(l!=(ll)1e10)printf("%lld\n",l);
	else puts("-1");
	return 0;
}
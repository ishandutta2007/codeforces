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
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

ll n,k,l,r,x;

inline void init()
{
	cin>>n>>l>>r>>k;
	if(l<=r)x=r-l+1;
	else x+=n-l+1+r;
}

inline void doing1()
{
	for(ll p=2*n;p>=n;p--)
	{
		ll t=(k-1)%p+1;
		if(x<=t && t<=x*2)
		{
			if((t-x+n<=p && p<=2*n-(2*x-t)) || ((t+1-x+n<=p && p<=2*n-(2*x-t-1))))printf("%lld\n",p-n),exit(0);
		}
	}
	puts("-1");
}

inline void doing2()
{
	ll ans=-n;

	if(x<=k && k<=2*x)printf("%lld\n",min(k-x+1+(n-x),n)),exit(0);
	
	for(ll i=1,lim=k/n;i<=lim;i++)
	{
		ll L=(k-2*x+i-1)/i,R=(k-x)/i;
		chkmax(L,n); chkmin(R,2*n);
		chkmax(L,(k-x+n+i)/(i+1)); chkmin(R,(2*n-2*x+k+1)/(i+1));
		if(L<=R)chkmax(ans,R);
	}
	if(ans<0)puts("-1");
	else printf("%lld\n",ans-n);
}

int main()
{
	init();
	if(n<=k/n)doing1();
	else doing2(); 
	return 0;
}
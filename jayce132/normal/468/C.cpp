#include<bits/stdc++.h>
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

const int maxp=20;

int n;
ll a;

inline ll mul(ll a,ll b,const ll mod)
{
	a%=mod; b%=mod;
	return (( a*b - (ll)floor((long double)a/mod*b)*mod )%mod+mod)%mod;
}

ll x;

inline void Out(ll t)
{
	static ll rk[100],tp=0;
	while(t)rk[++tp]=t%10,t/=10;
	rk[maxp+1]=1;
	DREP(i,maxp+1,1)printf("%lld",rk[i]);
}

inline void init()
{
	cin>>a;
	x=1;
	REP(i,1,maxp-1)x=mul(x,10,a);
	x=mul(x,45,a); x=mul(x,maxp,a);
	x=(x+1)%a;
	ll t=a-x;
	printf("%lld ",t+1); Out(t);
}

int main()
{
	init();
	return 0;
}
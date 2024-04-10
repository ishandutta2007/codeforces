#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define pi ((db)3.14159265358979323846264338327950288L)
#define buli __builtin_popcountll
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef long double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n;
int a[222222];
ll su[222222];
ll curup=0,curdo=1;int opt=1,optbo=1;


inline int grea(ll up,ll dow,ll up1,ll dow1){
	return up*dow1>up1*dow;
}
void work1(int m,bool pri){
	ll aup=0,ado=1;int opt=0;
	int l=0,r=min(m-1,n-m);
	while(l<=r){
		int mid=l+r>>1,mid2=(mid+r+1)>>1;
		ll up,dow,up2,dow2;
		up=su[m]-su[m-mid-1]+su[n]-su[n-mid];
		dow=2*mid+1;
		up2=su[m]-su[m-mid2-1]+su[n]-su[n-mid2];
		dow2=2*mid2+1;
		if(grea(up,dow,aup,ado)){
			aup=up;
			ado=dow;
			opt=mid;
		}
		if(grea(up2,dow2,aup,ado)){
			aup=up2;
			ado=dow2;
			opt=mid2;
		}
		if(grea(up,dow,up2,dow2)){
			r=mid2-1;
		}else l=mid+1;
	}
	aup-=1ll*ado*a[m];
	if(grea(aup,ado,curup,curdo)){
		curup=aup;
		curdo=ado;
		::opt=m;
		optbo=1;
	}
	if(pri){
		printf("%d\n",2*opt+1);
		for (int i=m-opt;i<=m;i++)printf("%d ",a[i]);
		for (int i=n-opt+1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
}
void work2(int m,bool pri){
	ll aup=0,ado=1;int opt=0;
	int l=0,r=min(m-1,n-m-1);
	while(l<=r){
		int mid=l+r>>1,mid2=(mid+r+1)>>1;
		ll up,dow,up2,dow2;
		up=su[m+1]-su[m-mid-1]+su[n]-su[n-mid];
		dow=2*mid+2;
		up2=su[m+1]-su[m-mid2-1]+su[n]-su[n-mid2];
		dow2=2*mid2+2;
		if(grea(up,dow,aup,ado)){
			aup=up;
			ado=dow;
			opt=mid;
		}
		if(grea(up2,dow2,aup,ado)){
			aup=up2;
			ado=dow2;
			opt=mid2;
		}
		if(grea(up,dow,up2,dow2)){
			r=mid2-1;
		}else l=mid+1;
	}
	aup*=2;ado*=2;	
	aup-=1ll*ado*(a[m]+a[m+1])/2;
	if(grea(aup,ado,curup,curdo)){
		curup=aup;
		curdo=ado;
		::opt=m;
		optbo=2;
	}
	if(pri){
		printf("%d\n",2*opt+2);
		for (int i=m-opt;i<=m+1;i++)printf("%d ",a[i]);
		for (int i=n-opt+1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	gn(n);
	rep(i,1,n+1)gn(a[i]);
	sort(a+1,a+1+n);
	su[0]=0;
	rep(i,1,n+2)su[i]=su[i-1]+a[i];

	for (int i=1;i<=n;i++)work1(i,0);
	for (int i=1;i<n;i++)work2(i,0);

	if(optbo==1)work1(opt,1);
	else work2(opt,2);
	return 0;
}
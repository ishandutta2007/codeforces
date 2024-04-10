#include<stdio.h>
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
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
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
const int inf=0x3f3f3f3f;
const db eps=1e-12;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n;

struct lin{
	int a,b,c;
	db x,y;
	void rd(){
		gn(a);
		gn(b);
		gn(c);
		x=db(a)*c/(a*a+b*b);
		y=db(b)*c/(a*a+b*b);
	}
}a[2222];
db sor[2222];
int to;

db suan(db x,db y){
	if(x<-eps)x*=-1,y*=-1;
	if(x<eps && y<-eps)x*=-1,y*=-1;
	return atan2(y,x);
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1)a[i].rd();

	ll ans=0;
	rep(i,1,n+1){
		to=0;
		rep(j,1,n+1)if(fabs(a[j].x-a[i].x)>eps||fabs(a[j].y-a[i].y)>eps)sor[++to]=suan(a[j].y-a[i].y,a[j].x-a[i].x);
		sort(sor+1,sor+1+to);

		for (int k=1,l;k<=to;k=l){
			for(l=k;l<=to && fabs(sor[l]-sor[k])<eps;l++);
			ans+=(l-k)*(l-k-1)/2;
		}
	}
	rep(i,1,n+1)rep(j,i+1,n+1)if(fabs(a[j].x-a[i].x)<eps && fabs(a[j].y-a[i].y)<eps){
		ans+=2*(n-2);
	}
	cout<<ans/3<<endl;



	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
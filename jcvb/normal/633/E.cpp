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
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


int n,k;
int vi[1111111],ci[1111111];
int an[1111111];


int qu1[1111111],q1;
int qu2[1111111],q2;

int get1(int d){
	if(d==n+1)return inf;
	int l=1,r=q1;
	while(l<=r){
		int mid=l+r>>1;
		if(qu1[mid]<=d)r=mid-1;
		else l=mid+1;
	}
	return vi[qu1[l]];
}
int get2(int d){
	if(d==n+1)return -inf;
	int l=1,r=q2;
	while(l<=r){
		int mid=l+r>>1;
		if(qu2[mid]<=d)r=mid-1;
		else l=mid+1;
	}
	return ci[qu2[l]];
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);
	rep(i,1,n+1)gn(vi[i]),vi[i]*=100;
	rep(i,1,n+1)gn(ci[i]);

	int ptr=n+1;
	for (int i=n;i>=1;i--){
		while(q1>0 && vi[i]>=vi[qu1[q1]])q1--;
		qu1[++q1]=i;
		while(q2>0 && ci[i]<=ci[qu2[q2]])q2--;
		qu2[++q2]=i;

		while(ptr>i){
			int vi2=get1(ptr-1);
			int ci2=get2(ptr-1);
			if(vi2>=ci2)ptr--;
			else break;
		}
		int x1=min(get1(ptr),get2(ptr)),x2=ptr==i?-inf:min(get1(ptr-1),get2(ptr-1));
		an[i]=max(x1,x2);
	}

	sort(an+1,an+1+n);

	db prod=k;
	db su=0.0;

	rep(i,1,n){
		if(i>=2)prod*=(n-k-i+2);
		prod/=(n-i+1);
		su+=an[i]*prod;
	}
	printf("%.10lf\n",su);
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
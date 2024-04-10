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
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n;
db a;
struct pkt{
	db x,y;
}p[111111];
pkt operator-(const pkt&a,const pkt&b){
	return (pkt){a.x-b.x,a.y-b.y};
}

db dis(const pkt&a){
	return sqrt(sqrf(a.x)+sqrf(a.y));
}

pkt lef,rig;

struct node{
	db l,r;
	int id;
}no[555555];int ntot;
int cmp(const node&a,const node&b){
	return a.l<b.l;
}

void inser(db le,db ri,int id){
	no[++ntot]=(node){le,ri,id};
	no[++ntot]=(node){le+2*pi,ri+2*pi,id};
	no[++ntot]=(node){le-2*pi,ri-2*pi,id};
}
multiset<db> se;
bool check(db r){
	ntot=0;
	rep(i,1,n+1){
		db d1=dis(lef-p[i]),d2=dis(p[i]-rig);
		if(d1+r<d2)continue;
		if(d2<abs(d1-r))continue;
		db cost=(sqrf(r)+sqrf(d2)-sqrf(d1))/2/r/d2;
		db t=acos(cost);
		if(t<0.5*pi){
			db mi=atan2((p[i]-rig).y,(p[i]-rig).x);
			inser(mi-t,mi+t,i);
		}else{
			db mi=atan2(-(p[i]-rig).y,-(p[i]-rig).x);
			inser(mi-(pi-t),mi+(pi-t),i);
		}

	}
	//if(ful && ntot>=1)return 1;
	sort(no+1,no+1+ntot,cmp);
	se.clear();
	for (int i=1;i<=ntot;i++){
		set<db>::iterator it=se.upper_bound(no[i].l);
		if(it!=se.end() && *it<no[i].r)return 1;
		se.insert(no[i].r);
	}
	return 0;
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(a);
	rig=(pkt){a,0};
	lef=(pkt){-a,0};
	rep(i,1,n+1)gn(p[i].x),gn(p[i].y);
	db l=0.0,r=2*a,mid;
	rep(_,0,100){
		mid=(l+r)*0.5;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.10lf\n",double(l));
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
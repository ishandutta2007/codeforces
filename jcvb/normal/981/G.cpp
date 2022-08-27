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
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
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
#define forg(i,gu) for (int i=gu;~i;i=e[i].next)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
//const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
const int mo=998244353;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}



// range update, range query
// index 1..n
// first call seginit(n)

typedef int seg_nu;
struct seg_tag{
	int ad;
	int mu;
};
const int SEG_MAXN=200000+5;

int seglen[SEG_MAXN*4];
seg_nu seg[SEG_MAXN*4];
seg_tag tag[SEG_MAXN*4];
seg_tag tag0 = (seg_tag){0,1};						

inline seg_tag operator+(seg_tag old, seg_tag ne) {
	seg_tag c;
	c.mu=1ll*old.mu*ne.mu%mo;
	c.ad=(1ll*old.ad*ne.mu+ne.ad)%mo;
	return c;
}
inline void segadd(int x,seg_tag v){
	seg[x]=(1ll*seg[x]*v.mu + 1ll*v.ad*seglen[x])%mo;	
	tag[x]=tag[x]+v;			
}
inline void segpd(int x){
	if(tag[x].ad!=0 || tag[x].mu!=1){
		segadd(x<<1,tag[x]);
		segadd(x<<1|1,tag[x]);
		tag[x]=tag0;					
	}
}
inline void segpu(int x){
	seg[x]=(seg[x<<1]+seg[x<<1|1])%mo;				
}
void seginit_in(int l,int r,int x){
	tag[x]=tag0;						
	seglen[x]=r-l+1;
	if(l==r){
		seg[x]=0;					
	}else{
		int mid=l+r>>1;
		seginit_in(l,mid,x<<1);
		seginit_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int l1,r1;
seg_nu sans; bool ans_bo;
seg_tag stag;
void segupd_in(int l,int r,int x){
	//if(l1>r1)return;
	if(l1<=l && r<=r1){
		segadd(x,stag);
	}else{
		int mid=l+r>>1;
		segpd(x);
		if(l1<=mid)segupd_in(l,mid,x<<1);
		if(r1>mid)segupd_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
void segque_in(int l,int r,int x){
	//if(l1>r1)return;
	if(l1<=l && r<=r1){
		if(!ans_bo)ans_bo=1,sans=seg[x];
		else sans=(sans+seg[x])%mo;				
	}else{
		int mid=l+r>>1;
		segpd(x);
		if(l1<=mid)segque_in(l,mid,x<<1);
		if(r1>mid)segque_in(mid+1,r,x<<1|1);
	}
}
int segn;
void segupd(int l,int r,seg_tag v){
	if(l>r)return;
	stag=v,l1=l,r1=r;
	segupd_in(1,segn,1);
}
seg_nu segque(int l,int r){
	if(l>r)return 0;					
	ans_bo=0,l1=l,r1=r;
	segque_in(1,segn,1);
	return sans;
}
void seginit(int n){
	segn=n;
	seginit_in(1,segn,1);
}

set<pair<int,int> > se[222222];

seg_tag mu,ad;
void gao(int l,int r,set<pair<int,int> > &se) {
	if(l>r)return;
	auto nex = se.lower_bound(mp(l+1,-100));
	int rr = min(r,nex->fi-1);
	if(nex->se == -1) {
		segupd(l,rr,mu);
	}else segupd(l,rr,ad);
	gao(rr+1,r,se);
}
void shan(int l,int r,set<pair<int,int> >&se) {
	auto nex = se.lower_bound(mp(r+2,-100));
	auto pre = se.upper_bound(mp(l,-100));
	pre--;
	int lefs = pre->se;
	int rigs=nex->se;

	while(1) {
		auto t = se.lower_bound(mp(l,-100));
		if(t->fi>r+1)break;
		se.erase(t);
	}
	if(lefs==-1)se.insert(mp(l,1));
	if(rigs==1)se.insert(mp(r+1,-1));
}
int main()
{
	int n,q;
	gn(n);gn(q);
	seginit(n);
	mu.ad=0;mu.mu=2;
	ad.ad=1;ad.mu=1;
	rep(i,1,n+1){
		se[i].insert(mp(n+2,1));
		se[i].insert(mp(-1,-1));
	}
	while(q--){
		int t;
		gn(t);
		if(t==1){
			int l,r,x;
			gn(l);gn(r);gn(x);
			gao(l,r,se[x]);
			shan(l,r,se[x]);
		}else{
			int l,r;
			gn(l);gn(r);
			printf("%d\n",segque(l,r));
		}
	}
	return 0;
}
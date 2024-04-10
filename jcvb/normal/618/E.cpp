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




// range update, range query
// index 1..n
// first call seginit(n)

void zhuan(db t,db &x,db &y){
	db nx=cos(t)*x-sin(t)*y;
	db ny=sin(t)*x+cos(t)*y;
	x=nx;y=ny;
}
struct data{
	db dt,dx,dy;
};
data operator*(const data&a,const data&b){
	data c=b;
	zhuan(a.dt,c.dx,c.dy);
	c.dx+=a.dx;
	c.dy+=a.dy;
	c.dt+=a.dt;
	if(c.dt>=2*pi)c.dt-=2*pi;
	return c;
}
typedef int seg_nu;
typedef data seg_tag;
const int SEG_MAXN=300000+5;

int seglen[SEG_MAXN*4];
seg_tag tag[SEG_MAXN*4];
seg_tag tag0;						//modify
inline void segadd(int x,seg_tag v){
	tag[x]=v*tag[x];
}
inline void segpd(int x){
	segadd(x<<1,tag[x]);
	segadd(x<<1|1,tag[x]);
	tag[x]=tag0;
}
void seginit_in(int l,int r,int x){
	tag[x]=tag0;						
	seglen[x]=r-l+1;
	if(l==r){
		//seg[x]=a[l];
		tag[x]=(data){0,l*1.0,0};
	}else{
		int mid=l+r>>1;
		seginit_in(l,mid,x<<1);
		seginit_in(mid+1,r,x<<1|1);
	}
}
int l1,r1;
seg_tag sans; bool ans_bo;
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
	}
}
void segque_in(int l,int r,int x){
	//if(l1>r1)return;
	if(l1<=l && r<=r1){
		if(!ans_bo)ans_bo=1,sans=tag[x];
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
seg_tag segque(int l,int r){
	ans_bo=0,l1=l,r1=r;
	segque_in(1,segn,1);
	return sans;
}
void seginit(int n){
	segn=n;
	seginit_in(1,segn,1);
}
int n,m;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif

	gn(n);gn(m);
	seginit(n);

	while(m--){
		int x,y,z;
		gn(x);gn(y);gn(z);
		db x1,y1,x2,y2;
		if(y==1){
			x1=y1=0;
		}else{
			data an=segque(y-1,y-1);
			x1=an.dx,y1=an.dy;
		}
		data an=segque(y,y);
		x2=an.dx,y2=an.dy;

		if(x==1){
			db le=sqrt(sqrf(x1-x2)+sqrf(y1-y2));
			db ra=(z)/le;
			data gao;
			gao=(data){0,(x2-x1)*ra,(y2-y1)*ra};
			segupd(y,n,gao);
		}else{
			db dt=(360-z)*1.0/360*2*pi;

			data gao;
			db x3=-x1,y3=-y1;
			zhuan(dt,x3,y3);
			gao=(data){dt,x3+x1,y3+y1};
			segupd(y,n,gao);
		}
		an=segque(n,n);
		printf("%.10lf %.10lf\n",double(an.dx),double(an.dy));
	}




	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
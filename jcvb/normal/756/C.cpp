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
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
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
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

// single point update, range query
// index 1..n
// first call seginit(n)


int wei[111111];
struct node{
	int a,b;//minu a add b
}zer,pus,po;
node operator+(const node&a,const node&b){
	int x=a.a,y=a.b,z=b.a,w=b.b;
	int de=min(y,z);
	y-=de,z-=de;
	if(y==0)return (node){x+z,w};
	else return (node){x,y+w};
}
typedef node seg_nu;
typedef node seg_tag;
const int SEG_MAXN=100000+5;

seg_nu seg[SEG_MAXN*4];
inline void segpu(int x){
	seg[x]=seg[x<<1]+seg[x<<1|1];				//modify
}
void seginit_in(int l,int r,int x){
	if(l==r){
		seg[x]=zer;					//modify
	}else{
		int mid=l+r>>1;
		seginit_in(l,mid,x<<1);
		seginit_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int l1,r1,I;
seg_nu sans; bool ans_bo;
seg_tag stag;
void segupd_in(int l,int r,int x){
	if(l==r){
		seg[x]=stag;				//modify
	}else{
		int mid=l+r>>1;
		if(I<=mid)segupd_in(l,mid,x<<1);
		else segupd_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
void segque_in(int l,int r,int x){
	//if(l1>r1)return;
	if(l1<=l && r<=r1){
		if(!ans_bo)ans_bo=1,sans=seg[x];
		else sans=sans+seg[x];				//modify
	}else{
		int mid=l+r>>1;
		if(l1<=mid)segque_in(l,mid,x<<1);
		if(r1>mid)segque_in(mid+1,r,x<<1|1);
	}
}
int segn;
void segupd(int i,seg_tag v){
	stag=v,I=i;
	segupd_in(1,segn,1);
}
seg_nu segque(int l,int r){
	ans_bo=0,l1=l,r1=r;
	segque_in(1,segn,1);
	return sans;
}
void seginit(int n){
	segn=n;
	seginit_in(1,segn,1);
}



int que(int l,int r,int x,int id){
	if(l==r)return l;
	else{
		int mid=l+r>>1;
		node lef=seg[x<<1],rig=seg[x<<1|1];

		if(lef.b>=rig.a){
			if(id<=lef.b-rig.a)return que(l,mid,x<<1,id);
			else return que(mid+1,r,x<<1|1,id-(lef.b-rig.a));
		}else{
			return que(mid+1,r,x<<1|1,id);
		}
	}
}
int m;
int ask(){
	node t=seg[1];
	int d=t.b;
	if(d==0)return -1;

	return wei[que(1,m,1,d)];
}
int main()
{
	pus=(node){0,1};
	po=(node){1,0};
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(m);
	seginit(m);
	rep(i,1,m+1){
		int pos;
		int opt;
		gn(pos);gn(opt);
		if(opt==1){
			gn(wei[pos]);
		}
		if(opt==0)segupd(pos,po);
		else segupd(pos,pus);
		printf("%d\n",ask());
	}

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
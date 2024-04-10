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
const int mo=1e9+7;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

// single point update, range query
// index 1..n
// first call seginit(n)
const int N=111111;
vector<int> lis[N];
int inpos[111111];

struct node{
	int ans,cnt,lc,rc,l,r;
};
int L[N],R[N];

node sing(int i,int sg,int id){
	node c;
	c.ans=0;
	c.cnt=sg;
	c.lc=c.rc=0;
	c.l=L[lis[id][i-1]]*sg;
	c.r=R[lis[id][i-1]]*sg;
	return c;
}
node operator+(const node&a,const node&b){
	node c;
	c.cnt=(a.cnt+b.cnt);
	c.ans=(1ll*a.l*b.rc+1ll*a.lc*b.r+a.ans+b.ans)%mo;
	c.l=(a.l+b.l)%mo;
	c.r=(a.r+b.r)%mo;
	c.lc=(0ll+b.lc+a.lc+1ll*a.l*b.cnt)%mo;
	c.rc=(0ll+a.rc+b.rc+1ll*b.r*a.cnt)%mo;
	return c;
}


typedef node seg_nu;
typedef int seg_tag;
const int SEG_MAXN=100000+5;

int curid;
node buf[1111111];int curptr=0;
node* head[111111],*seg;
inline void segpu(int x){
	seg[x]=seg[x<<1]+seg[x<<1|1];				//modify
}
void seginit_in(int l,int r,int x){
	if(l==r){
		seg[x]=sing(l,1,curid);
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
		seg[x]=sing(l,stag,curid);
		//seg[x]=seg[x]+stag;				//modify
	}else{
		int mid=l+r>>1;
		if(I<=mid)segupd_in(l,mid,x<<1);
		else segupd_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int segn;
void segupd(int i,seg_tag v){
	stag=v,I=i;
	segupd_in(1,segn,1);
}
void seginit(int n){
	segn=n;
	seginit_in(1,segn,1);
}


int a[N];
map<int,int> ma;
int tot=0;
int bit[N];
void bitupd(int x,int del){
	for (;x<=tot;x+=x&-x)bit[x]+=del;
}
int bitque(int x){
	int ans=0;
	for (;x;x-=x&-x)ans+=bit[x];
	return ans;
}

int nowans=0;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	int n;gn(n);
	rep(i,1,n+1){
		gn(a[i]);
		ma[a[i]];
	}
	foreach(it,ma)it->se=++tot;

	rep(i,1,n+1){
		a[i]=ma[a[i]];
		lis[a[i]].pb(i);
		inpos[i]=lis[a[i]].size();
	}

	rep(i,1,n+1){
		L[i]=bitque(a[i]);
		bitupd(a[i],1);
	}
	cl(bit);
	per(i,1,n+1){
		R[i]=bitque(a[i]);
		bitupd(a[i],1);
	}
	rep(i,1,tot+1){
		head[i]=buf+curptr;
		curptr+=(siz(lis[i])+1)*4;
	}
	rep(i,1,tot+1){
		curid=i;
		seg=head[i];
		segn=siz(lis[i]);
		seginit(segn);
		upmo(nowans,seg[1].ans);
	}

	int m;gn(m);
	while(m--){
		int t,x;gn(t);gn(x);
		t--;

		curid=a[x];
		seg=head[curid];
		segn=siz(lis[curid]);
		upmo(nowans,-seg[1].ans);
		segupd(inpos[x],t);
		upmo(nowans,seg[1].ans);
		printf("%d\n",nowans);
	}
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
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
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


int fi[33333];
int seq[33333];


// single point update, range query
// index 1..n
// first call seginit(n)

typedef int seg_nu;
typedef int seg_tag;
const int SEG_MAXN=100000+5;

seg_nu seg[SEG_MAXN*4],seg1[SEG_MAXN*4];
int num[SEG_MAXN*4];
inline void segpu(int x){
	num[x]=num[x<<1]+num[x<<1|1];
	if(num[x<<1]){
		seg[x]=(seg[x<<1]+1ll*fi[num[x<<1]-1]*seg[x<<1|1] + 1ll* fi[num[x<<1]]*seg1[x<<1|1])%mo;
		seg1[x]=(seg1[x<<1]+1ll*fi[num[x<<1]]*seg[x<<1|1] + 1ll* fi[num[x<<1]+1]*seg1[x<<1|1])%mo;
	}else{
		seg[x]=seg[x<<1|1];
		seg1[x]=seg1[x<<1|1];
	}
}
void seginit_in(int l,int r,int x){
	if(l==r){
		//seg[x]=a[l];
		seg[x]=seg1[x]=0;					//modify
		num[x]=0;
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
		seg[x]=0,seg1[x]=stag*seq[l];
		num[x]=stag;
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



int n;
int ai[33333];
map<int,int>ma;
struct Q{
	int l,r,id;
}que[33333];int q;
int tot=0;
int SZ=200;
int cmp(const Q&a,const Q&b){
	if(a.l/SZ==b.l/SZ)return a.r<b.r;
	else return a.l<b.l;
}

int cl,cr;
int cnt[33333];
int out[33333];


void upd(int id,int del){
	if(cnt[id]==0 && del==1){
		segupd(id,1);

	}else if(cnt[id]==1 && del==-1){
		segupd(id,0);

	}
	cnt[id]+=del;
}
void gaol(int l){
	while(cl>l){
		cl--;
		upd(ai[cl],1);
	}
	while(cl<l){
		upd(ai[cl],-1);
		cl++;
	}
}
void gaor(int r){
	while(cr<r){
		cr++;
		upd(ai[cr],1);
	}
	while(cr>r){
		upd(ai[cr],-1);
		cr--;
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(mo);
	fi[0]=0;fi[1]=1%mo;
	rep(i,2,30010)fi[i]=(fi[i-1]+fi[i-2])%mo;

	rep(i,1,n+1){
		gn(ai[i]);
		ma[ai[i]];
	}
	foreach(i,ma)seq[i->se=++tot]=(i->fi)%mo;
	rep(i,1,n+1)ai[i]=ma[ai[i]];
	gn(q);
	rep(i,1,q+1)gn(que[i].l),gn(que[i].r),que[i].id=i;

	sort(que+1,que+1+q,cmp);

	seginit(tot);

	cl=1,cr=0;

	rep(i,1,q+1){
		if(cl>que[i].r)gaol(que[i].l),gaor(que[i].r);
		else gaor(que[i].r),gaol(que[i].l);
		out[que[i].id]=seg1[1];
	}
	rep(i,1,q+1)printf("%d\n",out[i]);
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
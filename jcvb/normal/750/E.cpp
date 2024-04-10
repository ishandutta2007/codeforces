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
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// single point update, range query
// index 1..n
// first call seginit(n)

char s[222222];

struct node{
	int f[5][5];
}inn;
typedef node seg_nu;
typedef int seg_tag;
const int SEG_MAXN=200000+5;

seg_nu seg[SEG_MAXN*4];

int get(char c){
	if(c=='2')return 1;
	else if(c=='0')return 2;
	else if(c=='1')return 3;
	else if(c=='6')return 4;
	else return 0;
}
node inis(char c){
	int ind=get(c);
	node ret;
	rep(i,0,5)rep(j,0,5){
		if(i>j)ret.f[i][j]=inf;
		else{
			if(ind==i+1){
				if(j==i)ret.f[i][j]=1;
				else if(j==ind)ret.f[i][j]=0;
				else ret.f[i][j]=inf;
			}else{
				if(j==i)ret.f[i][j]=0;
				else ret.f[i][j]=inf;
			}
		}
	}
	return ret;
}
node operator+(const node&a,const node&b){
	node c=inn;
	rep(i,0,5)rep(j,0,5)rep(k,i,j+1){
		upmin(c.f[i][j],a.f[i][k]+b.f[k][j]);
	}
	return c;
}
inline void segpu(int x){
	seg[x]=seg[x<<1]+seg[x<<1|1];				//modify
}
void seginit_in(int l,int r,int x){
	if(l==r){
		seg[x]=inis(s[l]);
		//seg[x]=0;					//modify
	}else{
		int mid=l+r>>1;
		seginit_in(l,mid,x<<1);
		seginit_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int l1,r1,I;
seg_nu sans; bool ans_bo;
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
seg_nu segque(int l,int r){
	if(l>r)return inn;					//modify
	ans_bo=0,l1=l,r1=r;
	segque_in(1,segn,1);
	return sans;
}
void seginit(int n){
	segn=n;
	seginit_in(1,segn,1);
}


int n;

int las7[222222];
int cnt6[222222];


int main()
{
	rep(i,0,5)rep(j,0,5)inn.f[i][j]=inf;
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	int q;
	gn(n);gn(q);
	gs(s+1);
	rep(i,1,n+1){
		if(s[i]=='7')las7[i]=i;
		else las7[i]=las7[i-1];
	}
	rep(i,1,n+1){
		if(s[i]=='6')cnt6[i]=cnt6[i-1]+1;
		else cnt6[i]=cnt6[i-1];
	}

	seginit(n);
	while(q--){
		int l,r;
		gn(l);gn(r);
		int pos7=las7[r];
		if(pos7<l){
			printf("-1\n");
			continue;
		}
		int ans=cnt6[r]-cnt6[pos7];
		node ret=segque(l,pos7);
		int an=ret.f[0][3];
		if(an>=inf){
			printf("-1\n");
		}else{
			printf("%d\n",ans+an);
		}
	}
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
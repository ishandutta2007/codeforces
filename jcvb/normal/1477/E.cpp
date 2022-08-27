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
//const int inf=0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

namespace myrand{
	// rand : [0,2^31)
	// randint : [-2^31,2^31)
	// randll : [-2^63,2^63)
	// randbit : 0,1
	unsigned int x[5]={107896582, 1107972621, 1195573091, 1224749359, 241825441};
	unsigned int get16(){
		unsigned long long tmp=(107374182ll*x[0]+104480ll*x[4]);
		unsigned int res=(tmp>>31)+(tmp&0x7fffffffu);
		x[0]=x[1],x[1]=x[2],x[2]=x[3],x[3]=x[4];
		return x[4]=res>=2147483647?res-2147483647:res;
	}
	void mysrand(unsigned int seed){
		for (int i=0;i<5;i++) seed=(seed+1)%2147483647,x[i]=seed;
		for (int i=0;i<5;i++) get16();
	}
	int randint(){
		int res=0;
		res+=int(get16());
		res+=int(get16())<<16;
		return res;
	}
	long long randll(){
		long long res=0;
		res+=(long long)(get16());
		res+=(long long)(get16())<<16;
		res+=(long long)(get16())<<32;
		res+=(long long)(get16())<<48;
		return res;
	}
	int randbit(){
		return ((get16())>>7)&1;
	}
	int myrand(){
		int x=randint();
		if(x<0)return ~x;
		return x;
	}
	template<typename RandomAccessIterator>void my_randomshuffle(RandomAccessIterator first,RandomAccessIterator last){
		int n=last-first;
		for (int i=1;i<n;i++){
			int to=myrand()%(i+1);
			swap(first[to],first[i]);
		}
	}
#define rand myrand::myrand
#define srand myrand::mysrand
#define random_shuffle myrand::my_randomshuffle
};


//
// first call treap_init()
// operator<(const treap_key&a,const treap_key&b) defined
// 
// empty treap: root=0
// ins(root,v) insert v into treap root, return nodeid
// del(root,v) delete one copy of v from treap root, return nodeid (0 if not found)
// rankhi(root,v) #<=v
// ranklo(root,v) #<v
// count(root,v) #==v
// pred(root,v) max (<v) or minf
// succ(root,v) min (>v) or pinf
// prede(root,v) max (<=v) or minf
// succe(root,v) min (>=v) or pinf
// kth(root,k) kth smallest (1<=k<=t[root].sz)

const int TREAP_MAXN=2000000+5;
typedef int treap_key;
treap_key pinf=0x3f3f3f3f,minf=-0x3f3f3f3f;

struct node{
	int ch[2],fix;
	treap_key v;
	int sz;
	ll su;
}t[TREAP_MAXN],emptynode;
int pool[TREAP_MAXN];int ndtot;
int newnode(){
	int x=pool[++ndtot];
	t[x]=emptynode;
	return x;
}
void freenode(int x){
	pool[ndtot--]=x;
}
inline void pu(int x){
	t[x].sz=t[t[x].ch[0]].sz+t[t[x].ch[1]].sz+1;
	t[x].su=t[t[x].ch[0]].su+t[t[x].ch[1]].su+t[x].v;
}
void rot(int &x,int f){
	int y=t[x].ch[!f];
	t[x].ch[!f]=t[y].ch[f];
	t[y].ch[f]=x;
	pu(x);
	x=y;
}
int ins(int &x,treap_key v){
	if(x==0){
		x=newnode();
		t[x].ch[0]=t[x].ch[1]=0;
		t[x].v=v;
		t[x].fix=rand();

		t[x].sz=1;
		t[x].su=t[x].v;
		return x;
	}else{
		int f=!(v<t[x].v);
		int ret=ins(t[x].ch[f],v);
		if(t[t[x].ch[f]].fix<t[x].fix)rot(x,!f);
		pu(x);
		return ret;
	}
}
int del(int &x,treap_key v){
	if(!x)return 0;
	if(!(t[x].v<v) && !(v<t[x].v)){
		if(!t[x].ch[0] && !t[x].ch[1]){
			int ret=x;
			freenode(x);
			x=0;
			return ret;
		}else{
			int f=!t[x].ch[0] || (t[x].ch[1]&&t[t[x].ch[1]].fix<t[t[x].ch[0]].fix);
			rot(x,!f);
			int ret=del(t[x].ch[!f],v);
			pu(x);
			return ret;
		}
	}else{
		int f=!(v<t[x].v);
		int ret=del(t[x].ch[f],v);
		pu(x);
		return ret;
	}
}
int ranklo(int x,treap_key v){
	int ans=0;
	while(x){
		if(!(t[x].v<v))x=t[x].ch[0];
		else{
			ans+=t[t[x].ch[0]].sz+1;
			x=t[x].ch[1];
		}
	}
	return ans;
}
int rankhi(int x,treap_key v){
	int ans=0;
	while(x){
		if(v<t[x].v)x=t[x].ch[0];
		else{
			ans+=t[t[x].ch[0]].sz+1;
			x=t[x].ch[1];
		}
	}
	return ans;
}
ll sumhi(int x,treap_key v){
	ll ans=0;
	while(x){
		if(v<t[x].v)x=t[x].ch[0];
		else{
			ans+=t[t[x].ch[0]].su+t[x].v;
			x=t[x].ch[1];
		}
	}
	return ans;
}
int count(int x,treap_key v){
	return rankhi(x,v)-ranklo(x,v);
}
treap_key pred(int x,treap_key v){
	treap_key y=minf;
	while(x){
		if(t[x].v<v){
			y=t[x].v;
			x=t[x].ch[1];
		}else x=t[x].ch[0];
	}
	return y;
}
treap_key succ(int x,treap_key v){
	treap_key y=pinf;
	while(x){
		if(v<t[x].v){
			y=t[x].v;
			x=t[x].ch[0];
		}else x=t[x].ch[1];
	}
	return y;
}
treap_key prede(int x,treap_key v){
	treap_key y=minf;
	while(x){
		if(!(v<t[x].v)){
			y=t[x].v;
			x=t[x].ch[1];
		}else x=t[x].ch[0];
	}
	return y;
}
treap_key succe(int x,treap_key v){
	treap_key y=pinf;
	while(x){
		if(!(t[x].v<v)){
			y=t[x].v;
			x=t[x].ch[0];
		}else x=t[x].ch[1];
	}
	return y;
}
treap_key kth(int x,int k){
	while(1){
		if(t[t[x].ch[0]].sz+1==k)return t[x].v;
		else if(k<=t[t[x].ch[0]].sz)x=t[x].ch[0];
		else{
			k-=t[t[x].ch[0]].sz+1;
			x=t[x].ch[1];
		}
	}
}
void treap_init(){
	static bool ini=0;
	if(!ini){
		ini=1;
		for (int i=1;i<TREAP_MAXN;i++)pool[i]=i;
		ndtot=0;
	}else{
		ndtot=0;
	}
}

const int N = 555555;
int n,m,q;
int ai[N],bi[N];
int rta=0,rtb=0;


ll suan(int A,int X,int c) {
	int mi = min(kth(rta,1),kth(rtb,1));
	ll my = 1ll*max(0,A-X-mi)*(n-c);
	ll his = 1ll*(A-X)*rankhi(rtb,A-X) - sumhi(rtb,A-X);
	return my-his+1ll*(X-A)*(n-m);
}
ll gao(int X) {
	int go;
	//if(m<=n) go = 1e8;
	//else go = kth(rtb,n);

	go = 1e8;
	go+=X;

	ll maxgain=-inf;

	int trya;
	trya=prede(rta,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,1));
	trya=succ(rta,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,1));

	trya=prede(rtb,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,0));
	trya=succ(rtb,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,0));

	go = kth(rtb,max(1,m-1));
	//go = 1e8;
	go+=X;

	trya=prede(rta,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,1));
	trya=succ(rta,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,1));
	trya=prede(rtb,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,0));
	trya=succ(rtb,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,0));

	go = kth(rtb,max(1,m));
	//go = 1e8;
	go+=X;

	trya=prede(rta,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,1));
	trya=succ(rta,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,1));
	trya=prede(rtb,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,0));
	trya=succ(rtb,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,0));
	go = kth(rtb,max(1,m-n));
	//go = 1e8;
	
	go+=X;

	trya=prede(rta,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,1));
	trya=succ(rta,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,1));
	trya=prede(rtb,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,0));
	trya=succ(rtb,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,0));

	go = kth(rtb,1);
	//go = 1e8;
	go+=X;

	trya=prede(rta,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,1));
	trya=succ(rta,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,1));
	trya=prede(rtb,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,0));
	trya=succ(rtb,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,0));

	go = kth(rta,1);
	//go = 1e8;

	trya=prede(rta,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,1));
	trya=succ(rta,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,1));
	trya=prede(rtb,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,0));
	trya=succ(rtb,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,0));
	go = kth(rtb,1);
	//go = 1e8;

	trya=prede(rta,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,1));
	trya=succ(rta,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,1));
	trya=prede(rtb,go);
	if(trya!=minf) upmax(maxgain,suan(trya,X,0));
	trya=succ(rtb,go);
	if(trya!=pinf) upmax(maxgain,suan(trya,X,0));
	return t[rta].su - t[rtb].su + maxgain;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	treap_init();
	srand(19283746);
	gn(n);gn(m);gn(q);
	rep(i,1,n+1){
		gn(ai[i]);
		ins(rta,ai[i]);
	}
	rep(i,1,m+1){
		gn(bi[i]);
		ins(rtb,bi[i]);
	}
	while(q--){
		int opt;gn(opt);
		if(opt==3) {
			int X;gn(X);
			printf(lld"\n",gao(X));
		}else {
			int i,x;
			gn(i);gn(x);
			int old;
			if(opt==1) {
				old=ai[i];
				ai[i]=x;
				del(rta,old);
				ins(rta,x);
			}else if(opt==2) {
				old=bi[i];
				bi[i]=x;
				del(rtb,old);
				ins(rtb,x);
			}
		}
	}


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
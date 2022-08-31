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
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}


// empty node = 0
// remember to set data of node 0
// subsum of v

const int LCT_MAXV=400000+5;
struct node{
	int pre,up,ch[2],fl;
	int v;
	int sz,sb,susb;
	ll ti;
	ll ma;
}t[LCT_MAXV];
void fl(int x){
	if(x){
		swap(t[x].ch[0],t[x].ch[1]);
		t[x].fl^=1;
	}
}
void pu(int x){
	t[x].sz=t[t[x].ch[0]].sz+t[t[x].ch[1]].sz+t[x].v;
	t[x].susb=t[t[x].ch[0]].susb+t[t[x].ch[1]].susb+t[x].sb;
	t[x].ma=max(max(t[t[x].ch[0]].ma,t[t[x].ch[1]].ma),t[x].ti);
}
void pd(int x){
	if(t[x].fl){
		fl(t[x].ch[0]);fl(t[x].ch[1]);t[x].fl=0;
	}
}
void rot(int x){
	int y=t[x].pre;t[x].up=t[y].up;
	int f=t[y].ch[0]==x;
	t[y].ch[!f]=t[x].ch[f];t[t[x].ch[f]].pre=y;
	t[x].pre=t[y].pre;t[t[x].pre].ch[t[t[x].pre].ch[1]==y]=x;
	t[x].ch[f]=y;t[y].pre=x;
	pu(y);
}
void allpd(int x){
	if(t[x].pre)allpd(t[x].pre);
	pd(x);
}
void spl(int x){
	allpd(x);int y;
	while(y=t[x].pre){
		if(!t[y].pre)rot(x);
		else{
			int f=t[t[y].pre].ch[1]==y;
			if(t[y].ch[f]==x)rot(y),rot(x);
			else rot(x),rot(x);
		}
	}
	pu(x);
}
int acc(int x){
	int y=0;
	for(;x;y=x,x=t[x].up){
		spl(x);
		t[t[x].ch[1]].pre=0;
		t[t[x].ch[1]].up=x;
		t[x].sb+=t[t[x].ch[1]].sz+t[t[x].ch[1]].susb;
		t[x].ch[1]=y;
		t[x].sb-=t[y].sz+t[y].susb;
		t[y].pre=x;
		pu(x);
	}
	return y;
}
int gr(int x){
	x=acc(x);
	while(t[x].ch[0]){
		x=t[x].ch[0];
		pd(x);
	}
	spl(x);
	return x;
}
int mr(int x){
	x=acc(x);
	fl(x);
	return x;
}
void lk(int x,int y){
	acc(x);spl(x);
	t[y=mr(y)].up=x;
	t[x].sb+=t[y].susb+t[y].sz;
	t[x].susb+=t[y].susb+t[y].sz;
}
void cut(int x,int y){
	mr(x);acc(y);spl(x);
	t[y].pre=t[y].up=0;
	t[x].ch[1]=0;pu(x);
}
int subsum(int rt,int x){
	mr(rt);
	acc(x);
	return t[x].sb+t[x].v;
}
int n,m;
struct ed{
	int u,v,w;
	ll wei;
}e[333333];
set<ll>se;
int tot;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	tot=n;

	rep(i,1,n+1)t[i].v=t[i].sz=1;
	rep(i,1,m+1){
		int u,v,w;
		gn(u);
		gn(v);
		gn(w);
		e[i]=(ed){u,v,w,(1ll*w)<<25|i};

		t[i+n].ti=t[i+n].ma=e[i].wei;

		if(gr(u)==gr(v)){
			ll ma=t[mr(u),acc(v)].ma;
			if(e[i].wei<ma){
				int eid=ma&((1<<25)-1);
				cut(eid+n,e[eid].u);
				cut(eid+n,e[eid].v);
				se.erase(ma);
				lk(i+n,e[i].u);
				lk(i+n,e[i].v);
				se.insert(e[i].wei);
			}
		}else{
			int su=subsum(u,u);
			int sv=subsum(v,v);
			if((su&1) && (sv&1))tot-=2;
			lk(i+n,e[i].u);
			lk(i+n,e[i].v);
			se.insert(e[i].wei);
		}

		if(tot)printf("-1\n");
		else{
			while(1){
				ll ma=*se.rbegin();
				int eid=ma&((1<<25)-1);
				if(!(subsum(eid+n,e[eid].u)&1) && !(subsum(eid+n,e[eid].v)&1)){
					cut(eid+n,e[eid].u);
					cut(eid+n,e[eid].v);
					se.erase(ma);
				}else break;
			}
			printf("%d\n",int(*se.rbegin()>>25));
		}
	}
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
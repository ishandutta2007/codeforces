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

const int LCT_MAXV=10000000+5;
struct node{
	int pre,up,ch[2],fl;
	bool ed,sz;
	int ti,mi;
}t[LCT_MAXV];int ndtot=0;
void fl(int x){
	if(x){
		swap(t[x].ch[0],t[x].ch[1]);
		t[x].fl^=1;
	}
}
void pu(int x){
	t[x].sz=t[t[x].ch[0]].sz^t[t[x].ch[1]].sz^t[x].ed;
	t[x].mi=min(min(t[t[x].ch[0]].mi,t[t[x].ch[1]].mi),t[x].ti);
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
		t[x].ch[1]=y;
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
	t[mr(y)].up=x;
}
void cut(int x,int y){
	mr(x);acc(y);spl(x);
	t[y].pre=t[y].up=0;
	t[x].ch[1]=0;pu(x);
}

int n,m,k,q;
int ui[555555],vi[555555];
int on[555555];
struct quer{int eid,col;}qu[555555];
int back[555555];
int nex[555555];
int pos[555555];

map<pii,int>mav;

int curc[555555];
int getv(int co,int ui){
	int x;
	if(mav[mp(co,ui)])x=mav[mp(co,ui)];
	else {
		x=mav[mp(co,ui)]=++ndtot;
		t[x].mi=t[x].ti=inf;
	}
	return x;
}
void jiabian(int ei,int nu,int nv,int ne,int co){
	if(gr(nu)==gr(nv)){
		int mi=t[mr(nu),acc(nv)].mi;
		if(ne>mi){
			int alei=qu[back[mi]].eid;
			int alui=getv(co,ui[alei]);
			int alvi=getv(co,vi[alei]);
		
			cut(alei,alui);cut(alei,alvi);
			on[alei]=0;

			t[ei].mi=t[ei].ti=ne;
			on[ei]=1;
			lk(nu,ei);
			lk(nv,ei);
		}
	}else{
		t[ei].mi=t[ei].ti=ne;
		on[ei]=1;
		lk(nu,ei);
		lk(nv,ei);
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	t[0].mi=inf;
	gn(n);gn(m);gn(k);gn(q);
	rep(i,1,m+1)gn(ui[i]),gn(vi[i]);
	rep(i,1,q+1)gn(qu[i].eid),gn(qu[i].col);
	rep(i,1,m+1)pos[i]=q+1;

	per(i,1,q+1){
		nex[i]=pos[qu[i].eid];
		pos[qu[i].eid]=i;
	}
	rep(i,1,q+1)back[nex[i]]=i;
	
	ndtot=m;
	rep(i,1,m+1)t[i].ed=t[i].sz=1;
	rep(i,1,q+1){
		int ei=qu[i].eid;
		int co=qu[i].col;
		int o=curc[ei];

		int nu=getv(co,ui[ei]);
		int nv=getv(co,vi[ei]);

		if((gr(nu)==gr(nv)) && !t[mr(nu),acc(nv)].sz){
			printf("NO\n");
			if(o){
				if(on[ei]){
					cut(ei,getv(o,ui[ei]));
					cut(ei,getv(o,vi[ei]));
					on[ei]=0;
				}
				jiabian(ei,getv(o,ui[ei]),getv(o,vi[ei]),nex[i],o);
			}
		}else{
			printf("YES\n");
			if(o && on[ei]){
				int ou=getv(o,ui[ei]);
				int ov=getv(o,vi[ei]);
				cut(ou,ei);
				cut(ov,ei);
				on[ei]=0;
			}
			curc[ei]=co;
			jiabian(ei,nu,nv,nex[i],co);
		}
	}

	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
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

int h,w,n;


map<int,int> uback;
struct ban{
	int u,l,r,s,id;
	void read(){
		gn(u);gn(l);gn(r);gn(s);
	}
}b[111111];
int cmpuh(const ban&a,const ban&b){
	return a.u+a.s<b.u+b.s;
}
int cmph(const ban&a,const ban&b){
	return a.u<b.u;
}

map<pii,int> ans;
struct query{
	int h,c;
}ques[333333];

int cmpqh(const query&a,const query&b){
	return a.h<b.h;
}
int q=0;

set<int> seg[444444];
int l1,r1,v;
int I;int ret;
void upd(int l,int r,int x){
	if(l1<=l && r<=r1)seg[x].insert(v);
	else{
		int mid=l+r>>1;
		if(l1<=mid)upd(l,mid,x<<1);
		if(r1>mid)upd(mid+1,r,x<<1|1);
	}
}
//!!!!let ret=0
void ask(int l,int r,int x){
	auto it=seg[x].lower_bound(v);
	if(it!=seg[x].begin()){
		it--;
		upmax(ret,*it);
	}
	if(l!=r){
		int mid=l+r>>1;
		if(I<=mid)ask(l,mid,x<<1);
		else ask(mid+1,r,x<<1|1);
	}
}


int wei[111111];
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(h);gn(w);gn(n);

	rep(i,1,n+1){
		b[i].read();
		b[i].id=i;
		uback[b[i].u]=i;
	}
	uback[0]=0;

	rep(i,1,w+1){
		ques[++q]=(query){h+1,i};
	}
	rep(i,1,n+1){
		if(b[i].r!=w)ques[++q]=(query){b[i].u,b[i].r+1};
		if(b[i].l!=1)ques[++q]=(query){b[i].u,b[i].l-1};
	}
	sort(b+1,b+1+n,cmpuh);
	reverse(b+1,b+1+n);
	sort(ques+1,ques+1+q,cmpqh);
	reverse(ques+1,ques+1+q);

	int cur=1;
	rep(i,1,q+1){
		while(cur<=n && b[cur].u+b[cur].s>=ques[i].h){
			l1=b[cur].l,r1=b[cur].r,v=b[cur].u;
			upd(1,w,1);
			cur++;
		}
		ret=0;
		I=ques[i].c;
		v=ques[i].h;
		ask(1,w,1);
		ans[mp(ques[i].h,ques[i].c)]=uback[ret];
		//debug("%d %d %d\n",ques[i].h,ques[i].c,uback[ret]);
	}

	wei[0]=1;

	sort(b+1,b+1+n,cmph);
	rep(i,1,n+1){
		int lque=-1,rque=-1;
		if(b[i].r!=w)rque=ans[mp(b[i].u,b[i].r+1)];
		if(b[i].l!=1)lque=ans[mp(b[i].u,b[i].l-1)];

		if(lque==-1)wei[b[i].id]=2*wei[rque]%mo;
		else if(rque==-1)wei[b[i].id]=2*wei[lque]%mo;
		else wei[b[i].id]=(wei[lque]+wei[rque])%mo;
	}
	int out=0;
	rep(i,1,w+1){
		int ge=ans[mp(h+1,i)];
		upmo(out,wei[ge]);
	}
	printf("%d\n",out);

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
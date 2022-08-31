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

int n;


int bo=0;
int get(int x1,int y1,int x2,int y2){

	static int tmp=0;
	++tmp;
	if(tmp>200)gettle();
	if(bo==0);
	else if(bo==1){
		x1=n-x1+1;
		y1=n-y1+1;
		x2=n-x2+1;
		y2=n-y2+1;
	}else if(bo==2){
		swap(x1,y1);swap(x2,y2);
	}else if(bo==3){
		swap(x1,y1);swap(x2,y2);
		x1=n-x1+1;
		y1=n-y1+1;
		x2=n-x2+1;
		y2=n-y2+1;
	}

	if(x1>x2)swap(x1,x2);
	if(y1>y2)swap(y1,y2);
	if(!(x1>=1 && x2<=n && y1>=1 && y2<=n && x1<=x2 && y1<=y2))gettle();
		printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int x;gn(x);
	return x;
}

int boo=0;
set<pair<pii,pii> > ans;
void work(){
	int l,r;

	l=2,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(get(1,mid,n,n))l=mid+1;
		else r=mid-1;
	}

	int lef=r;

	l=1,r=n-1;
	while(l<=r){
		int mid=l+r>>1;
		if(get(1,lef,mid,n))r=mid-1;
		else l=mid+1;
	}

	int up=l;


	l=2,r=up;
	while(l<=r){
		int mid=l+r>>1;
		if(get(mid,lef,up,n))l=mid+1;
		else r=mid-1;
	}

	int down=r;

	l=lef,r=n-1;
	while(l<=r){
		int mid=l+r>>1;
		if(get(down,lef,up,mid))r=mid-1;
		else l=mid+1;
	}
	int rig=l;



	if(bo==0 && (lef==1 || !get(1,1,n,lef-1))){
		boo=1;
	}
	if(bo==0){

	}else if(bo==1){
		down=n-down+1;
		lef=n-lef+1;
		up=n-up+1;
		rig=n-rig+1;
	}else if(bo==2){

		swap(down,lef);
		swap(rig,up);
	}else if(bo==3){
		swap(down,lef);
		swap(rig,up);
		down=n-down+1;
		lef=n-lef+1;
		up=n-up+1;
		rig=n-rig+1;
	}
	if(down>up)swap(down,up);
	if(lef>rig)swap(lef,rig);
	ans.insert(mp(mp(down,lef),mp(up,rig)));
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);


	work();


	if(ans.size()==2){
		goto lb;
	}

	if(!boo){
	bo=1;

	work();
	if(ans.size()==2){
		goto lb;
	}
	}
	bo=2;

	work();
	if(ans.size()==2){
		goto lb;
	}
	bo=3;

	work();


lb:
if(ans.size()!=2)gettle();
	bo=0;
	/*assert(get(ans[0].fi.fi,ans[0].fi.se,ans[0].se.fi,ans[0].se.se)==1);
	assert(get(ans[1].fi.fi,ans[1].fi.se,ans[1].se.fi,ans[1].se.se)==1);*/

	printf("!");

	auto xxx=*ans.begin();
	ans.erase(xxx);
	auto yyy=*ans.begin();
	printf(" %d %d %d %d %d %d %d %d\n",xxx.fi.fi,xxx.fi.se,xxx.se.fi,xxx.se.se,yyy.fi.fi,yyy.fi.se,yyy.se.fi,yyy.se.se);
	printf("\n");
	fflush(stdout);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
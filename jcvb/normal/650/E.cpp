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

#define N 555555
int n;
struct ed{
	int x,y;
}ea[N],eb[N];
int dont[N];
map<pii,int>mae;
////////////////////
//
struct node{
	int pre,up,ch[2],fl;
	int v,ma;
}t[N*3];
void fl(int x){
	swap(t[x].ch[0],t[x].ch[1]);
	t[x].fl^=1;
}
void pu(int x){
	t[x].ma=max(max(t[t[x].ch[0]].ma,t[t[x].ch[1]].ma),t[x].v);
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
		if(!t[y].pre){
			rot(x);
		}else{
			int f=t[t[y].pre].ch[1]==y;
			if(t[y].ch[f]==x){
				rot(y);rot(x);
			}else{
				rot(x);rot(x);
			}
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
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n){
		gn(ea[i].x);gn(ea[i].y);
		if(ea[i].x>ea[i].y)swap(ea[i].x,ea[i].y);
		mae[mp(ea[i].x,ea[i].y)]=1;
	}
	int nu=n-1;
	rep(i,1,n){
		gn(eb[i].x);gn(eb[i].y);
		if(eb[i].x>eb[i].y)swap(eb[i].x,eb[i].y);
		if(mae.count(mp(eb[i].x,eb[i].y))){
			dont[i]=1,nu--;
			mae[mp(eb[i].x,eb[i].y)]=2;
		}
	}

	rep(i,1,n){
		if(mae[mp(ea[i].x,ea[i].y)]==1)
			t[n+i].v=t[n+i].ma=i;
		lk(ea[i].x,n+i);
		lk(n+i,ea[i].y);
	}


	printf("%d\n",nu);
	rep(i,1,n)if(!dont[i]){
		int u=eb[i].x,v=eb[i].y;
		mr(u);
		int x=acc(v);

		int id=t[x].ma;

		printf("%d %d %d %d\n",ea[id].x,ea[id].y,u,v);

		cut(ea[id].x,id+n);
		cut(ea[id].y,id+n);

		lk(u,i+n+n);
		lk(v,i+n+n);
	}

	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
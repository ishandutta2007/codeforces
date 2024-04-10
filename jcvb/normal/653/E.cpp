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

int n,m,k;
int ui[333333],vvi[333333];

vi ad[333333];

int fa[333333];int cnt;
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
void un(int x,int y){
	x=gf(x);y=gf(y);
	if(x==y)return;
	if(x>y)swap(x,y);
	fa[x]=y;
	cnt--;
}
void comb(int l,int r){
	if(l>r)return;
	l=gf(l);
	r=gf(r);
	while(l<r){
		un(l,l+1);
		l=gf(l);
	}
}

void gao(int l,int r,int u){
	if(l>r)return;
	un(l,u);
}
int gao(int star){
	rep(i,star,n+1)fa[i]=i;
	cnt=n-star+1;

	for (int u=star;u<=n;u++){
		int las=star;
		for (int i=0;i<siz(ad[u]);i++){
			int v=ad[u][i];
			if(v<star)continue;
			comb(las,v-1);
			las=v+1;
		}
		comb(las,n);
	}
	for (int u=star;u<=n;u++){
		int las=star;
		for (int i=0;i<siz(ad[u]);i++){
			int v=ad[u][i];
			if(v<star)continue;
			gao(las,v-1,u);
			las=v+1;
		}
		gao(las,n,u);
	}
	return cnt;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);gn(k);
	int deg1=n-1;
	rep(i,1,m+1){
		gn(ui[i]);
		gn(vvi[i]);
		if(ui[i]>vvi[i])swap(ui[i],vvi[i]);
		if(ui[i]==1)deg1--;
		ad[ui[i]].pb(vvi[i]);
		ad[vvi[i]].pb(ui[i]);
	}
	rep(u,1,n+1)sort(all(ad[u]));
	if(deg1<k){
		printf("impossible\n");
		return 0;
	}

	int x=gao(1);
	if(x>1){
		printf("impossible\n");
		return 0;
	}


	int y=gao(2);
	if(k<y){
		printf("impossible\n");
		return 0;
	}
	printf("possible\n");

	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
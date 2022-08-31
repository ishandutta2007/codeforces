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
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	c=='-'?(sg=-1,x=0):(x=c-'0');
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
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n,m;
vector<int> b1[333][333];
vector<int> b2[333][333];
int need[333][333][2];

vector<pair<pii,pii> > ans1,ans2;
inline void add(int x1,int y1,int x2,int y2, vector<pair<pii,pii> > &ans){
	ans.pb(mp(mp(x1,y1),mp(x2,y2)));
}
int tot0=0,tot1=0;
void gao(vector<int> tar[333][333], vector<pair<pii,pii> > &ans) {
	per(k,0,siz(tar[1][1])) {
		if(tar[1][1][k]==0) {
			add(1,1,2,1,ans);
			add(2,1,1,1,ans);
		}else {
			add(1,m,1,1,ans);
		}
	}
	per(k,0,siz(tar[1][m])) {
		if(tar[1][m][k]==1) {
			add(1,m,2,m,ans);
			add(2,m,1,m,ans);
		}else {
			add(1,1,1,m,ans);
		}
	}
	rep(i,1,n+1)
		rep(j,2,m) {
			for (int k=siz(tar[i][j])-1;k>=0;k--) {
				if(tar[i][j][k]==0){
					if(i!=1)add(1,1,i,1,ans);
					add(i,1,i,j,ans);
				}else{
					if(i!=1)add(1,m,i,m,ans);
					add(i,m,i,j,ans);
				}
			}
		}
	rep(i,2,n+1) {
		int b0=0,a1=0;
		rep(k,0,siz(tar[i][1]))
			if(tar[i][1][k]==1)a1++;
		rep(k,0,siz(tar[i][m]))
			if(tar[i][m][k]==0)b0++;
		rep(k,0,b0)
			add(1,1,i,1,ans);
		rep(k,0,a1)
			add(1,m,i,m,ans);
		per(k,0,siz(tar[i][1])) {
			if(tar[i][1][k]==1) {
				add(i,m,i,1,ans);
			}else add(1,1,i,1,ans);
		}
		per(k,0,siz(tar[i][m])) {
			if(tar[i][m][k]==1) {
				add(1,m,i,m,ans);
			}else add(i,1,i,m,ans);
		}
	}
}

char s[111111];
int main()
{
	gn(n);gn(m);
	rep(i,1,n+1)
		rep(j,1,m+1) {
			gs(s);
			for (int k=0;s[k];k++) {
				b1[i][j].push_back(s[k]-'0');
				if(s[k]=='0')tot0++;
				else tot1++;
			}
			reverse(all(b1[i][j]));
		}

	rep(i,1,n+1)
		rep(j,1,m+1) {
			gs(s);
			for (int k=0;s[k];k++) {
				b2[i][j].pb(s[k]-'0');
			}
		}

	gao(b1,ans1);


	gao(b2,ans2);
	printf("%d\n",siz(ans1)+siz(ans2));
	per(i,0,siz(ans1)) {
		auto f=ans1[i];
		printf("%d %d %d %d\n",f.se.fi,f.se.se,f.fi.fi,f.fi.se);
	}
	//printf("\n");
	rep(i,0,siz(ans2)) {
		auto f=ans2[i];
		printf("%d %d %d %d\n",f.fi.fi,f.fi.se,f.se.fi,f.se.se);
	}
	return 0;
}
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
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n,m;
char stra[55][55];
char strb[55][55];

vpii optx,opty;

void out(char s[55][55]){
	rep(i,1,n+1)printf("%s\n",s[i]+1);
	printf("\n");
}
void subwork(char s[55][55],vpii &opt,int up,int dow,int c){ //middle to vert
	if(up+1==dow)return;
	int las=up;
	int y=c+1;
	int foun=0;
	for (int x=up+1;x<=dow;x++){
		if(x==dow || s[x][y]=='L'){
			if(x==dow && las==up)continue;
			foun=1;
			subwork(s,opt,las,x,y);
			las=x;
		}else if(s[x][y]=='D' && (x-up)%2==0)las=x;
	}
	if(!foun)return;
	rep(x,up+1,dow){
		if(s[x][y]=='U' && s[x][y+1]=='U'){
			assert(x<n &&y<m);
			opt.pb(mp(x,y));
			s[x][y]='L';
			s[x][y+1]='R';
			s[x+1][y]='L';
			s[x+1][y+1]='R';
			//out(s);
		}
	}
	rep(x,up+1,dow){
		if(s[x][y]=='L'){
			assert(x<n &&y<m);
			opt.pb(mp(x,y));
			s[x][y]='U';
			s[x][y+1]='U';
			s[x+1][y]='D';
			s[x+1][y+1]='D';
			//out(s);
		}
	}
}
void work(char s[55][55],vpii &opt){
	for (int y=1;y<m;y+=2){
		int las=0;
		rep(x,1,n+2){
			if(x==n+1 || s[x][y]=='L'){
				subwork(s,opt,las,x,y);
				las=x;
			}
		}
		rep(x,1,n+1){
			if(s[x][y]=='U'){
				assert(x<n &&y<m);
				opt.pb(mp(x,y));
				s[x][y]='L';
				s[x][y+1]='R';
				s[x+1][y]='L';
				s[x+1][y+1]='R';
				//out(s);
			}
		}
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	rep(i,1,n+1)scanf("%s",stra[i]+1);
	rep(i,1,n+1)scanf("%s",strb[i]+1);

	work(stra,optx);
	work(strb,opty);

	rep(i,1,n+1)rep(j,1,m+1){
		assert(stra[i][j]==strb[i][j]);
	}

	//rep(i,1,n+1)printf("%s\n",stra[i]+1);

	per(i,0,siz(opty)){
		optx.pb(opty[i]);
	}
	printf("%d\n",siz(optx));
	rep(i,0,siz(optx)){
		printf("%d %d\n",optx[i].fi,optx[i].se);
	}

/* 	printf("%d\n",siz(opty)); */
/* 	rep(i,0,siz(opty)){ */
/* 		printf("%d %d\n",opty[i].fi,opty[i].se); */
/* 	} */

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
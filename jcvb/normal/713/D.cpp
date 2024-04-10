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

int n,m;

int a[1111][1111];
int f[1111][1111];
int l2[1111];

short int st[10][10][1024][1024];
int quer(int x1,int y1,int x2,int y2){
	int k1=l2[x2-x1+1],k2=l2[y2-y1+1];

	return max(
			max(st[k1][k2][x1][y1],st[k1][k2][x1][y2-(1<<k2)+1]),
			max(st[k1][k2][x2-(1<<k1)+1][y1],st[k1][k2][x2-(1<<k1)+1][y2-(1<<k2)+1]));


}
void init(){
	rep(i,1,n+1)rep(j,1,m+1)st[0][0][i][j]=f[i][j];
	rep(k1,0,10)rep(k2,0,10){
		if(k1==0 && k2==0)continue;
		for (int i=1;i+(1<<k1)-1<=n;i++)
			for (int j=1;j+(1<<k2)-1<=m;j++){
				if(k1>0)st[k1][k2][i][j]=max(st[k1-1][k2][i][j],st[k1-1][k2][i+(1<<k1-1)][j]);
				else st[k1][k2][i][j]=max(st[k1][k2-1][i][j],st[k1][k2-1][i][j+(1<<k2-1)]);
			}
	}
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	l2[1]=0;
	for (int i=2;i<=1001;i++){
		if((i-1)&i)l2[i]=l2[i-1];
		else l2[i]=l2[i-1]+1;
	}
	gn(n);gn(m);
	rep(i,1,n+1)
		rep(j,1,m+1)
			gn(a[i][j]);
	per(i,1,n+1)per(j,1,m+1)
		if(a[i][j]==0)f[i][j]=0;
		else f[i][j]=1+min(min(f[i+1][j],f[i][j+1]),f[i+1][j+1]);

	init();
	int te;gn(te);
	while(te--){
		int a,b,c,d;
		gn(a);gn(b);gn(c);gn(d);
		int l=1,r=min(c-a+1,d-b+1);
		while(l<=r){
			int mid=l+r>>1;
			if(quer(a,b,c-mid+1,d-mid+1)>=mid)l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r);
	}

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
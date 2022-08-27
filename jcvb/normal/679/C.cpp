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
int n,k;
char s[555][555];
bool vis[555][555];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int id[555][555];
int ssiz[555*555];
int ctot=0;
int qux[555*555],quy[555*555];

int su[555][555];

int su2[555][555];
void bfs(int rx,int ry){
	int lox=rx,loy=ry,hix=rx,hiy=ry;
	ctot++;
	int p=0,q=0;
	qux[q]=rx;quy[q++]=ry;
	vis[rx][ry]=1;
	id[rx][ry]=ctot;
	while(p!=q){
		int ux=qux[p],uy=quy[p++];
		upmin(lox,ux);
		upmax(hix,ux);
		upmin(loy,uy);
		upmax(hiy,uy);
		rep(k,0,4){
			int vx=ux+dx[k],vy=uy+dy[k];
			if(s[vx][vy]!='.' || vis[vx][vy])continue;
			vis[vx][vy]=1;
			id[vx][vy]=ctot;
			qux[q]=vx;quy[q++]=vy;
		}
	}
	ssiz[ctot]=q;

	if(hix-lox+1>k || hiy-loy+1>k)return;

	su2[max(1,hix-k+1)][max(1,hiy-k+1)]+=q;
	su2[max(1,hix-k+1)][loy+1]-=q;
	su2[lox+1][max(1,hiy-k+1)]-=q;
	su2[lox+1][loy+1]+=q;
}

int maans=0;



int ap[555*555];
int cursum=0;

inline void add(int x){
	if((++ap[x])==1)cursum+=ssiz[x];
}
inline void del(int x){
	if((--ap[x])==0)cursum-=ssiz[x];
}
int work(int xx,int yy){
	for (int i=xx;i<=xx+k-1;i++)if(s[i][yy-1]=='.')add(id[i][yy-1]);
	for (int i=xx;i<=xx+k-1;i++)if(s[i][yy+k]=='.')add(id[i][yy+k]);
	for (int j=yy;j<=yy+k-1;j++)if(s[xx-1][j]=='.')add(id[xx-1][j]);
	for (int j=yy;j<=yy+k-1;j++)if(s[xx+k][j]=='.')add(id[xx+k][j]);

	int ret=cursum+su[xx+k-1][yy+k-1]-su[xx+k-1][yy-1]-su[xx-1][yy+k-1]+su[xx-1][yy-1]+su2[xx][yy];

	for (int i=xx;i<=xx+k-1;i++)if(s[i][yy-1]=='.')del(id[i][yy-1]);
	for (int i=xx;i<=xx+k-1;i++)if(s[i][yy+k]=='.')del(id[i][yy+k]);
	for (int j=yy;j<=yy+k-1;j++)if(s[xx-1][j]=='.')del(id[xx-1][j]);
	for (int j=yy;j<=yy+k-1;j++)if(s[xx+k][j]=='.')del(id[xx+k][j]);

	return ret;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);
	rep(i,1,n+1)gs(s[i]+1);

	rep(i,1,n+1)rep(j,1,n+1){
		if(s[i][j]=='X')su[i][j]=1;
	}
	rep(i,1,n+1)rep(j,1,n+1)if(s[i][j]=='.' && !vis[i][j]){
		bfs(i,j);
	}
	rep(i,1,n+1)rep(j,1,n+1)su[i][j]+=su[i][j-1];
	rep(i,1,n+1)rep(j,1,n+1)su[i][j]+=su[i-1][j];

	rep(i,1,n+1)rep(j,1,n+1)su2[i][j]+=su2[i][j-1];
	rep(i,1,n+1)rep(j,1,n+1)su2[i][j]+=su2[i-1][j];

	for (int i=1;i+k-1<=n;i++)
		for (int j=1;j+k-1<=n;j++)upmax(maans,work(i,j));
	printf("%d\n",maans);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
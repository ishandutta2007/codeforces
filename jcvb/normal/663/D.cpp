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
const int mo=1;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
int n;
int a[5555][3];
int renshu[3][3];

int fen[6]={500,1000,1500,2000,2500,3000};
int maxren[7];
int d[3];
int mi;
int macha[3];

int ok[5555][8];
int oktot;

int getfen(int i,int id){
	if(a[i][id]==0)return 0;
	return fen[d[id]]/250*(250-abs(a[i][id]));
}
int f[91][91][91];
void work(){
	for (int i=0;i<3;i++){
		int r=maxren[d[i]],l=maxren[d[i]+1]+1;
		int lre=renshu[i][2],rre=renshu[i][0]+renshu[i][2];
		if(rre<l || r<lre)return;

		macha[i]=min(rre-l,renshu[i][0]);
	}
	oktot=0;
	int my=getfen(1,0)+getfen(1,1)+getfen(1,2)+(macha[0]+macha[1]+macha[2])*100;


	if(macha[0]+macha[1]+macha[2]>=90){
		upmin(mi,1);
		return;
	}
	int mus=1;
	rep(i,2,n+1){
		int fe=getfen(i,0)+getfen(i,1)+getfen(i,2);
		if(fe>my){
			oktot++;
			int bo=0;
			rep(j,0,8){
				fe=0;
				rep(k,0,3)
					if(pw(k)&j){
						if(a[i][k]>0)fe=inf;
					}else{
						fe+=getfen(i,k);
					}
				if(fe<=my)bo=ok[oktot][j]=1;
				else ok[oktot][j]=0;
			}
			if(bo==0)oktot--,mus++;
		}
	}
	cl(f);
	rep(u,1,oktot+1){
		per(i,0,macha[0]+1)per(j,0,macha[1]+1)per(k,0,macha[2]+1){
			for (int d=0;d<8;d++)if(ok[u][d] && i>=(d&1) && j>=((d>>1)&1) && k>=((d>>2)&1)){
				upmax(f[i][j][k],f[i-(d&1)][j-((d>>1)&1)][k-((d>>2)&1)]+1);
			}
		}
	}
	upmin(mi,mus+oktot-f[macha[0]][macha[1]][macha[2]]);
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	mi=n;
	rep(d,0,6){
		maxren[d]=n>>d;
	}
	maxren[6]=-1;
	rep(i,1,n+1)rep(j,0,3){
		gn(a[i][j]);
		renshu[j][sgn(a[i][j])+1]++;
	}

	for (d[0]=0;d[0]<6;d[0]++)
		for (d[1]=0;d[1]<6;d[1]++)
			for (d[2]=0;d[2]<6;d[2]++)
				work();
	printf("%d\n",mi);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
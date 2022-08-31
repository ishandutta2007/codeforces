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

char stradd[1111];
int canaddl[1111],canaddr[1111];
int lenl[1111],lenr[1111];
int n;

int a[1111][1111];
char str[1111];
int cost[10];
int l=1005;

int f[1111][1111];
int sa[1111];//da dao xiao
int pos[1111];
inline int co(int i,int ch,int pos){
	if(ch!=0)return cost[ch];
	if(pos>=lenr[i])return 0;
	return cost[0];
}
int curpos;

int cmp(int i,int j){
	if(a[i][curpos]!=a[j][curpos])return a[i][curpos]>a[j][curpos];
	else return pos[i]<pos[j];
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gs(stradd);
	int len=strlen(stradd);
	rep(i,0,len){
		int pos=len-i;
		if(i==0 && stradd[i]=='?'){
			canaddl[pos]=1;
			canaddr[pos]=9;
		}else if(stradd[i]=='?'){
			canaddl[pos]=0;
			canaddr[pos]=9;
		}else{
			canaddl[pos]=stradd[i]-'0';
			canaddr[pos]=stradd[i]-'0';
		}
	}

	gn(n);
	rep(i,1,n+1){
		gs(str);
		int le=strlen(str);
		rep(j,0,le)a[i][le-j]=str[j]-'0';
		lenl[i]=max(le,len);
		lenr[i]=max(le,len)+1;
	}
	rep(i,0,10)gn(cost[i]);
	fil(f,-64);
	f[0][0]=0;

	rep(i,1,n+1)sa[i]=i;
	rep(i,1,l+1){
		rep(ad,canaddl[i],canaddr[i]+1){
			int jin=0;
			int su=0;
			rep(j,1,n+1){
				int x=a[j][i];
				su+=co(j,(ad+x)%10,i);
				if(ad+x>=10)jin++;
			}
			int cur=1;
			rep(t,0,n+1){
				if(t){
					int j=sa[t];
					int x=a[j][i];
					su-=co(j,(ad+x)%10,i);
					su+=co(j,(ad+x+1)%10,i);
					if(ad+x+1==10)jin++;
				}
				if(su+f[i-1][t]>=0)
					upmax(f[i][jin],su+f[i-1][t]);
			}
		}
		rep(t,1,n+1)pos[sa[t]]=t;
		curpos=i;
		sort(sa+1,sa+1+n,cmp);
	}
	printf("%d\n",f[l][0]);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
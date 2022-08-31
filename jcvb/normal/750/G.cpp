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

ll n;


ll f[56][2][111];
ll calc(int h1,int h2,ll su,int cnt){//h1>=h2
	if(su&1)return 0;
	if(pw(h1+1)-2+pw(h2+1)-2<su)return 0;
	cl(f);

	f[0][0][0]=1;
	for (int i=0;i<=h1;i++)
		for (int d=0;d<=1;d++)
			for (int x=0;x<=h1+h2;x++)if(f[i][d][x]){
				int ok=(i+1<=h1)+(i+1<=h2);
				int tar=(su>>(i+1))&1;
				for (int j=0;j<=ok;j++){
					if((j+d-tar)&1)continue;
					int way=(ok==2 && j==1)?2:1;
					if(j+d>=2)f[i+1][1][x+j]+=way*f[i][d][x];
					else f[i+1][0][x+j]+=way*f[i][d][x];
				}
			}
	return f[h1+1][0][cnt];
}
ll work(int h1,int h2,ll su){//2^1-1 ~ 2^hi - 1 subset sum= su
	if(su<0)return 0;
	if(h1==0 && h2==0 && su>0)return 0;
	if(h1<h2)swap(h1,h2);

	ll ret=0;
	for (int cnt=0;cnt<=h1+h2;cnt++){
		ret+=calc(h1,h2,su+cnt,cnt);
	}
	return ret;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	ll ans=1;
	for (int l1=0;l1<=53;l1++)
		for (int l2=l1;l2<=53;l2++){
			if(l1==l2){
				continue;
			}
			int d=l2-l1+1;
			ll hed=n/(pw(d)-1);
			if(hed>=pw(l1) && hed<pw(l1+1)){
				ll lef=n-hed*(pw(d)-1ll);
				ans+=work(d-1,0,lef);
			}
		}
	for (int l=0;l<=53;l++)
		for (int h0=l+1;h0<=53;h0++)
			for (int h1=l+1;h1<=53;h1++){
				int d0=h0-l,d1=h1-l;
				ll wei=pw(d0+1)-2+pw(d1+1)-2+1;
				ll hed=n/(wei);
				if(hed>=pw(l) && hed<pw(l+1)){
					ll lef=n-hed*wei;
					ans+=work(d0-1,d1-1,lef-pw(d1)+1);
				}
			}
	cout<<ans<<endl;


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
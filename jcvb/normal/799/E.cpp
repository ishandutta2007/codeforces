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
//const int inf=0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int n,m,k;

int cost[222222];
int typ[222222];

vi a,b,both;

int a_toput,b_toput;
ll sum=0;

priority_queue<ll> inside;
ll sum_in=0;
priority_queue<ll,vector<ll>,greater<ll> > outside;

void tiao(int k){
	while(siz(inside)>k){
		ll t = inside.top();inside.pop();
		sum_in-=t;
		outside.push(t);
	}
	while(siz(inside)<k){
		if(outside.empty())break;
		ll t = outside.top();outside.pop();
		sum_in+=t;
		inside.push(t);
	}
}

void push(int x){
	if(!inside.empty() && x<=inside.top()) inside.push(x), sum_in+=x;
	else outside.push(x);
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);gn(k);
	if(k>m){
		printf("-1\n");
		return 0;
	}
	rep(i,1,n+1)gn(cost[i]);
	int r;gn(r);
	while(r--){
		int t;gn(t);typ[t]|=1;
	}
	gn(r);
	while(r--){
		int t;gn(t);typ[t]|=2;
	}
	rep(i,1,n+1)
		if(typ[i]==1)a.pb(cost[i]);
		else if(typ[i]==2)b.pb(cost[i]);
		else if(typ[i]==3)both.pb(cost[i]);
		else push(cost[i]);


	sort(all(a));
	sort(all(b));
	sort(all(both));
	ll mi = inf;

	int had=0;
	rep(t,0,min(siz(both),m)+1){
		int singleneed = max(0,k-t);
		if(t>0)sum+=both[t-1];
		if(singleneed>siz(a) || singleneed > siz(b))continue;

		if(had==0){
			rep(j,a_toput,singleneed)sum+=a[j];
			a_toput = singleneed;

			rep(j,singleneed,siz(a)){
				push(a[j]);
			}
			rep(j,b_toput,singleneed)sum+=b[j];
			b_toput = singleneed;
			rep(j,singleneed,siz(b)){
				push(b[j]);
			}
			had=1;
		}

		while(a_toput>singleneed){
			sum-=a[a_toput-1];
			push(a[a_toput-1]);
			a_toput--;
		}
		while(b_toput>singleneed){
			sum-=b[b_toput-1];
			push(b[b_toput-1]);
			b_toput--;
		}

		if(t + singleneed*2>m)continue;
		tiao(m-2*singleneed-t);
		if(inside.size()==m-2*singleneed-t) upmin(mi,sum+sum_in);
	}
	if(mi==inf)printf("-1\n");
	else cout<<mi<<endl;
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
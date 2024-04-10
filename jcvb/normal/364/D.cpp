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

namespace myrand{
	// rand : [0,2^31)
	// randint : [-2^31,2^31)
	// randll : [-2^63,2^63)
	// randbit : 0,1
	unsigned int x[5]={107896582, 1107972621, 1195573091, 1224749359, 241825441};
	unsigned int get16(){
		unsigned long long tmp=(107374182ll*x[0]+104480ll*x[4]);
		unsigned int res=(tmp>>31)+(tmp&0x7fffffffu);
		x[0]=x[1],x[1]=x[2],x[2]=x[3],x[3]=x[4];
		return x[4]=res>=2147483647?res-2147483647:res;
	}
	void mysrand(unsigned int seed){
		for (int i=0;i<5;i++) seed=(seed+1)%2147483647,x[i]=seed;
		for (int i=0;i<5;i++) get16();
	}
	int randint(){
		int res=0;
		res+=int(get16());
		res+=int(get16())<<16;
		return res;
	}
	long long randll(){
		long long res=0;
		res+=(long long)(get16());
		res+=(long long)(get16())<<16;
		res+=(long long)(get16())<<32;
		res+=(long long)(get16())<<48;
		return res;
	}
	int randbit(){
		return ((get16())>>7)&1;
	}
	int myrand(){
		int x=randint();
		if(x<0)return ~x;
		return x;
	}
	template<typename RandomAccessIterator>void my_randomshuffle(RandomAccessIterator first,RandomAccessIterator last){
		int n=last-first;
		for (int i=1;i<n;i++){
			int to=myrand()%(i+1);
			swap(first[to],first[i]);
		}
	}
#define rand myrand::myrand
#define srand myrand::mysrand
#define random_shuffle myrand::my_randomshuffle
};

int randlr(int l,int r){	// rand integer from [l,r]
	return ((unsigned long long)(myrand::randll()))%(r-l+1)+l;
}
double randreal(){	//rand real from [0,1]
	long long t=myrand::randll();
	if(t<0)t=~t;
	return (long double)(t)/(long double)(0x8000000000000000u);
}

int n;
ll a[1111111];

ll ans=1ll;



// ha[123]=4567
// s[1..tot],v[1..tot]

const int hashtable_mod=1048576; // 300007 500009 800011 1000003 3000017 5000011 8000009
const int hashtable_maxn=1333333;
typedef long long hashtable_key;
//typedef int hashtable_key;
typedef int hashtable_value;
struct hashtable{
       int head[hashtable_mod];       
       hashtable_key s[hashtable_maxn];
       hashtable_value v[hashtable_maxn],zerovalue;
       int next[hashtable_maxn];
       int label[hashtable_mod];       
       int tot;
       int tms;
       hashtable_value& operator[](hashtable_key S){
	    int la=abs(S)%hashtable_mod;
	    if(label[la]==tms)
		for (int st=head[la];st;st=next[st])
		    if(s[st]==S) return v[st];
	    ++tot;
	    v[tot]=zerovalue;s[tot]=S;
	    next[tot]=label[la]==tms?head[la]:0;
	    head[la]=tot;
	    label[la]=tms;
	    return v[tot];
       }
       void clear(){
	    tms++;
	    tot=0;
       }
}ma;

void check(ll x){
	int sum=0;
	rep(i,1,ma.tot+1)if(ma.s[i]%x==0)sum+=ma.v[i];
	if(sum*2>=n)upmax(ans,x);
}

namespace rho{
	ll mul(ll x,ll y,ll z){
		x%=z,y%=z;
		if(z<=2e9)return (x*y%z+z)%z;
		return (x*y-(ll)(x/(long double)z*y)*z+z)%z;
	}
	ll qp(ll a,ll b,ll mo){ll ans=1;do{if(b&1)ans=mul(ans,a,mo);a=mul(a,a,mo);}while(b>>=1);return ans;}
	ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
	int pr[9]={2,3,5,7,11,13,17,19,23};
	ll tmp[100];int tot;
	ll ps[100],ds[100];int ptot;
	int mr(ll n){
	    if(n<=1)return 0;
	    for (int i=0,a;i<9;i++){
		if((a=pr[i])==n)return 1;
		ll t=n-1;int k=0;
		while(~t&1)t>>=1,k++;
		ll c=qp(a,t,n);
		if(c==1)continue;
		int bo=0;
		for (int i=0;i<k;i++){
		    if(c==n-1){bo=1;break;}
		    c=mul(c,c,n);
		}
		if(!bo)return 0;
	    }
	    return 1;
	}
	void rho(ll n){
	    if(mr(n))tmp[++tot]=n;
	    else{
		for (int c=12345;;c++){
		    ll x=0,y=0;
		    while(1){
			x=(mul(x,x,n)+c)%n;
			y=(mul(y,y,n)+c)%n;
			y=(mul(y,y,n)+c)%n;
			ll d=gcd(n,abs(x-y));
			if(d!=1){
			    if(d!=n){
				rho(d);
				rho(n/d);
				return;
			    }else break;
			}
		    }
		}
	    }
	}
	void facto(ll n){
		tot=0;
		for (int i=0;i<9;i++)while(n%pr[i]==0){
		    tmp[++tot]=pr[i];
		    n/=pr[i];
		}
		if(n>1)rho(n);
		sort(tmp+1,tmp+1+tot);
		ptot=0;
		for (int i=1;i<=tot;i++)
			if(i==1 || tmp[i]!=tmp[i-1]){
				ps[++ptot]=tmp[i];
				ds[ptot]=1;
			}else ds[ptot]++;
	}
	void dfs_fact(int id,ll cur){
		if(id==ptot+1){
			check(cur);
		}else{
			for (int i=0;i<=ds[id];i++){
				dfs_fact(id+1,cur);
				cur*=ps[id];
			}
		}
	}
};


int main()
{
#ifdef JCVB
//	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1)gn(a[i]);


	using namespace rho;
	rep(_,1,10){
		int id=randlr(1,n);

		ll x=a[id];

		ma.clear();
		rep(i,1,n+1)ma[gcd(x,a[i])]++;

		facto(x);
		dfs_fact(1,1);
	}
	cout<<ans<<endl;



#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
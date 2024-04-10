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

// ha[123]=4567
// s[1..tot],v[1..tot]

const int hashtable_mod=8000019; // 300007 500009 800011 1000003 3000017 5000011 8000009
const int hashtable_maxn=10033333;
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
}ha;

int n;



int a[4444];
int sua[4444];


int dfs(int l,int r,int k,int op){
	//if(l+r>n)return inf;
	if(n-l-r<k)return 0;
	if(n-l-r==k)return sua[l+k]-sua[l];
	ll s=(l+1)*3*5555ll*5555ll+(r+1)*3*5555ll+(k+1)*3ll+(op+1);
	if(ha[s]&1){
		return (ha[s]-1)/2;
	}else{
		int ans;
		if(op==0){
			ans=max(sua[l+k]-sua[l] - dfs(l+k,r,k,1), 
			           sua[l+k+1]-sua[l] - dfs(l+k+1,r,k+1,1));
		}else{
			ans=max(sua[n-r]-sua[n-r-k] - dfs(l,r+k,k,0),
					sua[n-r]-sua[n-r-k-1] - dfs(l,r+k+1,k+1,0));
		}
		ha[s]=2*ans+1;
		return ans;
	}
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	//n=4000;
	rep(i,1,n+1){
		gn(a[i]);
	}
	rep(i,1,n+1)sua[i]=sua[i-1]+a[i];
	ha.clear();

	printf("%d\n",dfs(0,0,1,0));
	/*ini=(node){0,0,1,0};
	dfs(ini);
	printf("%d\n",se.size());*/


#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
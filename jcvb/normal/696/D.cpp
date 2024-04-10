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
const ll inf=1e18;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

char str[1111];
int n;
int ch[222][26]={0};int val[222]={0},fail[222]={0};int ndtot=1,rt=0;
void add(char* s,int v){
	int x=rt;
	for (int i=0;s[i];i++){
		int c=s[i]-'a';
		if(ch[x][c])x=ch[x][c];
		else x=ch[x][c]=ndtot++;
	}
	val[x]+=v;
}
int qu[222],p,q;
void build(){
	p=q=0;
	qu[q++]=rt;
	while(p!=q){
		int u=qu[p++];
		val[u]+=val[fail[u]];
		for (int i=0;i<26;i++)
			if(ch[u][i]){
				qu[q++]=ch[u][i];
				if(!u)fail[ch[u][i]]=0;
				else fail[ch[u][i]]=ch[fail[u]][i];
			}else ch[u][i]=ch[fail[u]][i];
	}
}

int ai[222];

struct mat{
	ll a[222][222];
}zer,one;
mat operator*(const mat&a,const mat&b){
	mat c=zer;
	rep(k,0,ndtot)
		rep(i,0,ndtot)
			rep(j,0,ndtot)upmax(c.a[i][j],a.a[i][k]+b.a[k][j]);
	return c;
}
mat qp(mat a,ll b){mat n=one;do{if(b&1)n=n*a;a=a*a;}while(b>>=1);return n;}
mat b,ans;
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	int n;ll l;
	gn(n);gn(l);
	rep(i,1,n+1)gn(ai[i]);
	rep(i,1,n+1){
		gs(str);
		add(str,ai[i]);
	}

	build();

	rep(i,0,ndtot)rep(j,0,ndtot)zer.a[i][j]=-inf;
	one=zer;
	rep(i,0,ndtot)one.a[i][i]=0;

	
	b=zer;
	rep(i,0,ndtot)
		rep(c,0,26)b.a[i][ch[i][c]]=val[ch[i][c]];
	ans=qp(b,l);
	ll ma=0;
	rep(i,0,ndtot)upmax(ma,ans.a[0][i]);
	cout<<ma<<endl;
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
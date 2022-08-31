#include<cstdio>
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
#define pi ((db)3.14159265358979323846264338327950288L)
#define buli __builtin_popcountll
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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
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
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}



/*struct node{int ch[2],sz,v,fix;ll su;}t[500005];int ndtot=0;
int rt[222222]={0};
void rot(int &x,int f){
	int y=t[x].ch[!f];
	t[x].ch[!f]=t[y].ch[f];
	t[y].ch[f]=x;
	t[y].sz=t[x].sz;
	t[y].su=t[x].su;
	t[x].sz=t[t[x].ch[0]].sz+t[t[x].ch[1]].sz+1;
	t[x].su=t[t[x].ch[0]].su+t[t[x].ch[1]].su+t[x].v;
	x=y;
}
void ins(int &x,int v){
	if(x==0){
		x=++ndtot;
		t[x].ch[0]=t[x].ch[1]=0;
		t[x].sz=1;
		t[x].fix=rand();
		t[x].v=v;
		t[x].su=v;
	}else{
		int f=v>=t[x].v;
		ins(t[x].ch[f],v);
		t[x].sz++;
		t[x].su+=v;
		if(t[t[x].ch[f]].fix<t[x].fix)rot(x,!f);
	}
}
void del(int &x){
	if(!t[x].ch[0] && !t[x].ch[1])x=0;
	else{
		int v=t[x].v;
		int f=!t[x].ch[0] || t[x].ch[1]&&t[t[x].ch[1]].fix<t[t[x].ch[0]].fix;
		rot(x,!f);
		t[x].sz--;
		t[x].su-=v;
		del(t[x].ch[!f]);
	}
}
void del_num(int &x,int v){
	if(t[x].v==v)del(x);
	else{
		int f=v>=t[x].v;
		t[x].sz--;
		t[x].su-=v;
		del_num(t[x].ch[f],v);
	}
}
int rk(int v){
	int x=root;int ans=0;
	while(x){
		if(t[x].v>=v)x=t[x].ch[0];
		else{
			ans+=t[t[x].ch[0]].sz+1;
			x=t[x].ch[1];
		}
	}
	return ans+1;
}*/

int n,k,_q;
ll a,b;

ll bita[222222],bitb[222222];
ll ansa[222222],ansb[222222];
ll tot[222222];
void bitupd(ll *a,int x,ll v){
	for(;x<=n;x+=x&-x)a[x]+=v;
}
ll bitque(ll *a,int x){
	ll su=0;
	for(;x;x-=x&-x)su+=a[x];
	return su;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);gn(a);gn(b);gn(_q);
	while(_q--){
		int opt;gn(opt);
		if(opt==1){
			int di,ai;
			gn(di);gn(ai);
			tot[di]+=ai;
			ll na=min(a,tot[di]);
			bitupd(bita,di,-ansa[di]);
			ansa[di]=na;
			bitupd(bita,di,ansa[di]);
			ll nb=min(b,tot[di]);
			bitupd(bitb,di,-ansb[di]);
			ansb[di]=nb;
			bitupd(bitb,di,ansb[di]);

		}else{
			int pii;
			gn(pii);
			printf("%I64d\n",bitque(bitb,pii-1)+bitque(bita,n)-bitque(bita,pii+k-1));
		}
	}


	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
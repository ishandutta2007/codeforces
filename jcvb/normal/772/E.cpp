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

int n;

map<pair<pii,int>,char> note;
char  ask(int a,int b,int c){
	if(a==b){
		assert(a==0);
		return 'X';
	}
	assert(a!=b && b!=c && c!=a);
	auto x = mp(mp(a,b),c);
	if(note.count(x))return note[x];
	else {
		printf("%d %d %d\n",a,b,c);
		fflush(stdout);
		char c;gc(c);
		note[x]=c;
		return c;
	}
}

int ndtot;
int pr[2111];

int ch1[2222],ch2[2222];//for interi only//bixu genzhe erzi de ch1,2
vi chd[2222];
int off[2111];
void rebuild(){
	rep(i,1,ndtot+1)off[i]=0;
	rep(i,1,ndtot+1)chd[i].clear();
	rep(i,1,ndtot+1)if(pr[i])chd[pr[i]].pb(i);
}
int rt;
int u;


int sz[2222],maa[2222];
int lis[2222];int ltot;

void dfs(int u){
	sz[u]=1;
	maa[u]=0;
	lis[++ltot]=u;
	rep(j,0,siz(chd[u])){
		int v=chd[u][j];
		if(off[v])continue;
		dfs(v);
		upmax(maa[u],sz[v]);
		sz[u]+=sz[v];
	}
}


int work(int rt){
	ltot=0;
	dfs(rt);
	int totsz=sz[rt];
	if(totsz==1)return rt;
	int cen=0;
	rep(i,1,ltot+1){
		int u=lis[i];
		if((totsz-sz[u])*2<=totsz && maa[u] &&  maa[u]*2<=totsz){
			cen=u;
			break;
		}
	}

	assert(cen);
	assert(cen>n);
	char ret;
	ret=ask(ch1[cen],ch2[cen],u);
	if(ret=='X'){
		off[chd[cen][0]]=off[chd[cen][1]]=1;
		//off[cen]=1;
		return work(rt);
	}else{
		int son1,son2;
		if(ch1[chd[cen][0]]==ch2[cen] || ch2[chd[cen][0]]==ch2[cen] || chd[cen][0]==ch2[cen]){
			son2=chd[cen][0];
			son1=chd[cen][1];
		}else{
			son1=chd[cen][0];
			son2=chd[cen][1];
		}
		if(ret=='Y'){
			return work(son2);
		}else return work(son1);
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
	ndtot=n;

	char ret=ask(1,2,3);
	int arr[4];
	if(ret=='X')arr[1]=1,arr[2]=2,arr[3]=3;
	else if(ret=='Y')arr[1]=2,arr[2]=3,arr[3]=1;
	else arr[1]=3,arr[2]=1,arr[3]=2;
	int x=++ndtot;
	int y=++ndtot;
	pr[arr[1]]=pr[arr[2]]=x;
	ch1[x]=arr[1];
	ch2[x]=arr[2];
	pr[x]=pr[arr[3]]=y;
	ch1[y]=arr[1];
	ch2[y]=arr[3];
	rt=y;

	for (u=4;u<=n;u++){
		rebuild();
		rep(i,1,ndtot+1)debug("%d ",pr[i]);
		debug("\n");
		int t=work(rt);

		int x=++ndtot;
		if(pr[t]==0){
			ch1[x]=ch1[t];
			rt=x;
		}else{
			if(t<=n)ch1[x]=t;
			else{
				if(ch1[pr[t]]==ch1[t] || ch2[pr[t]]==ch1[t])ch1[x]=ch1[t];
				else ch1[x]=ch2[t];
			}
		}
		ch2[x]=u;
		pr[u]=x;
		pr[x]=pr[t];
		pr[t]=x;
	}
	printf("-1\n");
	rep(i,1,ndtot+1){
		if(pr[i]==0)printf("-1 ");
		else printf("%d ",pr[i]);
	}




#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
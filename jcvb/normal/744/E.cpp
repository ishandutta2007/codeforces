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


// str[1..n]  ->  hasharray[0..n]
// 	inithash(str,n,int*hasharray);
// or   inithash(str,n,int*hasharray0,int*hasharray1);
// or   inithash(str,n,ll*hasharray);
//
//hash of str[l..r]
//	gh(l,r,int*hasharray)
//or	gh(l,r,int*hasharray,typ)
//or	gh(l,r,int*hasharray0,int*hasharray1)   (return hash0<<32|hash1)
//or	gh(l,r,ll*hasharray)

const int HASH_LENGTH=100000+5;
const int hashmo[2]={1049999959,1050000011},hashseed[2]={100000007,200000033};
int hashpo[2][HASH_LENGTH];
ll hashpoll[HASH_LENGTH];

void inithash(char *a,int n,int*h,int typ=0){
	static bool ini[2]={0,0};
	int m=hashmo[typ],s=hashseed[typ];
	if(!ini[typ]){
		ini[typ]=1;
		hashpo[typ][0]=1;
		for (int i=1;i<HASH_LENGTH;i++)
			hashpo[typ][i]=1ll*hashpo[typ][i-1]*s%m;
	}
	h[0]=0;
	for (int i=1;i<=n;i++)h[i]=(1ll*h[i-1]*s+a[i])%m;
}
void inithash(char *a,int n,int*h0,int *h1){
	inithash(a,n,h0,0);
	inithash(a,n,h1,1);
}
void inithash(char *a,int n,ll *h){
	static bool ini=0;
	int s=hashseed[0];
	if(!ini){
		ini=1;
		hashpoll[0]=1;
		for (int i=1;i<HASH_LENGTH;i++)
			hashpoll[i]=1ll*hashpoll[i-1]*s;
	}
	h[0]=0;
	for (int i=1;i<=n;i++)h[i]=1ll*h[i-1]*s+a[i];
}
int gh(int l,int r,int *h,int typ=0){
	return ((h[r]-1ll*h[l-1]*hashpo[typ][r-l+1])%hashmo[typ]+hashmo[typ])%hashmo[typ];
}
ll gh(int l,int r,int *h0,int *h1){
	return (1ll*gh(l,r,h0,0))<<32|gh(l,r,h1,1);
}
ll gh(int l,int r,ll *h){
	return h[r]-h[l-1]*hashpoll[r-l+1];
}
int lcp(int la,int ra,int *h0a,int *h1a,int lb,int rb,int *h0b,int *h1b){
		//int lcp(int la,int ra,int *ha,int lb,int rb,int *hb){
		//int lcp(int la,int ra,ll *ha,int lb,int rb,ll *hb){
	int l=1,r=min(ra-la+1,rb-lb+1);
	while(l<=r){
		int mid=l+r>>1;
		if
			(gh(la,la+mid-1,h0a,h1a)==gh(lb,lb+mid-1,h0b,h1b))
					//(gh(la,la+mid-1,ha)==gh(lb,lb+mid-1,hb))
				l=mid+1;
		else 		r=mid-1;
	}
	return r;
}
/*
int comp(int la,int ra,int lb,int rb){			//modify
	// -1 if a<b 	; 0 if a==b 	; 1 if a>b
	int d=lcp(la,ra,lb,rb);				//modify
	if(ra-la+1==d && rb-lb+1==d)return 0;
	if(ra-la+1==d)return -1;
	if(rb-lb+1==d)return 1;
	char ca=stra[la+d],cb=strb[lb+d];		//modify
	if(ca<cb)return -1;
	return 1;
}*/
map<ll,int> vid;
int idtot=0;

int getid(ll x){
	if(vid[x])return vid[x];
	else return vid[x]=++idtot;
}
char s[33][111111];
int len[33];
ll sufhas[33][111111];
int sufid[33][111111];
int has1[33][111111],has2[33][111111];
int n;


const int SCC_MAXV=133333;
struct node{
	int v,next,l,r;
}e[6999999];int g[333333];int etot=0;
void ae(int u,int v,int l,int r){
	e[etot].v=v;e[etot].l=l;e[etot].r=r;e[etot].next=g[u];g[u]=etot++;
	debug("%d %d %d %d\n",u,v,l,r);
}

int dfn[SCC_MAXV],low[SCC_MAXV],stk[SCC_MAXV];bool inst[SCC_MAXV];int ind,top;
int scctot,sccid[SCC_MAXV];
int curl,curr;
void dfs(int u){
	dfn[u]=low[u]=++ind;
	inst[stk[++top]=u]=1;
	for (int i=g[u];~i;i=e[i].next)if(curl<=e[i].l && e[i].r<=curr){
		if(!dfn[e[i].v]){
			dfs(e[i].v);
			low[u]=min(low[u],low[e[i].v]);
		}else if(inst[e[i].v])
			low[u]=min(low[u],dfn[e[i].v]);
	}
	if(low[u]==dfn[u]){
		++scctot;
		while(1){
			bool bo=stk[top]==u;
			sccid[stk[top]]=scctot;
			inst[stk[top--]]=0;
			if(bo)break;
		}
	}
}
void scc(){
	rep(i,0,idtot+1)if(!dfn[i])dfs(i);
}
void scc_init(){
	for (int i=0;i<=idtot;i++)dfn[i]=low[i]=sccid[i]=0;
	etot=scctot=ind=0;
}

bool check(int l,int r){
	curl=l,curr=r;
	scc_init();
	scc();
	rep(i,l,r+1){
		rep(j,1,len[i]){
			ll x=gh(1,j,has1[i],has2[i]);
			if(vid.count(x)){
				if(sccid[vid[x]]==sccid[sufid[i][j+1]])return 0;
			}
		}

	}
	return 1;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	fil(g,-1);
	gn(n);
	vid[0]=0;
	rep(i,1,n+1){
		gs(s[i]+1);
		len[i]=strlen(s[i]+1);
		inithash(s[i],len[i],has1[i],has2[i]);
		rep(d,1,len[i]+1){
			sufhas[i][d]=gh(d,len[i],has1[i],has2[i]);
			sufid[i][d]=getid(sufhas[i][d]);
		}
	}

	rep(i,1,n+1)rep(j,1,n+1){
		rep(l,0,len[j]+1){
			if(l>len[i])break;
			if(sufhas[j][len[j]-l+1]==gh(1,l,has1[i],has2[i]))
				ae(sufid[j][len[j]-l+1],sufid[i][l+1],min(i,j),max(i,j));
		}
		if(len[j]>len[i])continue;
		rep(l,1,len[i]+1){
			if(l+len[j]-1>len[i])break;
			if(sufhas[j][1]==gh(l,l+len[j]-1,has1[i],has2[i])){
				ae(sufid[i][l],sufid[i][l+len[j]],min(i,j),max(i,j));
			}
		}
	}
	int su=0;
	rep(i,1,n+1){
		int l=i,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(check(i,mid))l=mid+1;
			else r=mid-1;
		}
		su+=l-i;
		debug("from %d to %d\n",i,r);
	}
	printf("%d\n",su);

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
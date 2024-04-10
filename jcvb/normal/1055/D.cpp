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
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	c=='-'?(sg=-1,x=0):(x=c-'0');
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
char s[3333][3333],t[3333][3333];
int lef[3333],rig[3333];
char gao[3333];



// getpre
// 	string : s[1..n]
// 	ans : pre[1..n]
// kmpmatch
// 	string : s[1..n], t[1..m]
// 	ans : f[1..m]

const int KMP_MAXN = 5005;
int pre[5555];
void getpre(char *s,int n,int *pre){
	pre[1]=0;
	for (int i=2,j=0;i<=n;i++){
		while(j && s[j+1]!=s[i])j=pre[j];
		if(s[j+1]==s[i])j++;
		pre[i]=j;
	}
}
int kmpmatch(char *s,int n,int *pre,char *t,int m){
	if(!pre){
		static int tmp[KMP_MAXN];pre=tmp;
		getpre(s,n,pre);
	}
	for (int i=1,j=0;i<=m;i++){
		while(j && s[j+1]!=t[i])j=pre[j];
		if(s[j+1]==t[i])j++;
			if(j==n) return i-j+1-1;
		if(j==m)j=pre[j];
	}
	return -1;
}
int main()
{
	gn(n);
	rep(i,1,n+1)gs(s[i]);
	rep(i,1,n+1)gs(t[i]);
	fil(lef,-1);
	fil(rig,-1);
	rep(i,1,n+1){
		for(int j=0;s[i][j];j++) {
			if(s[i][j]!=t[i][j]) {
				if(lef[i]==-1)lef[i]=j;
				rig[i]=j;
			}
		}
	}
	int fi=0;
	rep(i,1,n+1) {
		if(lef[i]!=-1){
			fi=i;
			break;
		}
	}

	rep(i,1,n+1)if(lef[i]!=-1) {
		if(rig[i]-lef[i]!=rig[fi]-lef[fi]){
			printf("NO\n"); return 0;
		}
		for (int t=lef[i];t<=rig[i];t++) {
			if(s[fi][t-lef[i]+lef[fi]]!=s[i][t] || ::t[fi][t-lef[i]+lef[fi]]!=::t[i][t]) {
				printf("NO\n");
				return 0;

			}
		}
	}
	int gol=0;
	while(1) {
		int bo=1;
		if(lef[fi]-gol-1<0) {
			break;
		}
		rep(i,1,n+1)if(lef[i]!=-1) {
			if(s[fi][lef[fi]-gol-1] != s[i][lef[i]-gol-1]) {
				bo=0;
				break;
			}
		}
		if(bo)gol++;
		else break;
	}
	int gor=0;


	int nn = strlen(s[fi]);
	while(1) {
		int bo=1;
		if(rig[fi]+gor+1>=nn) {
			break;
		}
		rep(i,1,n+1)if(lef[i]!=-1) {
			if(s[fi][rig[fi]+gor+1] != s[i][rig[i]+gor+1]) {
				bo=0;
				break;
			}
		}
		if(bo)gor++;
		else break;
	}
	int le=0;
	int lll = lef[fi]-gol,rrr=rig[fi]+gor;
	rep(i,lll,rrr+1)gao[le++]=s[fi][i];

	getpre(gao-1,le,pre);
	rep(i,1,n+1) {
		int ttt = kmpmatch(gao-1,le,pre,s[i]-1,strlen(s[i]));
		if(lef[i]==-1) {
			if(ttt!=-1){
				printf("NO\n"); return 0;
			}
		}else if (ttt!=lef[i]-gol) {
				printf("NO\n"); return 0;
		}
	}

	printf("YES\n");
	printf("%s\n",gao);
	rep(i,lll,rrr+1)putchar(t[fi][i]);
	printf("\n");
	return 0;
}
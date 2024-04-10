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

int n,m;
int a[6333];
int id[6333];
int presum[6333];
int tot;

int ans[3333][3333];

/*struct node{
	int id,x,lef;
};
int operator<(const node&a,const node&b){
	return a.x>b.x;
}
priority_queue<node>qu;*/

vector<int>in[6444],out[6444];
int ok[6666];
int tmp[6666],tmpid[6666];
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	rep(i,1,m+1)gn(a[i]);
	sort(a+1,a+1+m);
	reverse(a+1,a+1+m);
	tot=n*(n-1);
	rep(i,1,m+1){
		presum[i]=a[i]+presum[i-1];
	}
	if(presum[m]>tot || presum[m]+(n-m)*a[m]<tot){
		printf("no\n");
		return 0;
	}
	if(m!=n){
		int lef=tot-presum[m];
		int q=lef/(n-m);
		rep(i,m+1,n+1)a[i]=q;
		int r=lef%(n-m);
		rep(i,m+1,m+r+1)a[i]++;
	}
	int su=0;
	for (int i=1;i<=n;i++){
		su+=a[n-i+1];
		if(su<i*(i-1)){
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n");
	rep(i,1,n+1)id[i]=i;

	rep(i,1,n){
		memset(ok,0,sizeof(ok));
		int fen=a[i];
		int lef=n-i;
		/*while(!qu.empty())qu.pop();*/
		rep(j,0,2*(n-i+1)+1)in[j].clear();
		rep(j,i+1,n+1){
			in[a[j]].pb(j);
		}
		int curma=a[i+1];
		fen=2*lef-fen;
		while(fen){
			while(in[curma].empty())curma--;
			int x=in[curma].back();
			in[curma].pop_back();
			if(ok[x]!=2){
				ok[x]++;
				fen--;
				in[curma-1].pb(x);
			}else{
				out[curma].pb(x);
			}
		}
		rep(j,i+1,n+1){
			ans[id[i]][id[j]]=ok[j];
			ans[id[j]][id[i]]=2-ok[j];
		}
		int tmptot=0;
		for (int j=a[i+1];j>=0;j--){
			while(!in[j].empty()){
				int x=in[j].back();
				in[j].pop_back();
				tmp[++tmptot]=x;
				a[tmptot+i]=j;
			}
			while(!out[j].empty()){
				int x=out[j].back();
				out[j].pop_back();
				tmp[++tmptot]=x;
				a[tmptot+i]=j;
			}
		}
		rep(t,1,tmptot+1){
			tmpid[t+i]=id[tmp[t]];
		}
		rep(t,1,tmptot+1){
			id[t+i]=tmpid[t+i];
		}
	}
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(i==j)putchar('X');
			else if(ans[i][j]==2)putchar('L');
			else if(ans[i][j]==1)putchar('D');
			else putchar('W');
		}
		putchar('\n');
	}

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
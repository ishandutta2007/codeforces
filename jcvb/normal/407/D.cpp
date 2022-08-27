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

int n,m;
int a[411][411];

int nearlef[411][411],nearrig[411][411];
struct node{
	int x,y,next;
}nd[161111];int head[161111];

vpii pos[161111];// jiang xu
int glo_ans=0;
int up=160000;

int far[411];
int tag[411];

int cnt[411];//keep   zero

int curst;

int lklef[411],lkrig[411];
//int done[411];
void init_near(int num){
	//undefined : -1

	//int donetot=0;
	int prec=0;
	for (int i=head[num],j=-1;~i;i=nd[i].next){
		if(nd[i].x<curst){
			if(j==-1)head[num]=nd[i].next;
			else nd[j].next=nd[i].next;
		}else{
			if(nd[i].y==prec){
				cnt[prec]++;
			}else{
				lklef[nd[i].y]=prec;
				lkrig[prec]=nd[i].y;
				//done[++donetot]=nd[i].y;
				cnt[nd[i].y]=1;
				prec=nd[i].y;
			}
			j=i;
		}
	}

	lklef[m+1]=prec;
	lkrig[prec]=m+1;
	rep(i,0,siz(pos[num])){
		int x=pos[num][i].fi,y=pos[num][i].se;

		if(cnt[y]>1){
			nearlef[x][y]=nearrig[x][y]=y;
			cnt[y]--;
		}else{

			if(lklef[y]!=0)nearlef[x][y]=lklef[y];
			else nearlef[x][y]=-1;

			if(lkrig[y]!=m+1)nearrig[x][y]=lkrig[y];
			else nearrig[x][y]=-1;

			cnt[y]--;

			lklef[lkrig[y]]=lklef[y];
			lkrig[lklef[y]]=lkrig[y];
		}
	}
	//rep(i,1,donetot+1)cnt[done[i]]=0;
}
int main()
{
	fil(head,-1);
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	rep(i,1,n+1)rep(j,1,m+1)gn(a[i][j]);

	per(j,1,m+1)rep(i,1,n+1){
		int id=(i-1)*m+j;
		nd[id].x=i;
		nd[id].y=j;
		nd[id].next=head[a[i][j]];
		head[a[i][j]]=id;
	}
	per(i,1,n+1)per(j,1,m+1)pos[a[i][j]].pb(mp(i,j));

	rep(st,1,n+1){
		curst=st;
		rep(num,1,up+1){
			while(pos[num].size() && pos[num].back().fi<st)pos[num].pop_back();
			if(pos[num].size()){
				init_near(num);
			}
		}
		rep(i,1,m+1)far[i]=m;

		rep(ed,st,n+1){
			rep(j,1,m+1)tag[j]=inf;

			rep(j,1,m+1){
				if(~nearlef[ed][j]){
					upmin(tag[nearlef[ed][j]],j-1);
				}
				if(~nearrig[ed][j]){
					upmin(tag[j],nearrig[ed][j]-1);
				}
			}
			int cur=inf;
			per(j,1,m+1){
				upmin(cur,tag[j]);
				upmin(far[j],cur);
				if(far[j]>=j)upmax(glo_ans,(ed-st+1)*(far[j]-j+1));
			}
		}
	}
	printf("%d\n",glo_ans);
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
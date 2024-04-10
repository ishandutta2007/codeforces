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
int inf=0x3f3f3f3f;
db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
char str[555];
int n;
struct nd{
	int a,b,c,d,e;
	void rd(){
		gn(a);
		gn(b);
		gn(c);
		gn(d);
		gn(e);
	}
	int get(){
		return a+b*2+c*4+d*8;
	}
}no[55];

struct node{
	int l,r;
	char opt;
}t[511];int ndtot;

int f[511][65536];
int gao(int l,int r){
	if(l==r){
		int x=++ndtot;
		t[x].opt=str[l];
		return x;
	}else{
		int cu=1;
		int mid;
		rep(i,l+1,r+1){
			if(str[i]=='(' || str[i]==')'){
				if(str[i]=='(')cu++;
				else cu--;
			}
			if(cu==0){
				mid=i+1;
				break;
			}
		}
		int x=++ndtot;
		t[x].l=gao(l+1,mid-2);
		t[x].r=gao(mid+2,r-1);
		t[x].opt=str[mid];
		return x;
	}
}
int N=65536;
int K=16;
int a[65536],b[65536],gg[65536];
void meror(int *ta,int *tb,int *c){
	rep(i,0,N)a[i]=ta[i],b[i]=tb[i];
	rep(i,0,16)
		rep(j,0,N)if(j&pw(i)){
			upmo(a[j],a[j^pw(i)]);
			upmo(b[j],b[j^pw(i)]);
		}
	rep(i,0,N)c[i]=1ll*a[i]*b[i]%mo;
	rep(i,0,16)
		rep(j,0,N)if(j&pw(i)){
			upmo(c[j],-c[j^pw(i)]);
		}
}
void merand(int *ta,int *tb,int *c){
	rep(i,0,N)a[i]=ta[65535-i],b[i]=tb[65535-i];
	meror(a,b,gg);
	rep(i,0,N)c[i]=gg[65535-i];
}
int xxx[65536];
void dfs(int u){
	if(t[u].l==0 && t[u].r==0){
		if(t[u].opt=='?'){
			for (int va=0;va<=1;va++){
				for (int id=0;id<4;id++){
					int nd=0;
					rep(j,0,16){
						int an=((j>>id)&1)==va;
						nd|=an<<j;
					}
					f[u][nd]+=1;
				}
			}
		}else{
			int va=t[u].opt<='D';
			int id;
			if(va)id=t[u].opt-'A';
			else id=t[u].opt-'a';
			int nd=0;
			rep(j,0,16){
				int an=((j>>id)&1)==va;
				nd|=an<<j;
			}
			f[u][nd]+=1;
		}
	}else{
		dfs(t[u].l);
		dfs(t[u].r);
		if(t[u].opt=='|' || t[u].opt=='?'){
			meror(f[t[u].l],f[t[u].r],xxx);
			rep(i,0,65536)upmo(f[u][i],xxx[i]);
		}
		if(t[u].opt=='&' || t[u].opt=='?'){
			merand(f[t[u].l],f[t[u].r],xxx);
			rep(i,0,65536)upmo(f[u][i],xxx[i]);
		}
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	scanf("%s",str+1);
	int l=strlen(str+1);
	gn(n);
	rep(i,1,n+1)no[i].rd();

	int rt=gao(1,l);

	dfs(rt);

	int ans=0;
	rep(i,0,65536){
		int bo=1;
		rep(j,1,n+1){
			int su=no[j].get();
			if(((i>>su)&1)!=no[j].e){
				bo=0;
				break;
			}
		}
		if(bo)upmo(ans,f[rt][i]);
	}
	printf("%d\n",ans);

	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
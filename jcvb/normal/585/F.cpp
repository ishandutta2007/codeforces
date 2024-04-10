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
char str[1111];
char tmp[555];
int li[555],ri[555];
int d,nd;


struct node{
	int ch[10];
	int l,pre;
}t[2222];int ndtot=1,s=1,las=1;

int add(int c){
	int p=las,np=++ndtot;
	t[np].l=t[p].l+1;

	for(;p && !t[p].ch[c];p=t[p].pre)t[p].ch[c]=np;
	if(!p){
		t[np].pre=s;
	}else{
		int q=t[p].ch[c];
		if(t[q].l==t[p].l+1)t[np].pre=q;
		else{
			int nq=++ndtot;
			t[nq]=t[q];
			t[nq].l=t[p].l+1;
			t[q].pre=t[np].pre=nq;
			for(;p && t[p].ch[c]==q;p=t[p].pre)t[p].ch[c]=nq;
		}
	}
	
	return np;
}
int *a;
int f[55][2][55][2222][2];

int F(int i,int les,int len,int nod,int has){
	if(~f[i][les][len][nod][has])return f[i][les][len][nod][has];
	if(i==d) return has;

	int su=0;
	for (int j=0;j<=(les?9:a[i+1]);j++){
		int l=len,p=nod;
		while(p!=s && !t[p].ch[j])p=t[p].pre,upmin(l,t[p].l);
		if(t[p].ch[j])p=t[p].ch[j],l++;

		upmo(su,F(i+1,les || j<a[i+1],l,p,has || l>=nd));
	}

	return f[i][les][len][nod][has]=su;
}
int work(int *c){
	a=c;
	fil(f,-1);
	return F(0,0,0,1,0);
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	scanf("%s",str+1);
	scanf("%s",tmp+1);
	d=strlen(tmp+1);
	rep(i,1,d+1)li[i]=tmp[i]-'0';
	scanf("%s",tmp+1);
	d=strlen(tmp+1);
	rep(i,1,d+1)ri[i]=tmp[i]-'0';
	nd=d/2;

	int cur=d;
	while(li[cur]==0)li[cur]=9,cur--;
	li[cur]--;

	for (int i=1;str[i];i++)las=add(str[i]-'0');


	int ans=(work(ri)-work(li)+mo)%mo;
	printf("%d\n",ans);
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
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


int n;int m;
int mo1=982451653,mo2=982451707,mo3=998244353;
int se1[2222],se2[2222],se3[2222];
struct H{
	int h1[2222],h2[2222],h3[2222];
	void gen(char *s){
		h1[0]=h2[0]=h3[0]=0;
		rep(i,1,max(n,m)+1){
			h1[i]=(1ll*h1[i-1]*17173+s[i])%mo1;
			h2[i]=(1ll*h2[i-1]*799+s[i])%mo2;
			h3[i]=(1ll*h3[i-1]*677+s[i])%mo3;
		}
	}
};
inline bool eq(const H&ha,int l1,int r1,const H&hb,int l2,int r2){
	int a=((ha.h1[r1]-1ll*ha.h1[l1-1]*se1[r1-l1+1])-(hb.h1[r2]-1ll*hb.h1[l2-1]*se1[r2-l2+1]))%mo1;
	int b=((ha.h2[r1]-1ll*ha.h2[l1-1]*se2[r1-l1+1])-(hb.h2[r2]-1ll*hb.h2[l2-1]*se2[r2-l2+1]))%mo2;
	int c=((ha.h3[r1]-1ll*ha.h3[l1-1]*se3[r1-l1+1])-(hb.h3[r2]-1ll*hb.h3[l2-1]*se3[r2-l2+1]))%mo3;
	return a==0 && b==0 && c==0;
}
char a[2][2222];
char b[2222];
char rb[2222];
H ha[2],hb,hrb;

int f[2222][2222][4];


int work(){
	ha[0].gen(a[0]);	
	ha[1].gen(a[1]);	
	hb.gen(b);
	hrb.gen(rb);
	cl(f);
	rep(i,1,n+1){

		if(a[0][i]==b[1])upmo(f[i][1][0],1);
		if(a[1][i]==b[1])upmo(f[i][1][1],1);
		for (int j=4;j<=m && j<=2*i;j+=2){
			if(eq(ha[1],i-j/2+1,i,hrb,m-j/2+1,m) && eq(ha[0],i-j/2+1,i,hb,j/2+1,j))upmo(f[i][j][2],1);
			if(eq(ha[0],i-j/2+1,i,hrb,m-j/2+1,m) && eq(ha[1],i-j/2+1,i,hb,j/2+1,j))upmo(f[i][j][3],1);
		}
		rep(j,1,m){
			if(a[1][i]==b[j+1])upmo(f[i][j+1][3],f[i][j][0]);
			if(a[0][i]==b[j+1])upmo(f[i][j+1][2],f[i][j][1]);
		}
		if(i<n){
			rep(j,1,m){
				if(a[0][i+1]==b[j+1]){
					upmo(f[i+1][j+1][0],f[i][j][0]);
					upmo(f[i+1][j+1][0],f[i][j][2]);
				}
				if(a[1][i+1]==b[j+1]){
					upmo(f[i+1][j+1][1],f[i][j][1]);
					upmo(f[i+1][j+1][1],f[i][j][3]);
				}
			}
		}
	}
	int ans=0;
	f[0][0][0]=f[0][0][1]=0;
	rep(i,1,n+1){
		rep(j,0,m==2?3:4)upmo(ans,f[i][m][j]);

		for (int j=4;j<=m && j<=2*(n-i+1);j+=2){
			if(eq(ha[0],i,i+j/2-1,hb,m-j+1,m-j/2) && eq(ha[1],i,i+j/2-1,hrb,1,j/2)){
				upmo(ans,f[i-1][m-j][0]);
				upmo(ans,f[i-1][m-j][2]);
			}
			if(eq(ha[1],i,i+j/2-1,hb,m-j+1,m-j/2) && eq(ha[0],i,i+j/2-1,hrb,1,j/2)){
				upmo(ans,f[i-1][m-j][1]);
				upmo(ans,f[i-1][m-j][3]);
			}
		}
	}

	return ans;
}
int main()
{
	se1[0]=1;rep(i,1,2100)se1[i]=1ll*se1[i-1]*17173%mo1;
	se2[0]=1;rep(i,1,2100)se2[i]=1ll*se2[i-1]*799%mo2;
	se3[0]=1;rep(i,1,2100)se3[i]=1ll*se3[i-1]*677%mo3;
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	scanf("%s",a[0]+1);
	scanf("%s",a[1]+1);
	scanf("%s",b+1);
	n=strlen(a[0]+1);
	m=strlen(b+1);
	rep(i,1,m+1)rb[i]=b[m-i+1];


	int an=work();

	if(m>1){
		reverse(a[0]+1,a[0]+n+1);
		reverse(a[1]+1,a[1]+n+1);
		rep(i,1,n+1)swap(a[0][i],a[1][i]);
		upmo(an,work());
	}
	printf("%d\n",an);
	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
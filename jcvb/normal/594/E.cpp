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
char s[10111111];
int k,n;
int mi[5111111];
int mami[5111111];
int z[10111111];

int dbg=0;
void buildz(int n){
	z[1]=n;
	if(n<=1)return;
	z[n+1]='a'-1;
	while(s[2+z[2]]==s[1+z[2]])z[2]++;
	int a=2;
	for (int i=3;i<=n;i++){
		if(i<=a+z[a]-1){
			z[i]=min(a+z[a]-1-i+1,z[i-a+1]);
		}
		while(s[i+z[i]]==s[1+z[i]])z[i]++;
		if(i+z[i]>a+z[a])a=i;
	}
}
int zcmp(int i,int le){
	if(z[i]>=le)return 0;
	char a=s[1+z[i]],b=s[i+z[i]];
	if(a<b)return 1;
	return -1;
}
void init(){
	int i=1,j=2,k=0;
	s[n+1]='a'-2;
	int bo=0;
	int las=0,las2=0;
	while(i<=n){
		k=0;
		while(s[i+k]==s[j+k]){
			k++;
		}
		if(s[i+k]>s[j+k]){
			bo++;
			int d=j-i,e=i+k;
			do{
				i+=d;
				mi[i-1]=las+1;
				mami[i-1]=las2+1;
				las=i-1;
				if(dbg)printf("%d ",i-1);
			}while(i-1<e);
			las2=las;
			j=i+1;
		}else{
			j=j+k+1;
		}
	}
}

char ans[5111111];
char s2[5111111];
void doit(){
	rep(t,n+1,n+n+1)s[t]=s[t-n];
	s[n+n+1]=0;
	int i=1,j=2,k=0;
	while(j<=n){
		k=0;
		while(k<n && s[i+k]==s[j+k])k++;
		if(s[i+k]>s[j+k]){
			i=max(i+k+1,j);
			j=i+1;
		}else{
			j=j+k+1;
		}
	}
	int tmp=0;rep(t,i,i+n)ans[++tmp]=s[t];
	////////////
	rep(i,1,n+1)s2[i]=s[n-i+1];
	int bo=0;
	rep(i,1,n+1)if(ans[i]!=s2[i]){
		if(ans[i]>s2[i])bo=1;
		break;
	}
	if(bo)rep(i,1,n+1)ans[i]=s2[i];
	////////////
	bo=0;
	rep(i,1,n+1)if(ans[i]!=s[i]){
		if(ans[i]>s[i])bo=1;
		break;
	}
	if(bo)rep(i,1,n+1)ans[i]=s[i];
	//////////
	rep(i,1,n+1)s[n+i]=s2[i];
	buildz(2*n);
	int opt=1;
	rep(i,2,n){
		int ve=zcmp(2*n+1-i,i-opt);
		if(ve==1){
			opt=i;
		}else if(ve==0){
			ve=zcmp(i-opt+1,opt);
			if(ve==-1)opt=i;
		}
	}
	tmp=0;
	per(i,opt+1,n+1)s2[++tmp]=s[i];
	rep(i,1,opt+1)s2[++tmp]=s[i];
	bo=0;
	rep(i,1,n+1)if(ans[i]!=s2[i]){
		if(ans[i]>s2[i])bo=1;
		break;
	}
	if(bo)rep(i,1,n+1)ans[i]=s2[i];
	//////////
	init();
	tmp=0;
	rep(i,mi[n],n+1)s2[++tmp]=s[i];
	per(i,1,mi[n])s2[++tmp]=s[i];
	bo=0;
	rep(i,1,n+1)if(ans[i]!=s2[i]){
		if(ans[i]>s2[i])bo=1;
		break;
	}
	if(bo)rep(i,1,n+1)ans[i]=s2[i];


	s[++n]='z'+1;
	init();
	n--;
	tmp=0;
	rep(i,mami[n+1],n+1)s2[++tmp]=s[i];
	per(i,1,mami[n+1])s2[++tmp]=s[i];
	bo=0;
	rep(i,1,n+1)if(ans[i]!=s2[i]){
		if(ans[i]>s2[i])bo=1;
		break;
	}
	if(bo)rep(i,1,n+1)ans[i]=s2[i];


	rep(i,1,n+1)putchar(ans[i]);
	putchar('\n');
}

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	scanf("%s",s+1);
	n=strlen(s+1);
	gn(k);
	if(k==1){
		rep(i,1,n+1)s2[i]=s[n-i+1];
		int bo=0;
		rep(i,1,n+1)if(s[i]!=s2[i]){
			if(s[i]<s2[i]);
			else bo=1;
			break;
		}
		if(bo==0)
			printf("%s\n",s+1);
		else 
			printf("%s\n",s2+1);
		return 0;
	}
	if(strncmp(s+1,"aaabehbieifhddd",15)==0)dbg=1;
	dbg=0;
	if(dbg)printf("n=%d\n",n);
	for (int i=1;i<n-i+1;i++)swap(s[i],s[n-i+1]);
	init();
	int las=n;
	for (int t=k;t>2 && las;t--){
		int sst=mi[las],st=sst,le=las-sst+1;
		if(st==las){
			while(las>=1 && mi[las]==las)putchar(s[las]),las--;
		}else{
			while(st-le>=1){
				int bo=1;
				st-=le;
				rep(i,0,le){
					if(s[st+i]!=s[sst+i]){
						bo=0;
						break;
					}
				}
				if(bo==0){
					st+=le;
					break;
				}
			}
			rep(i,st,las+1)putchar(s[i]);
			las=st-1;
		}
	}
	if(las){
		n=las;
		doit();

	}
	putchar('\n');

	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
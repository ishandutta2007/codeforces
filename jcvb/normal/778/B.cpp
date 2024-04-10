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
//m bits

int outcome[11111][2];

map<string,int>id;


string get(){
	static char str[1111];
	if(scanf("%s",str)!=EOF){
		string tmp(str);
		return tmp;
	}else{
		string tmp;
		return tmp;
	}
}

string lis[55555];int listot=0;
int start[11111];

int op1[11111],op2[11111];
string opt[11111];


//0 : numer
int get(string &x){
	if(x[0]>='0' && x[0]<='9')return 0;
	else return	id[x];
}


int suan(int a,string b,int c){
	if(b[0]=='A')return a&c;
	else if(b[0]=='X')return a^c;
	else return a|c;
}
int res[51111];
int decide(int pos,int x){
	res[n+1]=x;
	rep(i,1,n+1){
		if(opt[i]!=""){
			int lef=op1[i]?res[op1[i]]:(lis[start[i]+2][pos]-'0');
			int rig=op2[i]?res[op2[i]]:(lis[start[i]+4][pos]-'0');
			res[i]=suan(lef,opt[i],rig);
		}else{
			int lef=op1[i]?res[op1[i]]:(lis[start[i]+2][pos]-'0');
			res[i]=lef;
		}
	}
	int sum=0;
	rep(i,1,n+1)sum+=res[i];
	return sum;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);


	while(1){
		string xx;
		xx=get();
		if(siz(xx)==0)break;
		lis[++listot]=xx;
	}

	int found=0;
	rep(i,1,listot+1){
		if(lis[i]==":="){
			start[++found]=i-1;
		}
	}
	id["?"]=n+1;
	start[n+1]=listot+1;
	rep(i,1,n+1){
		int l=start[i],r=start[i+1];
		id[lis[l]]=i;
		if(r-l==5){
			op1[i]=get(lis[l+2]);
			op2[i]=get(lis[l+4]);
			opt[i]=lis[l+3];
		}else{
			op1[i]=get(lis[l+2]);
			opt[i]="";
		}
	}

	rep(pos,0,m){
		outcome[pos][0]=decide(pos,0);
		outcome[pos][1]=decide(pos,1);
	}

	rep(i,0,m){
		if(outcome[i][0]<=outcome[i][1])printf("0");
		else printf("1");
	}
	printf("\n");
	rep(i,0,m){
		if(outcome[i][0]>=outcome[i][1])printf("0");
		else printf("1");
	}
	printf("\n");

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
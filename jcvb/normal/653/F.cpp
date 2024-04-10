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
const int inf=0x3f3f3f3f;
const db eps=1e-6;
int mo=1000000007;
int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}
char s[555555];
int n;
int a[555555];
bool blo[555555];
int dep[555555];

int las[555555];
int torig[555555];
vi occ[555555];

inline int gao(int id,int l,int r){
	if(l>r)return 0;
	return upper_bound(occ[id].begin(),occ[id].end(),r)-lower_bound(occ[id].begin(),occ[id].end(),l);
}


namespace suf{
///////////////////
#define MAXN 555005
#define SIZE 4 
///////////////////
int n,m=SIZE+1,s[MAXN],sa[MAXN],tmp1[MAXN],tmp2[MAXN],cnt[MAXN],*rk,h[MAXN];
void da(){
     int *x=tmp1,*y=tmp2,num,i,j,len;
     for (i=0;i<m;i++)cnt[i]=0;
     for (i=0;i<n;i++)cnt[s[i]]++;
     for (i=1;i<m;i++)cnt[i]+=cnt[i-1];
     for (i=n-1;i>=0;i--)sa[--cnt[s[i]]]=i;
     for (num=i=1,x[sa[0]]=0;i<n;i++)
         x[sa[i]]=s[sa[i-1]]==s[sa[i]]?num-1:num++;
     for (len=1;num<n;len<<=1){
         for (j=0;j<len;j++)y[j]=n-len+j;
         for (i=0;j<n;i++)if(sa[i]>=len)y[j++]=sa[i]-len;
        
         for (i=0;i<num;i++)cnt[i]=0;
         for (i=0;i<n;i++)cnt[x[i]]++;
         for (i=1;i<num;i++)cnt[i]+=cnt[i-1];
         for (i=n-1;i>=0;i--)sa[--cnt[x[y[i]]]]=y[i];
         
         swap(x,y);
         for (num=i=1,x[sa[0]]=0;i<n;i++)
             x[sa[i]]= y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+len]==y[sa[i]+len] ?num-1:num++;
     }
     rk=x;
}
void ch(){
     int i,j,l;
     for (i=l=0;i<n-1;h[rk[i++]]=l)
         for (l?l--:0,j=sa[rk[i]-1];s[j+l]==s[i+l];l++);
     h[0]=0;
}
	
///////////////////
};

int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	scanf("%s",s+1);
	rep(i,1,n+1)a[i]=s[i]=='('?+1:-1;
	int cur=0;
	rep(i,1,n+1){
		cur+=a[i];
		if(cur<0){
			blo[i]=1;
			cur=0;
		}
	}
	cur=0;
	per(i,1,n+1){
		//if(blo[i])continue;
		cur+=a[i];
		if(cur>0){
			blo[i]=1;
			cur=0;
		}
	}

	cur=0;
	rep(i,1,n+1){
		if(blo[i])continue;
		if(a[i]==1){
			cur++;
			dep[i]=cur;
		}else{
			dep[i]=cur;
			cur--;
		}
	}
	assert(cur==0);
	rep(i,1,n+1)if(blo[i])a[i]=0;

	las[0]=n+1;
	for (int i=n;i>=1;i--){
		if(a[i]==+1)torig[i]=las[dep[i]-1]-1;
		else{
			las[dep[i]]=i;
		}
	}
	for (int i=1;i<=n;i++)if(a[i]==-1)occ[dep[i]].pb(i);


	suf::n=n+1;
	rep(i,1,n+1){
		suf::s[i-1]=a[i]+2;
	}
	suf::s[n]=0;
	suf::da();
	suf::ch();
		
	ll ret=0;
	for (int i=1;i<=n;i++){
		int st=(suf::sa[i])+1;
		int hi=suf::h[i];
		if(a[st]!=1)continue;
		ret+=gao(dep[st],st+hi,torig[st]);
	}
	cout<<ret<<endl;
		
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
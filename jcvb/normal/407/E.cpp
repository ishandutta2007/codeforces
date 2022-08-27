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
//

typedef int seg_nu;
typedef int seg_tag;
const int SEG_MAXN=200000+5;

int seglen[SEG_MAXN*4];
seg_nu seg[SEG_MAXN*4];
seg_tag tag[SEG_MAXN*4];
seg_tag tag0 = 0;						//modify
inline void segadd(int x,seg_tag v){
	seg[x]=seg[x]+v;				//modify
	tag[x]=tag[x]+v;					//modify
}
inline void segpd(int x){
	if(tag[x]!=tag0){
		segadd(x<<1,tag[x]);
		segadd(x<<1|1,tag[x]);
		tag[x]=tag0;					
	}
}
inline void segpu(int x){
	seg[x]=min(seg[x<<1],seg[x<<1|1]);				//modify
}
void seginit_in(int l,int r,int x){
	tag[x]=tag0;						
	seglen[x]=r-l+1;
	if(l==r){
		//seg[x]=a[l];
		seg[x]=-l;					//modify
	}else{
		int mid=l+r>>1;
		seginit_in(l,mid,x<<1);
		seginit_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int l1,r1;
seg_nu sans; bool ans_bo;
seg_tag stag;
void segupd_in(int l,int r,int x){
	//if(l1>r1)return;
	if(l1<=l && r<=r1){
		segadd(x,stag);
	}else{
		int mid=l+r>>1;
		segpd(x);
		if(l1<=mid)segupd_in(l,mid,x<<1);
		if(r1>mid)segupd_in(mid+1,r,x<<1|1);
		segpu(x);
	}
}
int segn;
void segupd(int l,int r,seg_tag v){
	if(l>r)return;
	stag=v,l1=l,r1=r;
	segupd_in(1,segn,1);
}
void seginit(int n){
	segn=n;
	seginit_in(1,segn,1);
}
int n,k,d;

int a[222222];
int gloma=1,startl=1;

int fardif[222222];
map<int,int>cnt;
int ples[222222],pgre[222222];//next

int quma[222222],qumi[222222];
int topma,topmi;
void work(int l,int r){
	cnt.clear();
	int cur=l;
	rep(i,l,r+1){
		while(cur<=r && !cnt[a[cur]]){
			cnt[a[cur]]++;
			cur++;
		}
		fardif[i]=cur-1;
		cnt[a[i]]--;
	}
	int len=r-l+1;
	seginit(len);

	topma=topmi=0;
	quma[0]=qumi[0]=r+1;
	for (int i=r;i>=l;i--){
		if(i!=r){
			segupd(fardif[i]+1-l+1,fardif[i+1]-l+1,int(1e8));
		}
		while(topma && a[i]>a[quma[topma]]){
			segupd(quma[topma]-l+1,quma[topma-1]-1-l+1,-a[quma[topma]]);
			topma--;
		}
		quma[++topma]=i;
		segupd(quma[topma]-l+1,quma[topma-1]-1-l+1,a[quma[topma]]);

		while(topmi && a[i]<a[qumi[topmi]]){
			segupd(qumi[topmi]-l+1,qumi[topmi-1]-1-l+1,+a[qumi[topmi]]);
			topmi--;
		}
		qumi[++topmi]=i;
		segupd(qumi[topmi]-l+1,qumi[topmi-1]-1-l+1,-a[qumi[topmi]]);
		int le=1,ri=len,x=1;
		int val=k-(i-l+1);
		if(seg[x]<=val){
			while(le<ri){
				int mid=le+ri>>1;
				segpd(x);
				if(seg[x<<1|1]<=val){
					le=mid+1;
					x=x<<1|1;
				}else{
					ri=mid;
					x=x<<1;
				}
			}
			int ge=le-(i-l+1)+1;
			int star=i;
			if(ge>gloma)gloma=ge,startl=star;
			else if(ge==gloma)upmin(startl,star);
		}
	}
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(k);gn(d);
	rep(i,1,n+1)gn(a[i]);

	if(d==0){
		int las=1;
		rep(i,1,n+1){
			if(i==n || (a[i]-a[i+1])!=0){
				if(upmax(gloma,i-las+1))startl=las;
				las=i+1;
			}
		}
	}
	else{
		int las=1;
		rep(i,1,n+1){
			if(i==n || (a[i]-a[i+1])%d!=0){
				rep(j,las,i+1)a[j]=flo(a[j],d);
				work(las,i);
				las=i+1;
			}
		}
	}
	printf("%d %d\n",startl,startl+gloma-1);

#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
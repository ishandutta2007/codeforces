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
int n;
int a[222222];

int lef[222222],sle[222222];
int rig[222222],sri[222222];

void ins(int id,int num){
	if(id<lef[num]){
		sle[num]=lef[num];
		lef[num]=id;
	}else if(id<sle[num])sle[num]=id;

	if(id>rig[num]){
		sri[num]=rig[num];
		rig[num]=id;
	}else if(id>sri[num])sri[num]=id;
}
int M=200000;

struct intv{
	int l,r,x;
}in[666666];int itot=0;
int cmp(const intv&a,const intv&b){
	return a.r>b.r;
}



#define N 844444
int ma[N],mav[N],tag[N],cnt[N],sz[N];ll su[N];

#define ls (x<<1)
#define rs (x<<1|1)
void pu(int x){
    if(cnt[ls]+cnt[rs]==sz[x])tag[x]=inf;
    if(tag[x]==inf){
        cnt[x]=cnt[ls]+cnt[rs];
        su[x]=su[ls]+su[rs];
        mav[x]=min(mav[ls],mav[rs]);
    }else {
        cnt[x]=sz[x];
        su[x]=su[ls]+su[rs]+1ll*(sz[x]-cnt[ls]-cnt[rs])*tag[x];
        mav[x]=tag[x];
    }
    ma[x]=min(min(ma[ls],ma[rs]),tag[x]);
}
void del(int x,int v){//>v
    if(ma[x]>=v)return;
    tag[x]=inf;
    if(sz[x]>1){
        del(ls,v);
        del(rs,v);
        pu(x);
    }else{
        ma[x]=inf;
        mav[x]=0;
        cnt[x]=su[x]=0;
    }
}
void init(int l,int r,int x){
    tag[x]=inf;
    sz[x]=r-l+1;
    if(l==r){
	    tag[x]=0;
        su[x]=ma[x]=mav[x]=tag[x];
        cnt[x]=1;
    }else{
        int mid=l+r>>1;
        init(l,mid,x<<1);
        init(mid+1,r,x<<1|1);
        pu(x);
    }
}
int l1,r1,v;
ll ansu;

void cov(int x,int v){
    del(x,v);
    if(tag[x]==inf || v>tag[x])tag[x]=v;
    if(sz[x]>1)pu(x);
    else{
        mav[x]=su[x]=ma[x]=tag[x];
        cnt[x]=1;
    }
}
void upd(int l,int r,int x,int mi=0){
    if(tag[x]!=inf)mi=tag[x];
    if(v<=mi)return;
    if(l1<=l && r<=r1){
        cov(x,v);
    }else{
        int mid=l+r>>1;
        if(l1<=mid)upd(l,mid,x<<1);
        if(r1>mid)upd(mid+1,r,x<<1|1);
        pu(x);
    }
}
void que(int l,int r,int x,int mi=0){
    if(tag[x]!=inf)mi=tag[x];
    if(l1<=l && r<=r1){
        ansu+=su[x]+1ll*(sz[x]-cnt[x])*mi;
    }else{
        int mid=l+r>>1;
        if(l1<=mid)que(l,mid,x<<1,tag[x]!=inf?tag[x]:mi);
        if(r1>mid)que(mid+1,r,x<<1|1,tag[x]!=inf?tag[x]:mi);
    }
}


void inse(intv in){
	l1=in.l,r1=in.r;
	if(l1>r1)return;
	v=in.x;
	//debug("%d %d %d\n",l1,r1,v);
	upd(1,n,1);
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);
	rep(i,1,n+1)gn(a[i]);
	rep(i,1,M+1){
		lef[i]=sle[i]=n+1;
	}
	rep(i,1,n+1){
		int x=a[i];
		for (int j=1;j*j<=x;j++)if(x%j==0){
			ins(i,j);
			if(j*j!=x)ins(i,x/j);
		}
	}
	rep(i,1,M+1)if(sle[i]!=n+1){
		//debug("%d %d %d %d %d\n",i,lef[i],rig[i],sle[i],sri[i]);
		in[++itot]=(intv){lef[i]+1,rig[i]-1,i};
		in[++itot]=(intv){1,sri[i]-1,i};
		in[++itot]=(intv){sle[i]+1,n,i};
	}
	sort(in+1,in+1+itot,cmp);

	init(1,n,1);

	ll su=0;
	int cur=1;
	//debug("%d\n",itot);
	//rep(i,1,itot+1)debug("%d %d %d\n",in[i].l,in[i].r,in[i].x);
	for (int r=n;r>=1;r--){
		while(cur<itot && in[cur].r==r){
			inse(in[cur]);
			cur++;
		}
		ansu=0;
		l1=1,r1=r;
		que(1,n,1);
		su+=ansu;
	}
	cout<<su<<endl;



#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
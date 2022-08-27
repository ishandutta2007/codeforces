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
typedef long double db;
inline db sqr(db a){return a*a;}
const db inf=1e18;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-11;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

struct pkt{
	int x,y;
	void read(){gn(x);gn(y);}
	ll dissq(){return 1ll*x*x+1ll*y*y;}
	friend pkt operator+(const pkt&a,const pkt&b){return (pkt){a.x+b.x,a.y+b.y};}
	friend pkt operator-(const pkt&a,const pkt&b){return (pkt){a.x-b.x,a.y-b.y};}
	friend pkt operator-(const pkt&a){return (pkt){-a.x,-a.y};}
	friend ll dot(const pkt&a,const pkt&b){return 1ll*a.x*b.x+1ll*a.y*b.y;}
	friend ll cro(const pkt&a,const pkt&b){return 1ll*a.x*b.y-1ll*a.y*b.x;}
	friend bool operator<(const pkt&a,const pkt&b){return a.y==b.y?a.x<b.x:a.y<b.y;}
	/*friend bool operator<(const pkt&a,const pkt&b){
		int aa=a.y>0 || a.y==0&& a.x>0;
		int bb=b.y>0 || b.y==0&& b.x>0;
		if(aa!=bb)return aa<bb;
		else return cro(a,b)>0;
	}*/
}a[211111];

int len[211111];
int n,m;

struct inter{
	db l,r;
}in[5555555];int itot;

struct eve{
	db i;
	int del;
}e[1111111];int etot;

int cmp(const eve&a,const eve &b){
	return a.i<b.i;
}
void tiao(){
	while(itot>=2 && in[itot].l<in[itot-1].r+eps){
		assert(in[itot].l>in[itot-1].r-eps);
		in[itot-1].r=in[itot].r;
		itot--;
	}
}
inter jiao(inter a,inter b){
	return (inter){max(a.l,b.l),min(a.r,b.r)};
}
int curnum;
bool check(db d){
	itot=0;
	db seg=1.0*len[n]/m;

	int cur=0;
	rep(i,0,n){
		cur--;
		while(cur<i)cur++;
		while(len[cur]-len[i+1]<seg){
			db lef=max(db(len[i]),len[cur]-seg)-len[i];
			db rig=min(-seg+len[cur+1],db(len[i+1]))-len[i];

			int rax=0,ray=0,rbx=0,rby=0;

			if(a[i].x==a[i+1].x)ray=sgn(a[i+1].y-a[i].y);
			else rax=sgn(a[i+1].x-a[i].x);
			if(a[cur].x==a[cur+1].x)rby=sgn(a[cur+1].y-a[cur].y);
			else rbx=sgn(a[cur+1].x-a[cur].x);


			db xt=0,xc=0,yt=0,yc=0;
			xc+=a[i].x;
			yc+=a[i].y;
			xt+=rax;
			yt+=ray;
			//xc-=len[i]*rax;
			//yc-=len[i]*ray;
			xc-=a[cur].x;
			yc-=a[cur].y;
			xt-=rbx;
			yt-=rby;
			//xc-=(seg-len[cur])*rbx;
			//yc-=(seg-len[cur])*rby;
			xc-=(seg-len[cur]+len[i])*rbx;
			yc-=(seg-len[cur]+len[i])*rby;

			db A=sqr(xt)+sqr(yt);
			db B=2*(xt*xc+yt*yc);
			db C=sqr(xc)+sqr(yc)-sqr(d);
			if(A<eps){
				if(fabs(B)<eps){
					if(C<eps){
						if(lef<rig-eps) in[++itot]=(inter){len[i]+lef,len[i]+rig};
					}
				}else{
					inter tmp;
					if(B>0){
						tmp=jiao((inter){-inf,len[i]-C/B},(inter){len[i]+lef,len[i]+rig});
					}else{
						tmp=jiao((inter){len[i]-C/B,inf},(inter){len[i]+lef,len[i]+rig});
					}
					if(tmp.l<tmp.r-eps)in[++itot]=tmp;
				}
			}else{
				db del=B*B-4*A*C;
				if(del>0){
					del=sqrt(del);
					upmax(lef,(-B-del)/2/A);
					upmin(rig,(-B+del)/2/A);
					if(lef<rig-eps)in[++itot]=(inter){len[i]+lef,len[i]+rig};
				}
			}
			cur++;
			tiao();
		}
	}
	curnum=0;

	rep(i,1,itot+1){
		assert(in[i].l>=0);
		assert(in[i].r<=len[n]);
		if(i>1)assert(in[i].l>in[i-1].r+eps);
	}
	int now=1;
	rep(i,0,m){
		db pos=i*seg+seg*0.5;
		while(now<=itot && in[now].r<pos+eps)now++;
		if(now<=itot && in[now].l<pos+eps)curnum++;
	}
	etot=0;
	int id=0;
	rep(i,1,itot+1){
		while(id*seg+seg*0.5<in[i].l-eps)id++;
		if(fabs(in[i].l-in[itot].r+len[n])<eps)continue;
		e[++etot]=(eve){id*seg+seg*0.5-in[i].l,-1};
	}
	id=0;
	rep(i,1,itot+1){
		while(id*seg+seg*0.5<in[i].r-eps)id++;
		if(fabs(in[i].r-in[1].l-len[n])<eps)continue;
		e[++etot]=(eve){id*seg+seg*0.5-in[i].r,+1};
	}

	sort(e+1,e+1+etot,cmp);


	rep(i,1,etot+1){
		if(curnum>=m)return 1;
		curnum+=e[i].del;
	}
	if(curnum>=m)return 1;
	return 0;
}
int main()
{
#ifdef JCVB
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	gn(n);gn(m);
	rep(i,0,n){
		a[i].read();
	}
	rep(i,0,n){
		a[i+n]=a[i];
	}
	a[2*n]=a[n];//

	len[0]=0;
	rep(i,1,n+n+1){
		len[i]=len[i-1]+abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y);
	}

	db l=0.0,r=1e9;
	rep(_,0,70){
		db mid=(l+r)*0.5;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.6lf\n",double(l));
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}
#include<bits/stdc++.h>
#define ri register int
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef vector<int> poly;
#define pb push_back
const int rlen=1<<24,inf=1e9;
const ll Inf=1e16;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans,f;
  static char ch;
  ans=0,ch=gc(),f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline ll readl() {
  ll ans=0;
  bool f=1;
  char ch=gc();
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline int Read(char*s) {
  int tp=0;
  char ch=gc();
  while(!isdigit(ch)&&!isalpha(ch)) ch=gc();
  while(isdigit(ch)||isalpha(ch)) s[++tp]=ch,ch=gc();
  return tp;
}
namespace modular {
  const int mod=1e9+7;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { if(a<2) return a;int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
  inline int sqr(int a) { return mul(a,a); }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
}
using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T> inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
template<typename T> inline T Abs(T x) { return x<0?-x:x; }
template<typename T> inline void exgcd(T a,T b,T&x,T&y) {
  if(!b) { x=1,y=0;return; }
  exgcd(b,a-a/b*b,x,y);
  T t=x;
  x=y,y=t-a/b*y;
}
const int N=2e6+5;
int n,l;
ll X[N],Y[N];
#define EX cout<<"NO",exit(0)
struct atom {
  ll t,x,y,w,v;
  inline void read() {
    static ll _x,_y;
    t=readl(),_x=readl(),_y=readl();
    if((_x^_y^t)&1) EX;
    x=(_x+_y+t)>>1;
    y=(_y-_x+t)>>1;
    w=t%l,v=t/l;
  }
  friend inline bool operator<(atom a,atom b) { return a.w<b.w; }
}a[N];
inline void solve(ll*A) {
  ll dwn=0,upp=l;
  for(ri i=2;i<=n;++i) {
    ll dtv=a[i].v-a[i-1].v,dtw=a[i].w-a[i-1].w,dtx=a[i].x-a[i-1].x;
    if(!dtv) { if(dtx<0||dtx-dtw>0) EX; }
    else if(dtv>0) ckmax(dwn,(ll)ceil((double)(dtx-dtw)/dtv)),ckmin(upp,(ll)floor((double)dtx/dtv));
    else ckmax(dwn,(ll)ceil((double)dtx/dtv)),ckmin(upp,(ll)floor((double)(dtx-dtw)/dtv));
  }
  if(dwn>upp) EX;
  for(ri i=1;i<=l;++i) A[i]=Inf;
  A[l]=dwn;
  for(ri i=1;i<=n;++i) a[i].t%l?A[a[i].t%l]=a[i].x-a[i].v*dwn:0;
  for(ri i=1,pre=0;i<=l;++i) if(A[i]!=Inf) {
    if(A[pre]>A[i]) EX;
    for(ri ps=pre+1;ps<i;++ps) {
      A[ps]=A[ps-1];
      if(A[ps]<A[i]) ++A[ps];
    }
    if(A[i]-A[i-1]>1) EX;
    pre=i;
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),l=read();
  for(ri i=1;i<=n;++i) a[i].read();
  a[++n]=(atom) { 0,0,0,0,0 };
  a[++n]=(atom) { 0,0,0,l,-1 };
  sort(a+1,a+n+1);
  solve(X);
  for(ri i=1;i<=n;++i) swap(a[i].x,a[i].y);
  solve(Y);
  for(ri i=1;i<=l;++i) {
    if(X[i]==X[i-1]) {
      if(Y[i]==Y[i-1]) putchar('D');
      else putchar('L');
    }
    else {
      if(Y[i]==Y[i-1]) putchar('R');
      else putchar('U');
    }
  }
  return 0;
}
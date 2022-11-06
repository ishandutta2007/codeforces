#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
#define y2 cyktxdy
typedef long long ll;
typedef vector<int> poly;
typedef vector<ll> Poly;
typedef pair<int,int> pii;
#define pb push_back
#define fi first
#define se second
const int rlen=1<<18|1,inf=0x3f3f3f3f;
const ll Inf=1e18;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  bool f=1;
  char ch=gc();
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
  int top=0;
  char ch=gc();
  while(!isalpha(ch)&&!isdigit(ch)) ch=gc();
  while(isalpha(ch)||isdigit(ch)) s[++top]=ch,ch=gc();
  return top;
}
namespace modular {
  const int mod=1e9+7;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
  inline int sqr(int a) { return mul(a,a); }
  inline int cub(int a) { return mul(mul(a,a),a); }
}
using namespace modular;
template<typename T>inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T>inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T>inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
template<typename T>inline T Abs(T x) { return x<0?-x:x; }
const int N=2e5+5;
pii a[N],b[N];
struct node {
  int a,b,c;
  friend inline bool operator<(node a,node b) { return a.a<b.a; }
} c[N];
int n,m,K;
namespace sgt {
  const int N=1e6+5;
  #define lc (p<<1)
  #define rc (p<<1|1)
  #define mid ((l+r)>>1)
  ll mx[N<<2],tg[N<<2];
  inline void clear() { memset(mx,-0x3f,sizeof(mx)); }
  inline void pushup(int p) { mx[p]=max(mx[lc],mx[rc]); }
  inline void pushnow(int p,ll v) { mx[p]+=v,tg[p]+=v; }
  inline void pushdown(int p) {
    if(tg[p]) {
      pushnow(lc,tg[p]);
      pushnow(rc,tg[p]);
      tg[p]=0;
    }
  }
  inline void update(int p,int l,int r,int ql,int qr,ll v) {
    if(ql<=l&&r<=qr) return pushnow(p,v);
    pushdown(p);
    if(qr<=mid) update(lc,l,mid,ql,qr,v);
    else if(ql>mid) update(rc,mid+1,r,ql,qr,v);
    else update(lc,l,mid,ql,qr,v),update(rc,mid+1,r,ql,qr,v);
    pushup(p);
  }
  inline void modify(int p,int l,int r,int k,ll v) {
    if(l==r) return ckmax(mx[p],v);
    pushdown(p);
    k<=mid?modify(lc,l,mid,k,v):modify(rc,mid+1,r,k,v);
    pushup(p);
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),K=read();
  sgt::clear();
  for(ri i=1;i<=n;++i) a[i].fi=read(),a[i].se=read();
  for(ri i=1;i<=m;++i) b[i].fi=read(),b[i].se=read();
  for(ri i=1;i<=K;++i) {
    c[i].a=read(),c[i].b=read();
    c[i].c=read();
  }
  sort(a+1,a+n+1);
  sort(c+1,c+K+1);
  int mx=0;
  for(ri i=1;i<=m;++i) ckmax(mx,b[i].fi);
  for(ri i=1;i<=K;++i) ckmax(mx,c[i].b+1);
  for(ri i=1;i<=m;++i) sgt::modify(1,1,mx,b[i].fi,-b[i].se);
  ll ans=-Inf;
  for(ri i=1,ps=0;i<=n;++i) {
    while(ps<K&&c[ps+1].a<a[i].fi) {
      ++ps;
      sgt::update(1,1,mx,c[ps].b+1,mx,c[ps].c);
    }
    ckmax(ans,sgt::mx[1]-a[i].se);
  }
  cout<<ans;
  return 0;
}
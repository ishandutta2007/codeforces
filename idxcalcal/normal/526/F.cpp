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
  int tp=0;
  char ch=gc();
  while(!isdigit(ch)&&!isalpha(ch)) ch=gc();
  while(isdigit(ch)||isalpha(ch)) s[++tp]=ch,ch=gc();
  return tp;
}
namespace modular {
  const int mod=998244353;
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
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
const int N=3e5+5;
struct atom {
  int mn;
  ll cnt;
  atom(int mn=inf,ll cnt=0ll): mn(mn),cnt(cnt) {} 
  inline atom operator+(atom a) { return mn^a.mn?(mn<a.mn?*this:a):atom(mn,cnt+a.cnt); }
  inline atom operator+(ll dt) { return atom(mn+dt,cnt); }
};
namespace sgt {
  #define lc (p <<1)
  #define rc (p<<1|1)
  #define mid (l+r>>1)
  #define qll lc,l,mid
  #define qrr rc,mid+1,r
  ll dt[N<<2];
  atom vl[N<<2];
  inline void pushup(int p) { vl[p]=vl[lc]+vl[rc]; }
  inline void pushnow(int p,ll v) { vl[p]=vl[p]+v,dt[p]+=v; }
  inline void pushdown(int p) { if(dt[p]) pushnow(lc,dt[p]),pushnow(rc,dt[p]),dt[p]=0; }
  inline void build(int p,int l,int r) {
    if(l==r) { vl[p]=atom(0,1);return; }
    build(qll),build(qrr),pushup(p);
  }
  inline void update(int p,int l,int r,int ql,int qr,ll v) {
    if(ql<=l&&r<=qr) return pushnow(p,v);
    pushdown(p);
    if(qr<=mid) update(qll,ql,qr,v);
    else if(ql>mid) update(qrr,ql,qr,v);
    else update(qll,ql,qr,v),update(qrr,ql,qr,v);
    pushup(p);
  }
  #undef lc
  #undef rc
  #undef mid
  #undef qll
  #undef qrr
}
int smx[N],tpmx=0,smn[N],tpmn=0,a[N],n;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  for(ri x,i=1;i<=n;++i) x=read(),a[x]=read();
  sgt::build(1,1,n);
  ll res=0;
  for(ri ps,i=1;i<=n;++i) {
    sgt::update(1,1,n,1,i,-1);
    while(tpmx&&a[smx[tpmx]]<a[i]) {
      sgt::update(1,1,n,smx[tpmx-1]+1,smx[tpmx],a[i]-a[smx[tpmx]]);
      --tpmx;
    }
    smx[++tpmx]=i;
    while(tpmn&&a[smn[tpmn]]>a[i]) {
      sgt::update(1,1,n,smn[tpmn-1]+1,smn[tpmn],a[smn[tpmn]]-a[i]);
      --tpmn;
    }
    smn[++tpmn]=i;
    res+=sgt::vl[1].cnt;
  }
  cout<<res;
  return 0;
}
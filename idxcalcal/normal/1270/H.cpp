#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() getchar()
inline int read() {
  int ans=0;
  char ch=gc();
  bool f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline ll readl() {
  ll ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
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
}
const int N=1e6+5;
int n,m,a[N];
bool vs[N];
namespace sgt {
  #define lc (p<<1)
  #define rc (p<<1|1)
  #define mid (l+r>>1)
  int mn[N<<2],ct[N<<2],tg[N<<2];
  inline void pushnow(int p,int v) { tg[p]+=v,mn[p]+=v; }
  inline void pushdown(int p) { if(tg[p]) pushnow(lc,tg[p]),pushnow(rc,tg[p]),tg[p]=0; }
  inline void pushup(int p) {
    mn[p]=min(mn[lc],mn[rc]);
    ct[p]=(mn[lc]==mn[p]?ct[lc]:0)+(mn[rc]==mn[p]?ct[rc]:0);
  }
  inline void build(int p,int l,int r) {
    mn[p]=0x3f3f3f3f,ct[p]=tg[p]=0;
    if(l==r) {
      if(vs[l]) mn[p]=0;
      ct[p]=1;
      return;
    }
    build(lc,l,mid),build(rc,mid+1,r);
    pushup(p);
  }
  inline void update(int p,int l,int r,int ql,int qr,int v) {
    if(ql<=l&&r<=qr) return pushnow(p,v);
    pushdown(p);
    if(qr<=mid) update(lc,l,mid,ql,qr,v);
    else if(ql>mid) update(rc,mid+1,r,ql,qr,v);
    else update(lc,l,mid,ql,qr,v),update(rc,mid+1,r,ql,qr,v);
    pushup(p);
  }
  #undef lc
  #undef rc
  #undef mid
}
const int L=0,R=1e6;
inline void update(int ps,int coe) { sgt::update(1,L,R,min(a[ps],a[ps-1]),max(a[ps],a[ps-1])-1,coe); }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  a[0]=1000001,a[n+1]=0;
  for(ri i=1;i<=n;++i) a[i]=read(),vs[a[i]]=1;
  sgt::build(1,L,R);
  for(ri i=1;i<=n+1;++i) update(i,1);
  for(ri i=1,ps,vl;i<=m;++i) {
    ps=read(),vl=read();
    update(ps,-1),update(ps+1,-1);
    sgt::update(1,L,R,a[ps],a[ps],0x3f3f3f3f);
    a[ps]=vl;
    sgt::update(1,L,R,a[ps],a[ps],-0x3f3f3f3f);
    update(ps,1),update(ps+1,1);
    cout<<sgt::ct[1]<<'\n';
  }
  return 0;
}
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
template<typename T> inline T gcd(T a,T b) { T t;while(b)t=a,a=b,b=t-t/a*a;return a; }
template<typename T> inline T Abs(T x) { return x<0?-x:x; }
inline int rd() { return rand()|(rand()<<15); }
const int N=3e5+5;
int n,a[N],ps[N],qry[N];
struct node { int sum,pre,suf; };
inline node operator+(node a,node b) {
  node ret;
  ret.sum=a.sum+b.sum;
  ret.pre=max(a.pre,a.sum+b.pre);
  ret.suf=min(a.suf+b.sum,b.suf);
  return ret;
}
namespace sgt {
  #define lc (p<<1)
  #define rc (p<<1|1)
  #define mid ((l+r)>>1)
  node t[N<<2];
  inline void update(int p,int l,int r,int k,int x) {
    if(l==r) {
      t[p].sum+=x;
      t[p].pre=max(t[p].sum,0);
      t[p].suf=min(t[p].sum,0);
      return;
    }
    k<=mid?update(lc,l,mid,k,x):update(rc,mid+1,r,k,x);
    t[p]=t[lc]+t[rc];
  }
  inline node query(int p,int l,int r,int ql,int qr) {
    if(ql<=l&&r<=qr) return t[p];
    if(qr<=mid) return query(lc,l,mid,ql,qr);
    if(ql>mid) return query(rc,mid+1,r,ql,qr);
    return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
  }
  #undef lc
  #undef rc
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  for(ri i=1;i<=n;++i) ps[a[i]=read()]=i;
  for(ri i=1;i<=n;++i) qry[i]=read();
  int res=n;
  for(ri t,pss,prr,i=1;i<=n;++i) {
    cout<<res<<' ';
    if(i==n) break;
    sgt::update(1,1,n,qry[i],1);
    while(1) {
      t=(pss=ps[res])==1?0:(sgt::query(1,1,n,1,pss-1).suf);
      prr=(sgt::query(1,1,n,pss,n).pre)+t;
      if(prr<=0) break;
      sgt::update(1,1,n,pss,-1);
      --res;
    }
  }
  return 0;
}
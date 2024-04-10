#include<bits/stdc++.h>
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
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
const int N=2e5+5;
int n,m,K,a[N],vl[N],cnt[N],sig=0;
inline int find(int x) { return lower_bound(vl+1,vl+sig+1,x)-vl; }
struct Ntt {
  int mod,g,lim,tim,w[21],invv[21];
  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b) { return (ll)a*b%mod; }
  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
  inline int Inv(int a) { return ksm(a,mod-2); }
  vector<int>rev[21];
  inline void init_ntt() {
    invv[0]=1;
    for(ri i=1,iv=mod+1>>1;i<21;++i) invv[i]=mul(invv[i-1],iv);
    w[20]=ksm(g,(mod-1)>>21);
    for(ri i=19;~i;--i) w[i]=mul(w[i+1],w[i+1]);
  }
  inline void init(int up) {
    lim=1,tim=0;
    while(lim<up) lim<<=1,++tim;
    if(rev[tim].size()) return;
    rev[tim].resize(lim);
    for(ri i=1;i<lim;++i) rev[tim][i]=(rev[tim][i>>1]>>1)|((i&1)<<(tim-1));
  }
  inline void ntt(poly&a,int typ) {
    for(ri i=1;i<lim;++i) if(i<rev[tim][i]) swap(a[i],a[rev[tim][i]]);
    for(ri i=1,t=0,a0,a1,mt;i<lim;i<<=1,++t) for(ri j=0,len=i<<1;j<lim;j+=len) {
      mt=1;
      for(ri k=0;k<i;++k,Mul(mt,w[t])) {
        a0=a[j+k],a1=mul(a[j+k+i],mt);
        a[j+k]=add(a0,a1),a[j+k+i]=dec(a0,a1);
      }
    }
    if(~typ) return;
    reverse(++a.begin(),a.end());
    for(ri i=0;i<lim;++i) Mul(a[i],invv[tim]);
  }
  inline poly poly_mul(poly a,poly b) {
    int n=(int)a.size(),m=(int)b.size(),t=n+m-1;
    init(t);
    a.resize(lim),ntt(a,1);
    b.resize(lim),ntt(b,1);
    for(ri i=0;i<lim;++i) Mul(a[i],b[i]);
    return ntt(a,-1),a.resize(t),a;
  }
}A,B;
const int mod=1009;
int iv1,iv2;
inline ll mul(ll a,ll b,ll mod) { return a*b-(ll)((long double)a/mod*b+1e-8)*mod; }
inline int merge(int x,int y) {
  ll md=(ll)A.mod*B.mod;
  return (mul(x,(ll)B.mod*iv1%md,md)+mul(y,(ll)A.mod*iv2%md,md))%md%mod;
}
inline poly operator*(poly a,poly b) {
  int n=(int)a.size(),m=(int)b.size(),t=n+m-1;
  if(t<=128) {
    poly c(t);
    for(ri i=0;i<n;++i) if(a[i]) for(ri j=0;j<m;++j) {
      c[i+j]+=a[i]*b[j];
      if(c[i+j]>=100000000) c[i+j]%=mod;
    }
    for(ri i=0;i<t;++i) c[i]%=mod;
    return c;
  }
  poly _a=A.poly_mul(a,b),_b=B.poly_mul(a,b);
  a.resize(t);
  for(ri i=0;i<t;++i) a[i]=merge(_a[i],_b[i]);
  return a;
}
inline poly getpoly(int x) { return poly(x+1,1); }
poly f[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  A.mod=998244353,A.g=3,A.init_ntt();
  B.mod=1004535809,B.g=3,B.init_ntt();
  iv1=A.Inv(B.mod),iv2=B.Inv(A.mod);
  n=read(),m=read(),K=read();
  for(ri i=1;i<=n;++i) a[i]=vl[++sig]=read();
  sort(vl+1,vl+sig+1),sig=unique(vl+1,vl+sig+1)-vl-1;
  for(ri i=1;i<=n;++i) ++cnt[find(a[i])];
  priority_queue<pii,vector<pii>,greater<pii> >q;
  for(ri i=1;i<=sig;++i) {
    f[i]=getpoly(cnt[i]);
    q.push(pii(cnt[i],i));
  }
  pii fa,fb;
  while((int)q.size()>1) {
    fa=q.top(),q.pop();
    fb=q.top(),q.pop();
    f[fa.se]=f[fa.se]*f[fb.se];
    f[fb.se].resize(0);
    q.push(pii(fa.fi+fb.fi,fa.se));
  }
  cout<<f[q.top().se][K];
  return 0;
}
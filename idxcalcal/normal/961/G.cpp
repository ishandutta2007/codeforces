#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
#define pb push_back
#define fi first
#define se second
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
struct cp {
  double x,y;
  cp(double x=0,double y=0):x(x),y(y) {}
  friend inline cp operator+(cp a,cp b) { return cp(a.x+b.x,a.y+b.y); }
  friend inline void operator+=(cp&a,cp b) { a=a+b; }
  friend inline cp operator-(cp a,cp b) { return cp(a.x-b.x,a.y-b.y); }
  friend inline void operator-=(cp&a,cp b) { a=a-b; }
  friend inline cp operator*(cp a,cp b) { return cp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x); }
  friend inline void operator*=(cp&a,cp b) { a=a*b; }
  friend inline cp operator*(cp a,double b) { return cp(a.x*b,a.y*b); }
  friend inline void operator*=(cp&a,double b) { a=a*b; }
  friend inline cp operator/(cp a,double b) { return cp(a.x/b,a.y/b); }
  friend inline void operator/=(cp&a,double b) { a=a/b; }
  inline cp operator~() const { return cp(x,-y); }
};
typedef vector<cp> moly;
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
using namespace modular;
int lim,tim,inv[1<<20];
vector<int>rev[21];
vector<cp>w[21];
const double pi=acos(-1.0);
inline void init_fft() {
  inv[1]=1;
  for(ri i=2,up=1<<20;i<up;++i) inv[i]=mul(inv[mod-mod/i*i],mod-mod/i);
  w[20].resize(1<<20);
  for(ri i=0,lm=1<<20;i<lm;++i) w[20][i]=cp(cos(pi/lm*i),sin(pi/lm*i));
  for(ri i=19;~i;--i) {
    w[i].resize(1<<i);
    for(ri j=0,lm=1<<i;j<lm;++j) w[i][j]=w[i+1][j<<1];
  }
}
inline void init(int up) {
  lim=1,tim=0;
  while(lim<up) lim<<=1,++tim;
  if(rev[tim].size()) return;
  rev[tim].resize(lim);
  for(ri i=1;i<lim;++i) rev[tim][i]=(rev[tim][i>>1]>>1)|((i&1)<<(tim-1));
}
inline void fft(moly&a,int typ) {
  for(ri i=1;i<lim;++i) if(i<rev[tim][i]) swap(a[i],a[rev[tim][i]]);
  cp a0,a1;
  for(ri i=1,t=0;i<lim;i<<=1,++t) for(ri j=0;j<lim;j+=i<<1) for(ri k=0;k<i;++k) {
    a0=a[j+k],a1=a[j+k+i]*w[t][k];
    a[j+k]=a0+a1,a[j+k+i]=a0-a1;
  }
  if(~typ) return;
  reverse(++a.begin(),a.end());
  for(ri i=0;i<lim;++i) a[i]/=lim;
}
const int blo=(1<<15)-1;
inline poly operator*(poly a,poly b) {
  int n=(int)a.size(),m=(int)b.size(),t=n+m-1;
  poly c(t);
  if(t<=128) {
    for(ri i=0;i<n;++i) if(a[i]) for(ri j=0;j<m;++j) Add(c[i+j],mul(a[i],b[j]));
    return c;
  }
  init(t);
  moly P(lim),Q(lim),A(lim),B(lim);
  for(ri i=0;i<n;++i) P[i]=cp(a[i]>>15,a[i]&blo);
  for(ri i=0;i<m;++i) Q[i]=cp(b[i]>>15,b[i]&blo);
  fft(P,1),fft(Q,1);
  cp cur[4];
  for(ri i=0,j=0;i<lim;++i,j=j?j-1:lim-1) {
    cur[0]=(P[i]+(~P[j]))*cp(0.5,0);
    cur[1]=((~P[j])-P[i])*cp(0,0.5);
    cur[2]=(Q[i]+(~Q[j]))*cp(0.5,0);
    cur[3]=((~Q[j])-Q[i])*cp(0,0.5);
    A[i]=cur[0]*cur[2]+cp(0,1)*cur[1]*cur[3];
    B[i]=cur[0]*cur[3]+cp(0,1)*cur[1]*cur[2];
  }
  fft(A,-1),fft(B,-1);
  ll cr[4];
  for(ri i=0;i<t;++i) {
    cr[0]=(ll)(A[i].x+0.5)%mod;
    cr[1]=(ll)(A[i].y+0.5)%mod;
    cr[2]=(ll)(B[i].x+0.5)%mod;
    cr[3]=(ll)(B[i].y+0.5)%mod;
    c[i]=((cr[0]<<30)+((cr[2]+cr[3])<<15)+cr[1])%mod;
  }
  return c;
}
inline poly poly_inv(poly a,int K) {
  poly b(1,Inv(a[0])),c;
  for(ri i=1;i<K;i<<=1) {
    c=a,c.resize(i<<1);
    c=c*b,c.resize(i<<1);
    for(ri j=0;j<(i<<1);++j) c[j]=dec(j?0:2,c[j]);
    b=b*c,b.resize(i<<1);
  }
  return b.resize(K),b;
}
inline poly poly_shiftr(poly a,int K) {
  poly res(K,0);
  for(ri i=0;i<(int)a.size();++i) res.pb(a[i]);
  return res;
}
const int N=2e5+5;
int fac[N],ifac[N],n,K,a[N];
inline int C(int n,int m) { return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m])); }
inline void init() {
  fac[0]=fac[1]=ifac[0]=ifac[1]=1;
  for(ri i=2;i<=n;++i) {
    fac[i]=mul(fac[i-1],i);
    ifac[i]=mul(ifac[i-1],inv[i]);
  }
}
inline poly solve(int l,int r) {
  if(l==r) {
    poly res(2,1);
    res[1]=mod-l;
    return res;
  }
  int mid=l+r>>1;
  return solve(l,mid)*solve(mid+1,r);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),K=read();
  int ss=0;
  for(ri i=1;i<=n;++i) a[i]=read(),Add(ss,a[i]);
  if(K==1) return cout<<mul(n,ss),0;
  init_fft(),init();
  poly F=poly_shiftr(poly_inv(solve(1,K-1),n+1),K-1);
  int res=0;
  for(ri i=1,t;i<=n;++i) t=mul(mul(F[n-i],C(n-1,i-1)),mul(i,ss)),Add(res,t);
  cout<<res;
  return 0;
}
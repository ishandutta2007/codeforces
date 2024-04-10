#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
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
typedef vector<cp> polyr;
const int blo=(1<<15)-1;
int lim,tim;
vector<cp> w[20];
vector<int> rev[20];
const double pi=acos(-1.0);
inline void init_fft() {
  w[19].resize(1<<19);
  for(ri i=0,lm=1<<19;i<lm;++i) w[19][i]=cp(cos(pi/lm*i),sin(pi/lm*i));
  for(ri i=18;~i;--i) {
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
inline void fft(polyr&a,int typ) {
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
inline poly operator*(poly a,poly b) {
  int n=(int)a.size(),m=(int)b.size(),t=n+m-1;
  poly c(t);
  init(t);
  polyr A(lim),B(lim),P(lim),Q(lim);
  for(ri i=0;i<n;++i) A[i]=cp(a[i]>>15,a[i]&blo);
  for(ri i=0;i<m;++i) B[i]=cp(b[i]>>15,b[i]&blo);
  fft(A,1),fft(B,1);
  cp cur[4];
  for(ri i=0,j=0;i<lim;++i,j=j?j-1:lim-1) {
    cur[0]=(A[i]+(~A[j]))*cp(0.5,0);
    cur[1]=((~A[j])-A[i])*cp(0,0.5);
    cur[2]=(B[i]+(~B[j]))*cp(0.5,0);
    cur[3]=((~B[j])-B[i])*cp(0,0.5);
    P[i]=cur[0]*cur[2]+cp(0,1)*cur[1]*cur[3];
    Q[i]=cur[0]*cur[3]+cp(0,1)*cur[1]*cur[2];
  }
  fft(P,-1),fft(Q,-1);
  ll cr[4];
  for(ri i=0;i<t;++i) {
    cr[0]=(ll)(P[i].x+0.5)%mod;
    cr[1]=(ll)(P[i].y+0.5)%mod;
    cr[2]=(ll)(Q[i].x+0.5)%mod;
    cr[3]=(ll)(Q[i].y+0.5)%mod;
    c[i]=((cr[0]<<30)+(cr[2]+cr[3]<<15)+cr[1])%mod;
  }
  return c;
}
const int N=30005;
ll n;
int fac[N],ifac[N],K,pw1[N<<1],pw2[N<<1];
inline int getpw(int x) { return mul(pw1[x%blo],pw2[x/blo]); };
inline void init() {
  fac[0]=fac[1]=ifac[0]=ifac[1]=1;
  for(ri i=2;i<=K;++i) {
    fac[i]=mul(fac[i-1],i);
    ifac[i]=mul(ifac[mod-mod/i*i],mod-mod/i);
  }
  for(ri i=2;i<=K;++i) Mul(ifac[i],ifac[i-1]);
  pw1[0]=pw2[0]=1;
  for(ri i=1;i<=blo;++i) pw1[i]=add(pw1[i-1],pw1[i-1]);
  for(ri i=1;i<=blo;++i) pw2[i]=mul(pw2[i-1],pw1[blo]);
}
inline int C(int n,int m) { return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m])); }
inline poly poly_mul(poly a,poly b,int len) {
  for(ri i=0,n=(int)a.size();i<n;++i) Mul(a[i],getpw((ll)i*len%(mod-1)));
  return a*b;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  cin>>n>>K;
  if(n>K) return cout<<0,0;
  init(),init_fft();
  poly res,a(K+1);
  for(ri i=1;i<=K;++i) a[i]=ifac[i];
  res=a,--n;
  for(ri len=1;n;n>>=1,a=poly_mul(a,a,len),a.resize(K+1),len<<=1) if(n&1) {
    res=poly_mul(res,a,len);
    res.resize(K+1);
  }
  int ss=0;
  for(ri i=0;i<=K;++i) Add(ss,mul(res[i],ifac[K-i]));
  cout<<mul(ss,fac[K]);
  return 0;
}
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
}
using namespace modular;
template<typename T>inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T>inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T>inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
const double eps=1e-8;
//Math
/*
int fac[N],ifac[N],inv[N];
inline int C(int n,int m) { return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m])); }
inline void init_fac(int up) {
  fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
  for(ri i=2;i<=up;++i) {
    fac[i]=mul(fac[i-1],i);
    inv[i]=mul(inv[mod-mod/i*i],mod-mod/i);
    ifac[i]=mul(ifac[i-1],inv[i]);
  }
}
*/
const int N=5005;
int n,m,s[N],f[N],h[N],ss[N][N],pw[N];
vector<int>ps[N],a[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  pw[0]=1;
  for(ri i=1;i<=max(n,m);++i) pw[i]=add(pw[i-1],pw[i-1]);
  for(ri i=1;i<=n;++i) s[i]=read(),ps[s[i]].pb(i);
  for(ri i=1;i<=m;++i) f[i]=read(),h[i]=read(),a[f[i]].pb(h[i]);
  int mx=0,res=1;
  for(ri i=1;i<=n;++i) sort(a[i].begin(),a[i].end());
  for(ri ct1,ct2,ct3,curs=0,mt=1,i=1;i<=n;++i) {
    curs=0,mt=1;
    bool ff=0;
    for(ri j=1,X,Y;j<=n;++j) if((int)a[j].size()) {
      X=a[j].size(),Y=ps[j].size();
      ct1=ct2=ct3=0;
      bool ban=0;
      for(ri f1,f2,k=0;k<X;++k) if(a[j][k]<=Y) {
        if(ps[j][a[j][k]-1]==i) ban=1;
        else {
          f1=ps[j][a[j][k]-1]<=i;
          f2=ps[j][Y-a[j][k]]>i;
          if(f1&&f2) ++ct3;
          else if(f1) ++ct1;
          else if(f2) ++ct2;
        }
      }
      int x1=ct3*(ct3-1+ct1+ct2)+ct1*ct2,x2=ct2+ct1+ct3*2;
      if(ban) ff=1,x1=ct3+ct2,x2=1;
      if(x1) curs+=2,Mul(mt,x1);
      else if(x2) ++curs,Mul(mt,x2);
      else Mul(mt,1);
    }
    if(ff&&mt) {
      if(mx<curs) mx=curs,res=mt;
      else if(mx==curs) Add(res,mt);
    }
  }
  for(ri ct1,ct2,ct3,curs=0,mt=1,i=n;i;--i) {
    curs=0,mt=1;
    bool ff=0;
    for(ri j=1,X,Y;j<=n;++j) if((int)a[j].size()) {
      X=a[j].size(),Y=ps[j].size();
      ct1=ct2=ct3=0;
      bool ban=0;
      for(ri f1,f2,k=0;k<X;++k) if(a[j][k]<=Y) {
        if(ps[j][Y-a[j][k]]==i) ban=1;
        else {
          f1=ps[j][a[j][k]-1]<i;
          f2=ps[j][Y-a[j][k]]>=i;
          if(f1&&f2) ++ct3;
          else if(f1) ++ct1;
          else if(f2) ++ct2;
        }
      }
      int x1=ct2+ct3;
      if(ban) ff=1,x1=1;
      if(x1) curs+=1,Mul(mt,x1);
    }
    if(ff) {
      if(mx<curs) mx=curs,res=mt;
      else if(mx==curs) Add(res,mt);
    }
  }
  cout<<mx<<' '<<res;
  return 0;
}
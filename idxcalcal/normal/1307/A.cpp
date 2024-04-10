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
const int N=105;
int n,a[N],d;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read(),d;tt;--tt) {
    n=read(),d=read();
    for(ri i=1;i<=n;++i) a[i]=read();
    for(;d;--d) {
      for(ri j=2;j<=n;++j) {
        if(a[j]) {
          --a[j],++a[j-1];
          break;
        }
      }
    }
    cout<<a[1]<<'\n';
  }
  return 0;
}
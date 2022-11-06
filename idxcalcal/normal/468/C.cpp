#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define pb push_back
#define rez resize
const ll Inf=1e18;
const int rlen=1<<20;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans;
  static char ch;
  ans=0,ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline ll readl() {
  static ll ans;
  static char ch;
  ans=0,ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return ans;
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
  inline int sqr(int a) { return (ll)a*a%mod; }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
} using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
ll X;
inline ll mul(ll a,ll b,ll mod) {
  if(a>=mod) a%=mod;
  if(b>=mod) b%=mod;
  return a*b-(ll)((long double)a/mod*b+1e-8)*mod;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  cin>>X;
  ll pw=45%X,mt=10;
  for(ri l=1;;++l) {
    ll ss=mul(pw,l,X);
    if(!ss) {
      cout<<1<<' ';
      for(ri i=1;i<=l;++i) cout<<9;
      return 0;
    }
    if(X-ss<=mt) {
      cout<<max(X-ss,1ll)<<' '<<mt+X-ss-1;
      return 0;
    }
    pw=mul(pw,10,X);
    mt*=10;
  }
  return 0;
}
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
  while(!isdigit(ch)) {
    if(ch=='\n') return -1;
    f^=ch=='-',ch=gc();
  }
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
inline int Read(int*s) {
  int top=0,t;
  while(~(t=read())) s[++top]=t;
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
  inline int ksm(int a,ll p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
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
int n;
ll a[N],ans;
vector<ll>divv,ss;
inline void init(ll x) {
  divv.clear(),ss.clear();
  for(ri i=2,lm=sqrt(x);x!=1&&i<=lm;++i) if(x%i==0) {
    while(x%i==0) x/=i;
    divv.pb(i),ss.pb(0);
  }
  if(x!=1) divv.pb(x),ss.pb(0);
}
inline void update() {
  for(ri i=1;i<=n;++i) {
    for(ri j=(int)divv.size()-1;~j;--j) {
      if(a[i]<divv[j]) ss[j]+=divv[j]-a[i];
      else {
        ll t=a[i]%divv[j];
        ss[j]+=min(t,divv[j]-t);
      }
    }
  }
  for(ri i=(int)ss.size()-1;~i;--i) ckmin(ans,ss[i]);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  ans=0;
  for(ri i=1;i<=n;++i) a[i]=readl(),ans+=a[i]&1;
  random_shuffle(a+1,a+n+1);
  for(ri i=1;i<=50&&i<=n;++i) for(ri j=-1;j<2;++j) {
    init(max(a[i]+j,1ll));
    update();
  }
  cout<<ans;
  return 0;
}
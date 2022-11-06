#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
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
  const int mod=1e9+7;
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
template<typename T> inline void gcd(T a,T b) { T t;while(b)t=a,a=b,b=t-t/a*a;return a; }
template<typename T> inline T Abs(T x) { return x<0?-x:x; }
const int N=105;
int n,K,dis[N][N],f[N][N];
vector<int>L,R;
inline int rd() { return rand()|(rand()<<15); }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  srand(time(0));
  n=read(),K=read();
  for(ri i=1;i<=n;++i) for(ri j=1;j<=n;++j) dis[i][j]=read();
  int res=inf;
  for(ri tt=10000;tt;--tt) {
    L.resize(0),R.resize(0);
    L.pb(1);
    for(ri i=2;i<=n;++i) if(rd()&1) L.pb(i); else R.pb(i);
    if(!R.size()) { ++tt;continue; }
    for(ri i=0;i<=K;++i) for(ri j=1;j<=n;++j) f[i][j]=inf;
    f[0][1]=0;
    for(ri t=0;t<K;++t) {
      swap(L,R);
      for(ri i=0;i<R.size();++i) if(f[t][R[i]]!=inf)
      for(ri j=0;j<L.size();++j) ckmin(f[t+1][L[j]],f[t][R[i]]+dis[R[i]][L[j]]);
    }
    ckmin(res,f[K][1]);
  }
  cout<<res;
  return 0;
}
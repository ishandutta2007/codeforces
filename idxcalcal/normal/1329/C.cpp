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
  int mod;
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
template<typename T> inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
template<typename T> inline T Abs(T x) { return x<0?-x:x; }
template<typename T> inline void exgcd(T a,T b,T&x,T&y) {
  if(!b) { x=1,y=0;return; }
  exgcd(b,a-a/b*b,x,y);
  T t=x;
  x=y,y=t-a/b*y;
}
const int N=1<<22|5;
int a[N],n,m,sz[N];
ll ss=0;
vector<int> prt;
inline bool del(int p,int dp) {
  if(!a[p<<1]&&!a[p<<1|1]) {
    if(dp>0) return 0;
    return a[p]=sz[p]=0,1;
  }
  int t;
  bool ff;
  if(a[p<<1]>a[p<<1|1]) t=a[p<<1],ff=del(p<<1,dp-1);
  else t=a[p<<1|1],ff=del(p<<1|1,dp-1);
  if(!ff) return 0;
  return a[p]=t,sz[p]=sz[p<<1]+sz[p<<1|1]+1,1;
}
inline void solve(int p,int dp1,int dp2) {
  int t;
  while(a[p]) {
    t=a[p];
    if(!del(p,dp2)) break;
    prt.pb(p),ss-=t;
  }
  if(!a[p]) return;
  solve(p<<1,dp1-1,dp2-1),solve(p<<1|1,dp1-1,dp2-1);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    n=read(),m=read();
    fill(a+1,a+(1<<(n+1)),0);
    ss=0;
    for(ri i=1;i<(1<<n);++i) ss+=(a[i]=read());
    fill(sz+1,sz+(1<<(n+1)),0);
    for(ri i=(1<<n)-1;i;--i) sz[i]=sz[i<<1]+sz[i<<1|1]+1;
    prt.resize(0);
    solve(1,n,m);
    cout<<ss<<'\n';
    for(ri i=0;i<prt.size();++i) cout<<prt[i]<<' ';
    puts("");
  }
  return 0;
}
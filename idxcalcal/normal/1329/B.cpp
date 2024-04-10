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
const int N=2e5+5;
int pw[55],lm,f[55][55],F[55],a[55],top=0;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    lm=read(),mod=read();
    if(mod==1) {
      puts("0");
      continue;
    }
    int res=0;
    memset(f,0,sizeof(f));
    for(ri i=f[0][0]=1;i<=32;++i) {
      for(ri j=1;j<=31;++j) {
        if((1ll<<(j-1))>lm) break;
        f[i][j]=0;
        for(ri k=0;k<j;++k) f[i][j]=add(f[i][j],f[i-1][k]);
        Mul(f[i][j],min(1<<(j-1),lm-(1<<(j-1))+1)%mod);
      }
      for(ri j=0;j<=32;++j) Add(res,f[i][j]);
    }
    cout<<res<<'\n';
  }
  return 0;
}
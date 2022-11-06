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
  const int mod=998244353;
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
template<typename T> inline T gcd(T a,T b) { T t;while(b)t=a,a=b,b=t-t/a*a;return a; }
template<typename T> inline T Abs(T x) { return x<0?-x:x; }
inline int rd() { return rand()|(rand()<<15); }
const int N=5005;
int n;
char s[N];
bool f[N][N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    n=Read(s);
    for(ri i=1;i<=n;++i) for(ri j=1;j<=n;++j) f[i][j]=i>=j?1:0;
    for(ri len=2;len<=n;++len) for(ri l=1,r=len;r<=n;++l,++r) f[l][r]=f[l+1][r-1]&&s[l]==s[r];
    int len1=0,len2=0,len3=0;
    for(ri len=0,ff=1;len<=n&&ff;++len) {
      for(ri l=len+1,r=n-len;r>=l;--r) if(f[l][r]) {
        if(len1*2+len2<r-l+1+len*2&&len1*2+len2<r-l+1+len*2) {
          len1=len;
          len2=r-l+1;
          len3=0;
          break;
        }
      }
      for(ri l=len+1,r=n-len;r>=l;++l) if(f[l][r]) {
        if(len1*2+len2<r-l+1+len*2&&len1*2+len2<r-l+1+len*2) {
          len1=len;
          len2=0;
          len3=r-l+1;
          break;
        }
      }
      ff&=s[len+1]==s[n-len];
    }
    for(ri i=1;i<=len1;++i) cout<<s[i];
    for(ri i=1;i<=len2;++i) cout<<s[i+len1];
    for(ri i=1;i<=len3;++i) cout<<s[n-len1-i+1];
    for(ri i=len1;i;--i) cout<<s[n-i+1];
    puts("");
  }
  return 0;
}
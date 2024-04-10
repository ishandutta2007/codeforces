#include<bits/stdc++.h>
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
const int inf=1e9;
const int rlen=1<<20;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans,f;
  static char ch;
  ans=0,ch=gc(),f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline ll readl() {
  static ll ans;
  static int f;
  static char ch;
  ans=0,ch=gc(),f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline int Read(char*s) {
  static int tp;
  static char ch;
  tp=0,ch=gc();
  while(!isalpha(ch)&&!isdigit(ch)) ch=gc();
  while(isalpha(ch)||isdigit(ch)) s[++tp]=ch,ch=gc();
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
  inline int sqr(int a) { return (ll)a*a%mod; }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
} using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=2e5+5;
int n,m,K;
ll res;
inline ll sqrr(int x) { return (ll)x*x; }
inline void work(vector<int> a,vector<int> b,vector<int> c) {
  int n=a.size()-1,m=b.size()-1,K=c.size()-1;
  int ps1=1,ps2=1,ps3=1;
  while(ps1<=n&&a[ps1]<b[ps2]) ++ps1;
  if(ps1>n) return;
  for(;ps1<=n;++ps1) {
    while(ps2<m&&b[ps2+1]<=a[ps1]) ++ps2;
    while(ps3<K&&c[ps3+1]+c[ps3]<=b[ps2]+a[ps1]) ++ps3;
    ckmin(res,sqrr(a[ps1]-b[ps2])+sqrr(a[ps1]-c[ps3])+sqrr(b[ps2]-c[ps3]));
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  int tt=1;
  scanf("%d",&tt);
for(;tt;--tt) {
  n=read(),m=read(),K=read();
  res=5e18;
  vector<int> a(n+1),b(m+1),c(K+1);
  for(ri i=1;i<=n;++i) a[i]=read();
  for(ri i=1;i<=m;++i) b[i]=read();
  for(ri i=1;i<=K;++i) c[i]=read();
  sort(++a.begin(),a.end());
  sort(++b.begin(),b.end());
  sort(++c.begin(),c.end());
  work(a,b,c);
  work(a,c,b);
  work(b,a,c);
  work(b,c,a);
  work(c,a,b);
  work(c,b,a);
  cout<<res<<'\n';
}
  return 0;
}
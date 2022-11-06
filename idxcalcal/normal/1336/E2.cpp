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
const int N=2e5+5,bas=(1<<18)-1;
int n,m,rk,res[N],cnt[1<<18],coe[60][60],C[60][60],tim[N];
ll a[N],b[N];
inline void init() {
  for(ri i=1;i<(1<<18);++i) cnt[i]=cnt[i>>1]+(i&1);
  for(ri i=0;i<=m;++i) for(ri j=C[i][0]=1;j<=i;++j) C[i][j]=add(C[i-1][j],C[i-1][j-1]);
  for(ri t,x=0;x<=m;++x) for(ri y=0;y<=m;++y) for(ri i=0;i<=x;++i) {
    t=mul(C[y][i],C[m-y][x-i]);
    (i&1?Dec:Add)(coe[x][y],t);
  }
}
inline int ppcnt(ll x) { return cnt[x&bas]+(x<=bas?0:ppcnt(x>>18)); }
vector<int> id;
void dfs1(int ps,ll ss) {
  if(ps==rk) { ++res[ppcnt(ss)];return; }
  dfs1(ps+1,ss),dfs1(ps+1,ss^a[id[ps]]);
}
void dfs2(int ps,ll ss,int ct) {
  if(ps+rk==m) { ++tim[ppcnt(ss)+ct];return; }
  dfs2(ps+1,ss,ct),dfs2(ps+1,ss^b[ps],ct+1);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=1;i<=n;++i) {
    ll x=readl();
    for(ri j=63;~j;--j) if(x>>j&1) {
      if(!a[j]) { a[j]=x;break; }
      else x^=a[j];
    }
  }
  rk=0;
  for(ri i=0;i<64;++i) if(a[i]) id.pb(i),++rk;
  init();
  int mt;
  if(rk<=27) mt=ksm(2,n-rk),dfs1(0,0);
  else {
    mt=ksm(2,n<m?n-m+mod-1:n-m);
    for(ri i=0;i<60;++i) {
      for(ri j=i+1;j<60;++j) if(a[j]>>i&1) a[j]^=a[i];
      if(a[i]) a[i]^=1ll<<i;
    }
    for(ri i=0;i<60;++i) {
      bool ff1=0,ff2=0;
      for(ri j=0;j<60;++j) {
        if(a[j]>>i&1) ff1=1;
        if(a[j]>=(1ll<<i)) ff2=1;
      }
      if(!ff2) break;
      if(!ff1) {
        for(ri j=0;j<60;++j) if(a[j]) a[j]=(((1ll<<(i+1))-1)&a[j])|(a[j]>>(i+1)<<i);
        --i;
      }
    }
    int l=m-rk;
    for(ri i=0;i<l;++i) for(ri j=0;j<rk;++j) b[i]|=(a[id[j]]>>i&1ll)<<j;
    dfs2(0,0,0);
    for(ri i=0;i<=m;++i) for(ri j=0;j<=m;++j) Add(res[i],mul(coe[i][j],tim[j]));
  }
  for(ri i=0;i<=m;++i) cout<<mul(mt,res[i])<<' ';
  return 0;
}
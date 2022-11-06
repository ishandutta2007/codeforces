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
int n,m,f[2][64][1<<16|5],res[N];
ll a[N];
inline int cntt(ll x){
  int ret=0;
  for(ri i=63;~i;--i) if(x>>i&1) ++ret;
  return ret;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=1;i<=n;++i) {
    ll x=readl();
    for(ri j=63;~j;--j) if(x>>j&1) {
      if(!a[j]) {
        a[j]=x;
        break;
      }
      else x^=a[j];
    }
  }
  int rk=0;
  vector<int> id;
  for(ri i=0;i<64;++i) if(a[i]) {
    id.pb(i);
    ++rk;
  }
  int mt=ksm(2,n-rk);
  if(rk<=20) {
    for(ri s=0,up=1<<rk;s<up;++s) {
      ll t=0;
      for(ri i=0;i<rk;++i) if(s>>i&1) t^=a[id[i]];
      Add(res[cntt(t)],mt);
    }
  }
  else {
    for(ri i=0;i<64;++i) {
      for(ri j=i+1;j<64;++j) if(a[j]>>i&1) a[j]^=a[i];
      a[i]^=1ll<<i;
    }
    for(ri i=0;i<64;++i) {
      bool ff1=0,ff2=0;
      for(ri j=0;j<64;++j) {
        if(a[j]>>i&1) ff1=1;
        if(a[j]>=(1ll<<i)) ff2=1;
      }
      if(!ff2) break;
      if(!ff1) {
        for(ri j=0;j<64;++j) if(a[j]) a[j]=(((1ull<<(i+1))-1)&a[j])|(a[j]>>(i+1)<<i);
        --i;
      }
    }
    int cur=0;
    f[cur][0][0]=mt;
    for(ri i=0;i<rk;++i) {
      cur^=1,memcpy(f[cur],f[cur^1],sizeof(f[cur^1]));
      for(ri j=0,up=1<<16;j<up;++j) {
        for(ri op=0;op<=i;++op) Add(f[cur][op+1][j],f[cur^1][op][j^a[id[i]]]);
      }
    }
    for(ri i=0;i<=rk;++i) for(ri j=0,up=1<<16;j<up;++j) if(f[cur][i][j]) Add(res[i+cntt(j)],f[cur][i][j]);
  }
  for(ri i=0;i<=m;++i) cout<<res[i]<<' ';
  return 0;
}
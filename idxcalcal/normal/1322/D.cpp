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
template<typename T> inline T gcd(T a,T b) { T t;while(b)t=a,a=b,b=t-t/a*a;return a; }
template<typename T> inline T Abs(T x) { return x<0?-x:x; }
inline int rd() { return rand()|(rand()<<15); }
const int N=2005;
int n,m,a[N],cnt[N];
ll f[N][N],w[N<<1],g[N][N],c[N];
inline ll W(int l,int r,int x) {
  ll res=0;
  for(ri i=l;i<=r&&x;++i) res+=x*w[i],x>>=1;
  return res;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=0;i<=m;++i) for(ri j=1;j<=n;++j) f[i][j]=-Inf;
  for(ri i=1;i<=n;++i) a[i]=read();
  for(ri i=1;i<=n;++i) c[i]=read();
  for(ri i=1;i<=n+m;++i) w[i]=read();
  for(ri id=n,x,ww;id;--id) {
    ++cnt[x=a[id]],ww=c[id];
    for(ri i=cnt[x];i;--i) ckmax(f[x][i],f[x][i-1]-ww);
    for(ri dis=1,y=x-1,dwn;~y;--y,++dis) {
      dwn=dis>20?cnt[y]:min(cnt[y],(1<<dis)-1);
      ckmax(f[x][1],g[y][dwn]-ww);
      for(ri i=dwn+1;i<=cnt[y];++i) {
        ckmax(f[x][(i>>dis)+1],f[y][i]+W(y,x-1,i)-ww);
        ckmax(cnt[x],(i>>dis)+1);
      }
    }
    g[x][0]=f[x][0];
    for(ri i=1;i<=cnt[x];++i) g[x][i]=max(g[x][i-1],f[x][i]+W(x,n+m,i));
  }
  ll res=0;
  for(ri i=0;i<=m;++i) ckmax(res,g[i][cnt[i]]);
  cout<<res;
  return 0;
}
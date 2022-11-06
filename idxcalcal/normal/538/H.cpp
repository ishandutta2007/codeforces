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
const int rlen=1<<24,inf=1e9;
const ll Inf=1e16;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans,f;
  static char ch;
  ans=0,ch=gc(),f=1;
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
  inline int ksm(int a,int p) { if(a<2) return a;int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
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
const int N=1e5+5;
pii a[N];
int n,m,L,R;
vector<int> e[N];
#define EX puts("IMPOSSIBLE"),exit(0)
int col[N];
void dfs(int p) {
  for(ri v,i=0;i<e[p].size();++i) {
    if(col[v=e[p][i]]) { if(col[v]==col[p]) EX;continue; }
    col[v]=3-col[p],dfs(v);
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  L=read(),R=read(),n=read(),m=read();
  int vl1=0,vl2=1e9;
  for(ri i=1;i<=n;++i) {
    ckmax(vl1,a[i].fi=read());
    ckmin(vl2,a[i].se=read());
  }
  if(vl1+vl2<L) vl1=L-vl2;
  else if(vl1+vl2>R) vl2=R-vl1;
  if(vl1<0||vl2<0) EX;
  for(ri i=1;i<=n;++i) {
    bool f1=a[i].fi<=vl1&&a[i].se>=vl1;
    bool f2=a[i].fi<=vl2&&a[i].se>=vl2;
    if(!f1&&!f2) EX;
    else if(!f2) col[i]=1;
    else if(!f1) col[i]=2;
  }
  for(ri u,v;m;--m) u=read(),v=read(),e[u].pb(v),e[v].pb(u);
  for(ri i=1;i<=n;++i) if(col[i]) dfs(i);
  for(ri i=1;i<=n;++i) if(!col[i]) col[i]=1,dfs(i);
  puts("POSSIBLE");
  cout<<vl1<<' '<<vl2<<'\n';
  for(ri i=1;i<=n;++i) cout<<col[i];
  return 0;
}
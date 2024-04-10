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
  static int ans;
  static char ch;
  ans=0,ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
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
const int N=4e5+5;
int n,fst[N],cnt=0,nxt[N<<1],vl[N<<1],du[N],cur,ct=0,m;
bool vs[N];
inline void ins(int u,int v) { nxt[++cnt]=fst[u],fst[u]=cnt,++du[vl[cnt]=v]; }
inline void dfs(int p) {
  for(ri v,x,&i=fst[p];i;i=nxt[i]) {
    if(vs[x=((i+1)>>1)]) continue;
    v=vl[i],vs[x]=1;
    dfs(v);
    ++ct;
    if(ct&1) cout<<p<<' '<<v<<'\n';
    else cout<<v<<' '<<p<<'\n';
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=1,u,v;i<=m;++i) {
    u=read(),v=read();
    ins(u,v),ins(v,u);
  }
  cur=0;
  for(ri i=1;i<=n;++i) if(du[i]&1) {
    if(!cur) cur=i;
    else ++m,ins(cur,i),ins(i,cur),cur=0;
  }
  if(m&1) ins(1,1),ins(1,1),++m;
  cout<<m<<'\n';
  for(ri i=1;i<=n;++i) if(fst[i]) dfs(i);
  return 0;	
}
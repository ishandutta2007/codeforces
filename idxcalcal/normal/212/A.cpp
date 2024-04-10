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
template<typename T> inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
template<typename T> inline T Abs(T x) { return x<0?-x:x; }
template<typename T> inline void exgcd(T a,T b,T&x,T&y) {
  if(!b) { x=1,y=0;return; }
  exgcd(b,a-a/b*b,x,y);
  T t=x;
  x=y,y=t-a/b*y;
}
const int N=505,M=10005;
map<int,int> idx[100005];
int sz[2][N],col[2][M][N],id[2][N];
int n,m,edg,K,res[1000005];
inline int nxt(int x) { return x<K?x+1:1; }
void dfs(int op,int x,int y,int ix,int iy) {
  int nxt=col[op^1][y][ix];
  col[op][x][ix]=y,col[op^1][y][ix]=x;
  col[op^1][y][iy]=0;
  if(nxt) dfs(op^1,y,nxt,iy,ix);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),edg=read(),K=read();
  if(K==1) { cout<<0<<'\n';for(ri i=1;i<=edg;++i) cout<<1<<' ';return 0; }
  int mx=0,tot=0;
  for(ri ix,iy,x,y,tt=1;tt<=edg;++tt) {
    x=read(),y=read();
    sz[0][x]=nxt(sz[0][x]),sz[1][y]=nxt(sz[1][y]);
    if(sz[0][x]==1) id[0][x]=++tot;
    if(sz[1][y]==1) id[1][y]=++tot;
    x=id[0][x],y=id[1][y];
    idx[x][y]=tt;
    for(ix=1;col[0][x][ix];++ix);
    for(iy=1;col[1][y][iy];++iy);
    ckmax(mx,max(ix,iy));
    if(ix==iy) col[0][x][ix]=y,col[1][y][iy]=x;
    else dfs(0,x,y,ix,iy);
  }
  int ss=0;
  for(ri i=1;i<=n;++i) if(sz[0][i]>=1&&sz[0][i]<K) ++ss;
  for(ri i=1;i<=m;++i) if(sz[1][i]>=1&&sz[1][i]<K) ++ss;
  cout<<ss<<'\n';
  for(ri i=1;i<=tot;++i) for(ri j=1;j<=mx;++j) res[idx[i][col[0][i][j]]]=j;
  for(ri i=1;i<=edg;++i) cout<<res[i]<<' ';
  return 0;
}
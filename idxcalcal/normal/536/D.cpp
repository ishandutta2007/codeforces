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
const int N=2005;
int n,m,S,T,a[N];
vector<pii> e[N];
int sz[N][N];
ll dis[2][N],f[2][N][N],ss[N][N];
typedef pair<ll,int> pli;
inline void dijkstra(int s) {
  static int t=0;
  set<pli> S;
  for(ri i=1;i<=n;++i) dis[t][i]=Inf;
  S.insert(pli(dis[t][s]=0,s));
  while(S.size()) {
    int x=S.begin()->se;
    S.erase(S.begin());
    for(ri v,i=0;i<e[x].size();++i) if(dis[t][v=e[x][i].fi]>dis[t][x]+e[x][i].se) {
      if(dis[t][v]<Inf) S.erase(pli(dis[t][v],v));
      S.insert(pli(dis[t][v]=dis[t][x]+e[x][i].se,v));
    }
  }
  ++t;
}
inline ll S1(int x1,int y1,int x2,int y2) { return ss[x2][y2]+ss[x1-1][y1-1]-ss[x1-1][y2]-ss[x2][y1-1]; }
inline int S2(int x1,int y1,int x2,int y2) { return sz[x2][y2]+sz[x1-1][y1-1]-sz[x1-1][y2]-sz[x2][y1-1]; }
ll vx[N],vy[N];
int cx,cy;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),S=read(),T=read();
  for(ri i=1;i<=n;++i) a[i]=read();
  for(ri i=1,u,v,w;i<=m;++i) {
    u=read(),v=read(),w=read();
    e[u].pb(pii(v,w)),e[v].pb(pii(u,w));
  }
  dijkstra(S),dijkstra(T);
  for(ri i=1;i<=n;++i) vx[i]=dis[0][i],vy[i]=dis[1][i];
  sort(vx+1,vx+n+1),cx=unique(vx+1,vx+n+1)-vx-1;
  sort(vy+1,vy+n+1),cy=unique(vy+1,vy+n+1)-vy-1;
  for(ri rx,ry,i=1;i<=n;++i) {
    rx=lower_bound(vx+1,vx+cx+1,dis[0][i])-vx;
    ry=lower_bound(vy+1,vy+cy+1,dis[1][i])-vy;
    ss[rx][ry]+=a[i],++sz[rx][ry];
  }
  for(ri i=1;i<=cx;++i) for(ri j=1;j<=cy;++j) ss[i][j]+=ss[i-1][j],sz[i][j]+=sz[i-1][j];
  for(ri i=1;i<=cx;++i) for(ri j=1;j<=cy;++j) ss[i][j]+=ss[i][j-1],sz[i][j]+=sz[i][j-1];
  ll W;
  for(ri i=cx,S;i;--i) for(ri j=cy;j;--j) {
    W=S1(i,j,i,cy),S=S2(i,j,i,cy);
    f[0][i][j]=S?max(f[0][i+1][j],-f[1][i+1][j])+W:f[0][i+1][j];
    W=S1(i,j,cx,j),S=S2(i,j,cx,j);
    f[1][i][j]=S?max(-f[0][i][j+1],f[1][i][j+1])+W:f[1][i][j+1];
  }
  puts(f[0][1][1]?(f[0][1][1]>0?"Break a heart":"Cry"):"Flowers");
  return 0;
}
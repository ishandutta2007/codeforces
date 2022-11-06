#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef vector<ll> Poly;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define pb push_back
#define fi first
#define se second
const int rlen=1<<18|1;
const ll inf=1e17;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline ll readl() {
  ll ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline int Read(char*s) {
  int top=0;
  char ch=gc();
  while(!isalpha(ch)&&!isdigit(ch)) ch=gc();
  while(isalpha(ch)||isdigit(ch)) s[++top]=ch,ch=gc();
  return top;
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
}
using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=3005;
vector<int>e[N];
int n,siz[N],fa[N],dis[N][N];
ll f[N][N];
bool vs[N][N];
ll ans=0;
void getdist(int p,int ft,int rt,int dst=0) {
  dis[p][rt]=dst;
  for(ri i=0,v;i<(int)e[p].size();++i) {
    if((v=e[p][i])==ft) continue;
    getdist(v,p,rt,dst+1);
  }
}
inline void dfs(int p) {
  siz[p]=1;
  for(ri i=0,v;i<(int)e[p].size();++i) {
    if((v=e[p][i])==fa[p]) continue;
    fa[v]=p,dfs(v),siz[p]+=siz[v];
  }
}
void DP(int x,int y,int fx,int fy) {
  if(x>y) swap(x,y),swap(fx,fy);
  if(vs[x][y]) return;
  vs[x][y]=1;
  f[x][y]=0;
  for(ri sz1,sz2,i=0,v;i<(int)e[x].size();++i) {
    v=e[x][i];
    if(dis[v][y]<dis[x][y]) continue;
    if(v==fa[x]) sz1=n-siz[x];
    else sz1=siz[v];
    if(siz[fy]<siz[y]) sz2=n-siz[fy];
    else sz2=siz[y];
    DP(v,y,x,fy);
    ckmax(f[x][y],f[min(v,y)][max(v,y)]+(ll)sz1*sz2);
  }
  for(ri sz1,sz2,i=0,v;i<(int)e[y].size();++i) {
    v=e[y][i];
    if(dis[v][x]<dis[x][y]) continue;
    if(v==fa[y]) sz1=n-siz[y];
    else sz1=siz[v];
    if(siz[fx]<siz[x]) sz2=n-siz[fx];
    else sz2=siz[x];
    DP(v,x,y,fx);
    ckmax(f[x][y],f[min(v,x)][max(v,x)]+(ll)sz1*sz2);
  }
}
pii a[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  for(ri i=1,u,v;i<n;++i) {
    u=read(),v=read();
    a[i]=pii(u,v);
    e[u].pb(v),e[v].pb(u);
  }
  for(ri i=1;i<=n;++i) getdist(i,0,i);
  dfs(1);
  for(ri i=1,sz1,sz2;i<n;++i) {
    if(a[i].fi>a[i].se) swap(a[i].fi,a[i].se);
    DP(a[i].fi,a[i].se,a[i].se,a[i].fi);
    if(fa[a[i].se]==a[i].fi) sz1=n-siz[a[i].se];
    else sz1=siz[a[i].fi];
    if(fa[a[i].fi]==a[i].se) sz2=n-siz[a[i].fi];
    else sz2=siz[a[i].se];
    ans=max(ans,(ll)f[a[i].fi][a[i].se]+(ll)sz1*sz2);
  }
  cout<<ans;
  return 0;
}
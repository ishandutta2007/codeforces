#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
#define pb push_back
#define fi first
#define se second
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  bool f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline ll readl() {
  ll ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
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
int lim,tim,invv[21];
vector<int>rev[21],w[21];
inline void init_ntt() {
  w[20].resize(1<<20),w[20][0]=1,w[20][1]=ksm(3,(mod-1)>>21);
  for(ri i=2,up=1<<20;i<up;++i) w[20][i]=mul(w[20][i-1],w[20][1]);
  for(ri i=19;~i;--i) {
    w[i].resize(1<<i);
    for(ri j=0,up=1<<i;j<up;++j) w[i][j]=w[i+1][j<<1];
  }
  invv[0]=1;
  for(ri i=1,iv=mod+1>>1;i<21;++i) invv[i]=mul(invv[i-1],iv);
}
inline void init(int up) {
  lim=1,tim=0;
  while(lim<up) lim<<=1,++tim;
  if(rev[tim].size()) return;
  rev[tim].resize(lim);
  for(ri i=1;i<lim;++i) rev[tim][i]=(rev[tim][i>>1]>>1)|((i&1)<<(tim-1));
}
inline void ntt(poly&a,int typ) {
  for(ri i=1;i<lim;++i) if(i<rev[tim][i]) swap(a[i],a[rev[tim][i]]);
  for(ri i=1,t=0,a0,a1;i<lim;i<<=1,++t) for(ri j=0;j<lim;j+=i<<1) for(ri k=0;k<i;++k) {
    a0=a[j+k],a1=mul(a[j+k+i],w[t][k]);
    a[j+k]=add(a0,a1),a[j+k+i]=dec(a0,a1);
  }
  if(~typ) return;
  reverse(++a.begin(),a.end());
  for(ri i=0;i<lim;++i) Mul(a[i],invv[tim]);
}
inline poly operator*(poly a,poly b) {
  int n=(int)a.size(),m=(int)b.size(),t=n+m-1;
  if(t<=128) {
    poly c(t);
    for(ri i=0;i<n;++i) if(a[i]) for(ri j=0;j<m;++j) Add(c[i+j],mul(a[i],b[j]));
    return c;
  }
  init(t);
  a.resize(lim),ntt(a,1);
  b.resize(lim),ntt(b,1);
  for(ri i=0;i<lim;++i) Mul(a[i],b[i]);
  return ntt(a,-1),a.resize(t),a;
}
inline poly operator+(poly a,poly b) {
  int n=(int)b.size();
  if((int)a.size()<n) a.resize(n);
  for(ri i=0;i<n;++i) Add(a[i],b[i]);
  return a;
}
const int N=1e5+5;
vector<int>e[N],son[N];
int fa[N],hson[N],dep[N],top[N],siz[N],pred[N],num[N],tot=0,bot[N];
void dfs1(int p) {
  siz[p]=1;
  for(ri i=0,v;i<(int)e[p].size();++i) {
    if((v=e[p][i])==fa[p]) continue;
    fa[v]=p,dep[v]=dep[p]+1,dfs1(v),siz[p]+=siz[v];
    if(siz[v]>siz[hson[p]]) hson[p]=v;
  }
}
void dfs2(int p,int tp) {
  pred[num[p]=++tot]=p,top[p]=tp;
  if(!hson[p]) { bot[p]=p;return; }
  dfs2(hson[p],p),bot[p]=bot[hson[p]];
  for(ri i=0,v;i<(int)e[p].size();++i) if((v=e[p][i])!=fa[p]&&v!=hson[p]) dfs2(v,v);
}
#define lc (ch[p][0])
#define rc (ch[p][1])
int n,rt,Fa[N],ch[N][2],fac[N],ifac[N];
ll x;
poly F[N],G[N];
inline poly solve(int l,int r,vector<poly>&a) {
  if(l>r) return poly(1,1);
  if(l==r) return a[l];
  int mid=l+r>>1;
  return solve(l,mid,a)*solve(mid+1,r,a);
}
inline void init_vl(int p) {
  vector<poly>t;
  for(ri i=0;i<(int)son[p].size();++i) t.pb(F[son[p][i]]);
  G[p]=solve(0,(int)t.size()-1,t);
  G[p].pb(0);
  for(ri i=(int)G[p].size()-1;i;--i) G[p][i]=G[p][i-1];
  F[p]=G[p],G[p][0]=0,F[p][0]=1;
}
inline void pushup(int p) {
  if(lc&&rc) {
    F[p]=F[lc]+G[lc]*G[p]*F[rc];
    G[p]=G[lc]*G[p]*G[rc];
  }
  else if(lc) {
    F[p]=F[lc]+G[lc]*G[p];
    G[p]=G[lc]*G[p];
  }
  else if(rc) {
    F[p]=G[p]*F[rc];
    F[p][0]=1;
    G[p]=G[p]*G[rc];
  }
}
inline int solve(int l,int r,int dt=0) {
  if(l>r) return 0;
  if(l==r) return init_vl(pred[l]),pred[l];
  for(ri p,i=r;i>=l;--i) if(siz[pred[l]]+dt<=2*siz[pred[i]]) {
    p=pred[i];
    init_vl(p);
    lc=solve(l,i-1,siz[p]);
    rc=solve(i+1,r,dt);
    return pushup(p),p;
  }
  return 0;
}
inline int solve(int p) {
  for(ri x=p;x;x=hson[x]) for(ri i=0,v;i<(int)e[x].size();++i) if((v=e[x][i])!=fa[x]&&v!=hson[x]) son[x].pb(solve(v));
  return solve(num[p],num[bot[p]]);
}
inline void init() {
  fac[0]=fac[1]=ifac[0]=ifac[1]=1;
  for(ri i=2;i<=n;++i) {
    fac[i]=mul(fac[i-1],i);
    ifac[i]=mul(ifac[mod-mod/i*i],mod-mod/i);
  }
  for(ri i=2;i<=n;++i) Mul(ifac[i],ifac[i-1]);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),x=readl();
  init_ntt();
  init();
  for(ri i=1,u,v;i<n;++i) {
    u=read(),v=read();
    e[u].pb(v),e[v].pb(u);
  }
  dfs1(1),dfs2(1,1);
  rt=solve(1);
  int res=0;
  for(ri i=1,mt=1;i<(int)F[rt].size();++i) {
    Add(res,mul(ifac[i-1],mul(mt,F[rt][i])));
    Mul(mt,(x+i)%mod);
  }
  cout<<res;
  return 0;
}
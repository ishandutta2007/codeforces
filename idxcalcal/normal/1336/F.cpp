#include<bits/stdc++.h>
#include<tr1/unordered_map>
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
const int rlen=1<<20;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() getchar()//(((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans;
  static char ch;
  ans=0,ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline ll readl() {
  static ll ans;
  static char ch;
  ans=0,ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
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
  inline int sqr(int a) { return (ll)a*a%mod; }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
} using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=150005;
int n,m,lim,fa[N],st[N][19],hson[N],dep[N],top[N],siz[N],in[N],out[N],tot=0;
vector<int> e[N];
void dfs1(int p) {
  siz[p]=1;
  for(ri i=1;i<19;++i) st[p][i]=st[st[p][i-1]][i-1];
  for(ri i=0,v;i<e[p].size();++i) if((v=e[p][i])^fa[p]) {
    fa[v]=st[v][0]=p,dep[v]=dep[p]+1,dfs1(v),siz[p]+=siz[v];
    if(siz[v]>siz[hson[p]]) hson[p]=v;
  }
}
void dfs2(int p,int tp) {
  in[p]=++tot,top[p]=tp;
  for(ri i=0,v;i<e[p].size();++i) if((v=e[p][i])!=fa[p]&&v!=hson[p]) dfs2(v,v);
  if(hson[p]) dfs2(hson[p],tp);
  out[p]=tot;
}
inline int lca(int x,int y) {
  while(top[x]^top[y]) dep[top[x]]<dep[top[y]]?y=fa[top[y]]:x=fa[top[x]];
  return dep[x]<dep[y]?x:y;
}
inline int lift(int x,int t) { for(ri i=18;~i;--i) if(t>>i&1) x=st[x][i];return x; }
vector<pii> pth[N],a[N];
ll res=0;
namespace Bit {
  int bt[N],res;
  inline int lbt(int x) { return x&-x; }
  inline void updd(int x,int v) { for(;x<=n;x+=lbt(x)) bt[x]+=v; }
  inline int qry(int x) { for(res=0;x;x^=lbt(x)) res+=bt[x];return res; }
  inline void upd(int l,int r) { updd(l,1),updd(r+1,-1); }
}
namespace sgt {
  #define lc son[p][0]
  #define rc son[p][1]
  #define mid ((l+r)>>1)
  #define qll lc,l,mid
  #define qrr rc,mid+1,r
  const int N=::N<<6;
  int son[N][2],sz[N],tot=0,ql,qr;
  inline void ins(int&p,int l,int r,int k) {
    if(!p) p=++tot,lc=rc=sz[p]=0;
    ++sz[p];
    if(l==r) return;
    k<=mid?ins(qll,k):ins(qrr,k);
  }
  inline int merge(int p,int l,int r,int x) {
    if(!p||!x) return p|x;
    sz[p]+=sz[x];
    return l^r?(lc=merge(qll,son[x][0]),rc=merge(qrr,son[x][1])):0,p;
  }
  inline int qry(int p,int l,int r) {
    if(!p) return 0;
    if(ql<=l&&r<=qr) return sz[p];
    return qr<=mid?qry(qll):(ql>mid?0:qry(qll))+qry(qrr);
  }
}
int rt[N],id[N];
void solve(int p,int anc) {
  rt[p]=0,id[p]=p;
  int _l=dep[anc]+max(lim-dep[p]+dep[anc],0);
  for(ri x,y,ps,i=0,l;i<a[p].size();++i) {
    x=a[p][i].fi,y=a[p][i].se;
    if((l=dep[y]-_l)>=0) ps=lift(y,l),sgt::ql=in[ps],sgt::qr=out[ps],res+=sgt::qry(rt[p],1,n);
    sgt::ins(rt[p],1,n,in[y]);
  }
  pii cur;
  for(ri i=0,ps,x,y,v,l;i<e[p].size();++i) if((v=e[p][i])!=fa[p]&&v!=hson[anc]) {
    solve(v,anc);
    if(a[id[p]].size()<a[id[v]].size()) swap(id[p],id[v]),swap(rt[p],rt[v]);
    #define A a[id[p]]
    #define B a[id[v]]
    for(ri j=0;j<B.size();++j) {
      x=B[j].fi,y=B[j].se,A.pb(B[j]);
      if((l=dep[y]-_l)>=0) ps=lift(y,l),sgt::ql=in[ps],sgt::qr=out[ps],res+=sgt::qry(rt[p],1,n);
    }
    B.rez(0);
    rt[p]=sgt::merge(rt[p],1,n,rt[v]);
  }
}
void calc(int p) {
  int lm=pth[p].size();
  for(ri i=0;i<e[p].size();++i) if(e[p][i]^fa[p]) calc(e[p][i]);
  for(ri i=0;i<lm;++i) res+=Bit::qry(in[pth[p][i].se]);
  for(ri i=0,x,l;i<lm;++i) {
    x=pth[p][i].se,l=dep[x]-dep[p]-lim;
    if(l>=0) x=lift(x,l),Bit::upd(in[x],out[x]);
  }
  for(ri i=0,x;i<lm;++i) x=pth[p][i].fi,res+=Bit::qry(in[x]),a[x].pb(pth[p][i]);
  for(ri i=0,x,l;i<lm;++i) {
    x=pth[p][i].fi,l=dep[x]-dep[p]-lim;
    if(l>=0) x=lift(x,l),Bit::upd(in[x],out[x]);
  }
  solve(p,p),sgt::tot=0;
  a[id[p]].rez(0);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),lim=read();
  for(ri i=1,u,v;i<n;++i) u=read(),v=read(),e[u].pb(v),e[v].pb(u);
  dfs1(1),dfs2(1,1);
  for(ri i=1,t,x,y;i<=m;++i) {
    x=read(),y=read(),t=lca(x,y);
    if(in[x]>in[y]) swap(x,y);
    pth[t].pb(pii(x,y));
  }
  calc(1);
  cout<<res;
  return 0;
}
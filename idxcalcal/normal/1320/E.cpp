#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
#define y2 cyktxdy
typedef long long ll;
typedef vector<int> poly;
typedef vector<ll> Poly;
typedef pair<int,int> pii;
#define pb push_back
#define fi first
#define se second
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
  int top=0;
  char ch=gc();
  while(!isalpha(ch)&&!isdigit(ch)) ch=gc();
  while(isalpha(ch)||isdigit(ch)) s[++top]=ch,ch=gc();
  return top;
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
  inline int cub(int a) { return mul(mul(a,a),a); }
}
using namespace modular;
template<typename T>inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T>inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T>inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
template<typename T>inline T Abs(T x) { return x<0?-x:x; }
const int N=2e5+5;
int n,dep[N],top[N],fa[N],hson[N],siz[N],m,K,dfn[N],tot=0;
vector<int>e[N];
void dfs1(int p) {
  siz[p]=1;
  for(ri i=0,v;i<(int)e[p].size();++i) if((v=e[p][i])!=fa[p]) {
    fa[v]=p,dep[v]=dep[p]+1,dfs1(v),siz[p]+=siz[v];
    if(siz[v]>siz[hson[p]]) hson[p]=v;
  }
}
void dfs2(int p,int tp) {
  top[p]=tp,dfn[p]=++tot;
  if(!hson[p]) return;
  dfs2(hson[p],tp);
  for(ri i=0,v;i<(int)e[p].size();++i) if((v=e[p][i])!=fa[p]&&v!=hson[p]) dfs2(v,v);
}
inline int lca(int x,int y) {
  while(top[x]^top[y]) dep[top[x]]<dep[top[y]]?y=fa[top[y]]:x=fa[top[x]];
  return dep[x]<dep[y]?x:y;
}
int sp[N],st[N],a[N<<1],ed[N],tp,stk[N];
inline bool cmp(int a,int b) { return dfn[a]<dfn[b]; }
vector<pii>E[N];
vector<int>usd;
inline void Addd(int u,int v) {
  int d=max(dep[u],dep[v])-min(dep[u],dep[v]);
  E[u].pb(pii(v,d)),E[v].pb(pii(u,d));
}
inline void insert(int x) {
  if(tp<2) return usd.pb(stk[++tp]=x);
  int t=lca(x,stk[tp]);
  if(stk[tp]==t) return usd.pb(stk[++tp]=x);
  while(1) {
    if(dep[stk[tp-1]]<=dep[t]) {
      Addd(t,stk[tp--]);
      if(stk[tp]!=t) usd.pb(stk[++tp]=t);
      break;
    }
    Addd(stk[tp-1],stk[tp]),--tp;
  }
  if(stk[tp]!=x) usd.pb(stk[++tp]=x);
}
struct Node {
  int id,d,r;
  Node(int id=0,int d=0,int r=0):id(id),d(d),r(r) {}
  friend inline bool operator^(Node a,Node b) { return a.id!=b.id||a.d!=b.d||a.r!=b.r; }
  inline int V() { return d+(r>0); }
  friend inline bool operator<(Node a,Node b) { return a.V()^b.V()?a.V()<b.V():a.id<b.id; }
  friend inline Node operator+(Node a,int b) { return Node(a.id,a.d+(a.r+b)/sp[a.id],(a.r+b)%sp[a.id]); }
}dis[N];
typedef pair<Node,int> node;
inline void dijkstra() {
  static bool vs[N];
  set<node>S;
  for(ri i=(int)usd.size()-1;~i;--i) vs[usd[i]]=0,dis[usd[i]]=Node(inf,inf,inf);
  for(ri i=1;i<=K;++i) S.insert(node(dis[st[i]]=Node(i,0,0),st[i]));
  while(S.size()) {
    node t=*S.begin();
    int p=t.se;
    S.erase(S.begin());
    vs[p]=1;
    for(ri i=0,v;i<(int)E[p].size();++i) {
      v=E[p][i].fi;
      if(!vs[v]&&dis[p]+E[p][i].se<dis[v]) {
        if(dis[v]^Node(inf,inf,inf)) S.erase(node(dis[v],v));
        S.insert(node(dis[v]=dis[p]+E[p][i].se,v));
      }
    }
  }
  for(ri i=1;i<=m;++i) cout<<dis[ed[i]].id<<' ';
  puts("");
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  for(ri i=1,u,v;i<n;++i) {
    u=read(),v=read();
    e[u].pb(v),e[v].pb(u);
  }
  dfs1(1),dfs2(1,1);
  for(ri tt=read(),cnt;tt;--tt) {
    K=read(),m=read();
    a[cnt=1]=1;
    for(ri i=1;i<=K;++i) a[++cnt]=st[i]=read(),sp[i]=read();
    for(ri i=1;i<=m;++i) a[++cnt]=ed[i]=read();
    sort(a+1,a+cnt+1,cmp),cnt=unique(a+1,a+cnt+1)-a-1;
    tp=0;
    for(ri i=1;i<=cnt;++i) insert(a[i]);
    while(tp>1) Addd(stk[tp-1],stk[tp]),--tp;
    dijkstra();
    for(ri i=(int)usd.size()-1;~i;--i) E[usd[i]].clear();
    usd.clear();
  }
  return 0;
}
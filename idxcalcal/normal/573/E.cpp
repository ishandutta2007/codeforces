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
const int N=1e5+5;
int n;
namespace sbt {
  #define lc son[p][0]
  #define rc son[p][1]
  int son[N][2],sz[N],fa[N],rt,tot;
  ll vl[N],a0[N],d[N];
  inline void pushup(int p) { sz[p]=sz[lc]+sz[rc]+1; }
  inline void pushnow(int p,ll A0,ll D) { a0[p]+=A0,d[p]+=D,vl[p]+=A0+D*sz[lc]; }
  inline void pushdown(int p) {
    if(a0[p]||d[p]) {
      if(lc) pushnow(lc,a0[p],d[p]);
      if(rc) pushnow(rc,a0[p]+d[p]*(sz[lc]+1),d[p]);
      a0[p]=d[p]=0;
    }
  }
  inline bool which(int x) { return x^son[fa[x]][0]; }
  inline void rotate(int x) {
    int y=fa[x],z=fa[y],t=which(x);
    if(z) son[z][which(y)]=x;
    fa[x]=z,fa[y]=x,son[y][t]=son[x][t^1],son[x][t^1]=y;
    if(son[y][t]) fa[son[y][t]]=y;
    sz[x]=sz[y],pushup(y);
  }
  inline void splay(int p) {
    static int stk[N],tp;
    stk[tp=1]=p;
    for(ri i=fa[p];i;i=fa[i]) stk[++tp]=i;
    while(tp) pushdown(stk[tp--]);
    for(;fa[p];rotate(p)) if(fa[fa[p]]) rotate(which(p)^which(fa[p])?p:fa[p]);
    rt=p;
  }
  inline ll find(int rk) {
    int p=rt;
    while(p) {
      if(sz[lc]+1==rk) return splay(p),vl[p];
      if(sz[lc]>=rk) p=lc;
      else rk-=sz[lc]+1,p=rc;
    }
    return -1;
  }
  inline void init() { sz[rt=tot=1]=1; }
  inline void ins(int x,int rk) {
    vl[++tot]=find(rk);
    fa[son[tot][1]=son[rt][1]]=tot;
    son[fa[tot]=rt][1]=tot,pushnow(tot,(ll)x*rk,x);
  }
  inline ll getmx(int p) {
    ll res=vl[p];
    pushdown(p);
    if(lc) ckmax(res,getmx(lc));
    if(rc) ckmax(res,getmx(rc));
    return res;
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  sbt::init();
  for(ri i=1,x;i<=n;++i) {
    x=read();
    int l=1,r=i-1,ps=i;
    while(l<=r) {
      int mid=(l+r)>>1;
      if(sbt::find(mid)+(ll)x*mid>=sbt::find(mid+1)) r=mid-1,ps=mid;
      else l=mid+1;
    }
    sbt::ins(x,ps);
  }
  cout<<sbt::getmx(sbt::rt);
  return 0;
}
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
const int N=4e5+5;
int n,m,low[N],dfn[N],tot=0,top=0,lst[N],pre[N],vs[N],Pre[N],Suf[N],Vs[N],stk[N];
vector<int> e[N],E[N],rev[N];
int tpt=0,pt[N],que[N],hd,tl,prt[N],tp=0;
inline void solve(int S) {
  int T=0,ff=0;
  Vs[que[hd=tl=1]=S]=1;
  while(hd<=tl&&!ff) {
    int x=que[hd++];
    for(ri j=0,v;j<E[x].size();++j) if((v=E[x][j])!=pre[x]){
      if(!Vs[v]) pre[v]=x,Vs[que[++tl]=v]=1;
      else {
        ff=1;
        for(ri y=x;y;y=pre[y]) vs[y]=1,Suf[pre[y]]=y,Pre[y]=pre[y];
        Suf[x]=v,Pre[v]=x;
        for(S=v;!vs[S];S=pre[S]) {
          vs[S]=1;
          Pre[pre[S]]=S,Suf[S]=pre[S];
        }
        break;
      }
    }
  }
  for(ri y=S;y;y=pre[y]) vs[y]=0;
  memset(Vs,0,sizeof(Vs)),memset(pre,0,sizeof(pre));
  Vs[que[hd=tl=1]=S]=1;
  puts("YES");
  while(hd<=tl&&!T) {
    int x=que[hd++];
    for(ri j=0,v;j<E[x].size();++j) if(!Vs[v=E[x][j]]&&v!=pre[x]) {
      if(x==S&&(v==Suf[x]||v==Pre[x])) continue;
      if(vs[v]) {
        T=v;
        prt[tp=1]=v;
        for(ri y=x;y;y=pre[y]) prt[++tp]=y;
        cout<<tp<<' ';
        for(ri y=tp;y;--y) cout<<prt[y]<<' ';
        puts("");
        break;
      }
      else Vs[que[++tl]=v]=1,pre[v]=x;
    }
  }
  prt[tp=1]=S;
  for(ri y=Pre[S];y!=T;y=Pre[y]) {
    prt[++tp]=y;
    if(!y) exit(0);
  }
  prt[++tp]=T;
  cout<<tp<<' ';
  for(ri y=1;y<=tp;++y) cout<<prt[y]<<' ';
  puts("");
  prt[tp=1]=S;
  for(ri y=Suf[S];y!=T;y=Suf[y]) {
    prt[++tp]=y;
    if(!y) exit(0);
  }
  prt[++tp]=T;
  cout<<tp<<' ';
  for(ri y=1;y<=tp;++y) cout<<prt[y]<<' ';
  puts("");
  exit(0);
}
void tarjan(int p,int ft) {
  dfn[p]=low[p]=++tot;
  for(ri i=0,v;i<e[p].size();++i) {
    if(!dfn[v=e[p][i]]) {
      stk[++top]=v,tarjan(v,p);
      ckmin(low[p],low[v]);
      if(low[v]>=dfn[p]) {
        tpt=0;
        int t;
        do pt[++tpt]=(t=stk[top--]),E[t].resize(0); while(t!=v);
        E[p].resize(0);
        for(ri tt=1,x;tt<=tpt;++tt) {
          x=pt[tt];
          for(ri j=0;j<rev[x].size();++j) {
            E[x].pb(rev[x][j]);
            E[rev[x][j]].pb(x);
          }
        }
        pt[++tpt]=p;
        for(ri tt=1,ff;tt<=tpt;++tt) if(E[pt[tt]].size()>2) solve(pt[tt]);
      }
    }
    else {
      if(v!=ft) ckmin(low[p],dfn[v]);
      if(dfn[v]<dfn[p]) rev[p].pb(v);
    }
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=1,u,v;i<=m;++i) {
    u=read(),v=read();
    e[u].pb(v),e[v].pb(u);
  }
  for(ri i=1;i<=n;++i) if(!dfn[i]) top=0,tarjan(i,0);
  puts("NO");
  return 0;
}
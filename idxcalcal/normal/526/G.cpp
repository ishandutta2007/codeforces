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
const int N=3e5+5;
int n,m,rt1,rt2;
int len[N],mxlen;
vector<pii> e[N];
void dfs(int p,int ft) {
  ckmax(mxlen,len[p]);
  for(ri i=0,v;i<e[p].size();++i) if((v=e[p][i].fi)!=ft) len[v]=len[p]+e[p][i].se,dfs(v,p);
}
inline void getpt() {
  rt1=rt2=mxlen=0;
  dfs(1,0);
  for(ri i=1;i<=n;++i) if(mxlen==len[i]) rt1=i;
  len[rt1]=mxlen=0,dfs(rt1,0);
  for(ri i=1;i<=n;++i) if(mxlen==len[i]) rt2=i;
}
struct Tr {
  int dis[N],mx[N],rt,st[N][20],lson[N],rnk[N],top[N],tpp,ds[N][20],W[N];
  pii rts[N];
  void dfs1(int p) {
    for(ri i=1;i<20;++i) {
      st[p][i]=st[st[p][i-1]][i-1];
      ds[p][i]=ds[p][i-1]+ds[st[p][i-1]][i-1];
    }
    for(ri i=0,v;i<e[p].size();++i) if((v=e[p][i].fi)^st[p][0]) {
      dis[v]=dis[st[v][0]=p]+(ds[v][0]=e[p][i].se),dfs1(v);
      if(W[p]<W[v]+e[p][i].se) W[p]=W[v]+e[p][i].se,lson[p]=v;
    }
    for(ri i=0,v;i<e[p].size();++i) if((v=e[p][i].fi)!=st[p][0]&&v!=lson[p])
    rts[++tpp]=pii(W[v]+e[p][i].se,v);
  }
  void dfs2(int p,int tp) {
    top[p]=tp;
    if(p^top[p]) rnk[p]=rnk[top[p]];
    for(ri i=0,v;i<e[p].size();++i) if((v=e[p][i].fi)^st[p][0]) dfs2(v,v^lson[p]?v:tp);
  }
  inline void init() {
    dfs1(rt);
    rts[++tpp]=pii(W[rt],rt);
    sort(rts+1,rts+tpp+1),reverse(rts+1,rts+tpp+1);
    for(ri i=1;i<=tpp;++i) mx[i]=mx[i-1]+rts[i].fi,rnk[rts[i].se]=i;
    dfs2(rt,rt);
  }
  inline int jmp1(int x,int y) {
    int res=mx[y-1]+W[x];
    for(ri i=19;~i;--i) if(rnk[st[x][i]]>=y) res+=ds[x][i],x=st[x][i];
    return res+ds[x][0];
  }
  inline int jmp2(int x,int y) {
    int res=mx[y]+W[x];
    for(ri i=19;~i;--i) if(rnk[st[x][i]]>y) res+=ds[x][i],x=st[x][i];
    return res+ds[x][0]-W[st[x][0]];
  }
  inline int query(int x,int y) { return rnk[x]<=y?mx[y]:max(jmp1(x,y),jmp2(x,y)); }
} t1,t2;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  int ss=0;
  for(ri i=1,u,v,w;i<n;++i) {
    u=read(),v=read(),w=read();
    e[u].pb(pii(v,w)),e[v].pb(pii(u,w));
    ss+=w;
  }
  getpt(),t1.rt=rt1,t2.rt=rt2;
  t1.init(),t2.init();
  int lstans=0;
  for(ri x,y;m;--m) {
    x=(read()+lstans-1)%n+1;
    y=(read()+lstans-1)%n+1;
    if(2*y>=t1.tpp+1) lstans=ss;
    else lstans=max(t1.query(x,2*y-1),t2.query(x,2*y-1));
    cout<<lstans<<'\n';
  }
  return 0;
}
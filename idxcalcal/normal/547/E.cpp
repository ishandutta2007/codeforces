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
const int N=2e5+5,M=5e5+5;
int ps[N],in[N],out[N],n,m;
namespace acam {
  int son[N][26],fail[N],tot=0,dfntot=0,fa[N];
  vector<int> e[N];
  inline void ins(char*s,int len,int&id) {
    int p=0;
    for(ri i=1,x;i<=len;++i) {
      if(!son[p][x=(s[i]-'a')]) fa[son[p][x]=++tot]=p;
      p=son[p][x];
    }
    id=p;
  }
  void dfs(int p) { in[p]=++dfntot;for(ri i=0;i<e[p].size();++i) dfs(e[p][i]);out[p]=dfntot; }
  inline void build_fail() {
    static int que[N],hd,tl;
    hd=1,tl=0;
    for(ri i=0;i<26;++i) if(son[0][i]) que[++tl]=son[0][i];
    while(hd<=tl) {
      int x=que[hd++];
      for(ri i=0;i<26;++i) (son[x][i]?fail[que[++tl]=son[x][i]]:son[x][i])=son[fail[x]][i];
    }
    for(ri i=1;i<=tot;++i) e[fail[i]].pb(i);
    dfs(0);
  }
}
namespace Bit {
  int bit[N],lm;
  inline void init() { lm=acam::dfntot; }
  inline int lowbit(int x) { return x&-x; }
  inline void upd(int x) { for(;x<=lm;x+=lowbit(x)) ++bit[x]; }
  inline int query(int x) { int res=0;for(;x;x^=lowbit(x)) res+=bit[x];return res; }
  inline int qry(int x) { return query(out[x])-query(in[x]-1); }
}
char s[N];
vector<pii> qry[N];
int ans[M];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri len,i=1;i<=n;++i) len=Read(s),acam::ins(s,len,ps[i]);
  acam::build_fail(),Bit::init();
  for(ri i=1,l,r,x;i<=m;++i) {
    l=read()-1,r=read(),x=read();
    qry[l].pb(pii(-x,i)),qry[r].pb(pii(x,i));
  }
  for(ri x,i=1;i<=n;++i) {
    x=ps[i];
    while(x) Bit::upd(in[x]),x=acam::fa[x];
    for(ri j=0;j<qry[i].size();++j) {
      if(qry[i][j].fi>0) ans[qry[i][j].se]+=Bit::qry(ps[qry[i][j].fi]);
      else ans[qry[i][j].se]-=Bit::qry(ps[-qry[i][j].fi]);
    }
  }
  for(ri i=1;i<=m;++i) cout<<ans[i]<<'\n';
  return 0;
}
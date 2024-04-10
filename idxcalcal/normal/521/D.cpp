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
const int N=1e5+5;
int n,m,K,a[N],typ[N];
pii mx[N];
struct fs {
  ll a,b;
  fs(ll _a=0ll,ll _b=1ll) { ll g=gcd(_a,_b);a=_a/g,b=_b/g; }
  friend inline bool operator<(fs a,fs b) { return (long double)a.a*b.b<(long double)a.b*b.a; }
};
struct node {
  fs vl;
  int id;
  friend inline bool operator<(node a,node b) { return a.vl<b.vl; }
};
vector<pii> upd[N];
vector<node> mt;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),K=read();
  for(ri i=1;i<=n;++i) a[i]=read();
  for(ri i=1,op,id,vl;i<=m;++i) {
    op=read(),id=read(),vl=read(),typ[i]=op;
    if(op==1) { if(mx[id]<pii(vl-a[id],i)) mx[id]=pii(vl-a[id],i); }
    else if(op==2) upd[id].pb(pii(vl,i));
    else mt.pb((node) { fs(vl,1),i });
  }
  for(ri i=1;i<=n;++i) {
    if(mx[i].se&&mx[i].fi>0) upd[i].pb(mx[i]);
    sort(upd[i].begin(),upd[i].end());
    reverse(upd[i].begin(),upd[i].end());
    ll ss=a[i];
    for(ri j=0;j<upd[i].size();++j) {
      mt.pb((node) { fs(ss+upd[i][j].fi,ss),upd[i][j].se });
      ss+=upd[i][j].fi;
    }
  }
  sort(mt.begin(),mt.end()),reverse(mt.begin(),mt.end());
  if(mt.size()>K) mt.resize(K);
  cout<<mt.size()<<'\n';
  for(ri i=0;i<mt.size();++i) if(typ[mt[i].id]<2) cout<<mt[i].id<<' ';
  for(ri i=0;i<mt.size();++i) if(typ[mt[i].id]==2) cout<<mt[i].id<<' ';
  for(ri i=0;i<mt.size();++i) if(typ[mt[i].id]>2) cout<<mt[i].id<<' ';
  return 0;
}
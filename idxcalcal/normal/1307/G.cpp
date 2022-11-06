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
}
using namespace modular;
template<typename T>inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T>inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T>inline T gcd(T a,T b) { T t;while(b) t=a,a=b,b=t-t/a*a;return a; }
const int N=1e5+5;
struct edge { int v,nxt,c,w; };
int s,t,n,m;
vector<pair<int,ll> >Ans;
namespace Flow {
  int first[N],cnt,fl[N],F,ps[N];
  edge e[N];
  bool in[N];
  ll C,dis[N];
  inline void init() { memset(first,-1,sizeof(first)),cnt=-1,F=C=0; }
  inline void addedge(int u,int v,int c,int w) {
    e[++cnt]=(edge) { v,first[u],c,w };
    first[u]=cnt;
  }
  inline void add(int u,int v,int c,int w) {
    addedge(u,v,c,w);
    addedge(v,u,0,-w);
  }
  inline bool spfa() {
    queue<int>q;
    for(ri i=1;i<=n;++i) dis[i]=inf;
    in[s]=1,dis[s]=0,q.push(s),fl[s]=inf;
    while((int)q.size()) {
      int x=q.front();
      q.pop(),in[x]=0;
      for(ri i=first[x],v;~i;i=e[i].nxt) {
        if(e[i].c>0&&dis[v=e[i].v]>dis[x]+e[i].w) {
          dis[v]=dis[x]+e[i].w,ps[v]=i,fl[v]=min(fl[x],e[i].c);
          if(!in[v]) q.push(v),in[v]=1;
        }
      }
    }
    if(dis[t]==inf) return 0;
    F+=fl[t],C+=fl[t]*dis[t];
    int p=t;
    while(p^s) e[ps[p]].c-=fl[t],e[ps[p]^1].c+=fl[t],p=e[ps[p]^1].v;
    return 1;
  }
  inline void solve() { while(spfa()) Ans.pb(make_pair(F,C)); }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),s=1,t=n;
  Flow::init();
  for(ri i=1,u,v,w;i<=m;++i) {
    u=read(),v=read(),w=read();
    Flow::add(u,v,1,w);
  }
  Flow::solve();
  for(ri tt=read(),X;tt;--tt) {
    X=read();
    double res=Inf;
    for(ri i=(int)Ans.size()-1;~i;--i) ckmin(res,(double)(X+Ans[i].se)/Ans[i].fi);
    printf("%.10lf\n",res);
  }
  return 0;
}
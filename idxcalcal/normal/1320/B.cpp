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
int n,dis[N],K,m,a[N],s,t;
bool vs[N];
vector<int>e[N],rev[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=1,u,v;i<=m;++i) {
    u=read(),v=read();
    e[u].pb(v);
    rev[v].pb(u);
  }
  K=read();
  for(ri i=1;i<=K;++i) a[i]=read();
  queue<int>q;
  s=a[1],t=a[K],vs[t]=1;
  q.push(t);
  while(q.size()) {
    int x=q.front();
    q.pop();
    for(ri i=0,v;i<(int)rev[x].size();++i) {
      if(vs[v=rev[x][i]]) continue;
      vs[v]=1,dis[v]=dis[x]+1,q.push(v);
    }
  }
  int cnt=0;
  for(ri i=1;i<K;++i) {
    if(dis[a[i]]-dis[a[i+1]]!=1) {
      ++cnt;
      continue;
    }
    bool ff=0;
    for(ri v,j=0;j<(int)e[a[i]].size();++j) {
      v=e[a[i]][j];
      if(v==a[i+1]) {
        ff=1;
        break;
      }
    }
    if(!ff) ++cnt;
  }
  cout<<cnt<<' ';
  cnt=0;
  for(ri i=1;i<K;++i) {
    bool ff=0;
    for(ri v,j=0;j<(int)e[a[i]].size();++j) {
      v=e[a[i]][j];
      if(v!=a[i+1]&&dis[a[i]]-dis[v]==1) {
        ff=1;
        break;
      }
    }
    if(ff) ++cnt;
  }
  cout<<cnt;
  return 0;
}
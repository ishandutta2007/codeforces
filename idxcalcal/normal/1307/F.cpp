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
const int N=4e5+5;
vector<int>e[N];
int n,m,r,st[N][20],dep[N];
void dfs(int p) {
  for(ri i=1;i<20;++i) st[p][i]=st[st[p][i-1]][i-1];
  for(ri i=0,v;i<(int)e[p].size();++i) {
    if((v=e[p][i])==st[p][0]) continue;
    st[v][0]=p,dep[v]=dep[p]+1,dfs(v);
  }
}
inline int getanc(int x,int d) {
  for(ri i=19;~i;--i) if(d>>i&1) x=st[x][i];
  return x;
}
inline int lca(int x,int y) {
  if(dep[x]<dep[y]) swap(x,y);
  x=getanc(x,dep[x]-dep[y]);
  if(x==y) return x;
  for(ri i=19;~i;--i) if(st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
  return st[x][0];
}
int ft[N],col[N],dis[N];
inline int find(int x) { return x^ft[x]?ft[x]=find(ft[x]):x; }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),r=read(),m=read();
  for(ri ct=n,i=1,u,v;i<n;++i) {
    u=read(),v=read(),++ct;
    e[u].pb(ct),e[v].pb(ct);
    e[ct].pb(u),e[ct].pb(v);
  }
  dfs(1);
  queue<int>q;
  memset(dis,-1,sizeof(dis));
  for(ri i=1,x;i<=m;++i) x=read(),ft[x]=x,q.push(x),dis[x]=0;
  while(q.size()) {
    int x=q.front();
    q.pop();
    if(dis[x]==r) break;
    for(ri i=0,v,fx,fy;i<(int)e[x].size();++i) {
      if(dis[v=e[x][i]]==-1) {
        dis[v]=dis[x]+1,ft[v]=find(ft[x]);
        q.push(v);
      }
      else {
        fx=find(ft[x]),fy=find(ft[v]);
        if(fx^fy) ft[fy]=fx;
      }
    }
  }
  for(ri l,x,y,d,_x,_y,tt=read();tt;--tt) {
    x=read(),y=read(),l=lca(x,y),d=dep[x]+dep[y]-2*dep[l];
    if(d<=r*2) { puts("YES");continue; }
    _x=dep[x]-dep[l]>=r?getanc(x,r):getanc(y,d-r);
    _y=dep[y]-dep[l]>=r?getanc(y,r):getanc(x,d-r);
    puts(ft[_x]&&ft[_y]&&find(ft[_x])==find(ft[_y])?"YES":"NO");
  }
  return 0;
}
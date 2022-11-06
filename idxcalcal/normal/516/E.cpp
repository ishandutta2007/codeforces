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
inline int getiv(int n,int m) {
  int x,y;
  exgcd(n,m,x,y);
  return (x%m+m)%m;
}
const int N=4e5+5;
int A,B,n,m,G,ivA,ivB;
inline int idxa(int x) { return (ll)x*ivB%A; }
inline int idxb(int x) { return (ll)x*ivA%B; }
vector<int> a[N],b[N];
typedef pair<int,ll> pil;
vector<pil> e[N];
typedef pair<ll,int> pli;
inline ll solve(vector<int> a,vector<int> b,bool rev) {
  static ll dis[N];
  static bool vs[N],ban[N];
  if(!a.size()&&!b.size()) return -1;
  if(rev) swap(A,B),swap(ivA,ivB);
  priority_queue<pli> q;
  vector<int> pt;
  int n=a.size(),m=b.size();
  for(ri i=0,x;i<n;++i) pt.pb(x=a[i]),pt.pb(x?x-1:A-1);
  for(ri i=0,x;i<m;++i) pt.pb(x=((ll)b[i]*A%B*ivB%A)),pt.pb(x?x-1:A-1);
  sort(pt.begin(),pt.end()),pt.erase(unique(pt.begin(),pt.end()),pt.end());
  for(ri i=1;i<=pt.size();++i) dis[i]=1e18;
  for(ri i=0,rk;i<n;++i) {
    rk=lower_bound(pt.begin(),pt.end(),a[i])-pt.begin()+1;
    ban[rk]=1,q.push(pli(-(dis[rk]=(ll)a[i]*B%A),rk));
  }
  for(ri i=0,rk;i<m;++i) {
    rk=lower_bound(pt.begin(),pt.end(),(int)((ll)b[i]*A%B*ivB%A))-pt.begin()+1;
    if(dis[rk]>(ll)b[i]*A%B%A) q.push(pli(-(dis[rk]=(ll)b[i]*A%B%A),rk));
  }
  for(ri i=1;i<pt.size();++i) e[i].pb(pil(i+1,(ll)(pt[i]-pt[i-1])*B));
  if(pt.size()>1) e[pt.size()].pb(pil(1,(ll)(pt[0]+A-pt.back())*B));
  ll res=0;
  while(q.size()) {
    int x=q.top().se;
    q.pop();
    if(vs[x]) continue;
    vs[x]=1;
    if(!ban[x]) ckmax(res,dis[x]);
    for(ri i=0,v;i<e[x].size();++i) if(dis[v=e[x][i].fi]>dis[x]+e[x][i].se) {
      dis[v]=dis[x]+e[x][i].se;
      q.push(pli(-dis[v],v));
    }
  }
  for(ri i=1;i<=pt.size();++i) vs[i]=ban[i]=0,e[i].clear();
  if(rev) swap(A,B),swap(ivA,ivB);
  return res;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  A=read(),B=read(),ivA=getiv(A,B),ivB=getiv(B,A),G=gcd(A,B),A/=G,B/=G;
  n=read();
  for(ri i=1,x;i<=n;++i) x=read(),a[x%G].pb(idxa(x/G));
  m=read();
  for(ri i=1,x;i<=m;++i) x=read(),b[x%G].pb(idxb(x/G));
  if(n+m<G) return cout<<-1,0;
  if(A==1&&B==1) {
    int res=0;
    for(ri r=0;r<G;++r) {
      if(!a[r].size()&&!b[r].size()) return cout<<-1,0;
      if(!a[r].size()||!b[r].size()) res=r;
    }
    cout<<res;
    return 0;
  }
  ll res=0,t1,t2;
  for(ri r=0;r<G;++r) {
    t1=solve(a[r],b[r],0),t2=solve(b[r],a[r],1);
    if(t1==-1||t2==-1) return cout<<-1,0;
    if(t1||t2) ckmax(res,max(t1,t2)*G+r);
  }
  cout<<res;
  return 0;
}
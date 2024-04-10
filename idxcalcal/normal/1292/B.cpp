#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef vector<ll> Poly;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define pb push_back
#define fi first
#define se second
const int rlen=1<<18|1;
const ll inf=1e17;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline ll readl() {
  ll ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline int Read(char*s) {
  int top=0;
  char ch=gc();
  while(!isalpha(ch)&&!isdigit(ch)) ch=gc();
  while(isalpha(ch)||isdigit(ch)) s[++top]=ch,ch=gc();
  return top;
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
}
using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=1e5+5;
vector<pll>a;
ll dx1,dy1,dx2,dy2,sx,sy,t;
inline ll Abs(ll x) { return x<0?-x:x; }
inline ll dist(pll a,pll b) { return Abs(a.fi-b.fi)+Abs(a.se-b.se); }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  a.resize(2);
  int tot=1;
  a[1].fi=readl(),a[1].se=readl();
  dx1=readl(),dy1=readl(),dx2=readl(),dy2=readl();
  sx=readl(),sy=readl(),t=readl();
  while(1) {
    if(a[tot].fi+a[tot].se>=(t+sx+sy)*2&&(a[tot].fi>=sx||a[tot].se>=sy)) break;
    ll X=a[tot].fi*dx1+dx2;
    ll Y=a[tot].se*dy1+dy2;
    a.pb(pll(X,Y));
    ++tot;
  }
  int res=0;
  for(ri l=1;l<=tot;++l) for(ri r=l;r<=tot;++r) {
    if(dist(a[l],a[r])>t) break;
    if(min(dist(a[l],pll(sx,sy)),dist(a[r],pll(sx,sy)))+dist(a[l],a[r])<=t) ckmax(res,r-l+1);
  }
  cout<<res;
  return 0;
}
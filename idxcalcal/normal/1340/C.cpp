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
inline ll readl() {
  static ll ans;
  static int f;
  static char ch;
  ans=0,ch=gc(),f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
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
  inline int sqr(int a) { return (ll)a*a%mod; }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
} using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=10005,M=1005,K=1e7+N;
int n,m,g,r,a[N];
int dis[N][M];
bool vs[N][M];
inline int idx(int x,int y) { return m*x+y; }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read();
  for(ri i=1;i<=m;++i) a[i]=read();
  g=read(),r=read();
  sort(a+1,a+m+1);
  deque<pii> q;
  for(ri i=1;i<=m;++i) for(ri j=0;j<g;++j) dis[i][j]=0x3f3f3f3f;
  q.push_front(pii(1,0)),dis[1][0]=0;
  while(q.size()) {
    pii x=q.front();
    q.pop_front();
    int id=x.fi,r=x.se;
    if(id<m) {
      if(r+a[id+1]-a[id]==g) {
        if(dis[id+1][0]>dis[id][r]+1) {
          dis[id+1][0]=dis[id][r]+1;
          q.push_front(pii(id+1,0));
        }
      }
      else if(r+a[id+1]-a[id]<g) {
        if(dis[id+1][r+a[id+1]-a[id]]>dis[id][r]) {
          dis[id+1][r+a[id+1]-a[id]]=dis[id][r];
          q.push_back(pii(id+1,r+a[id+1]-a[id]));
        }
      }
    }
    if(id>1) {
      if(r+a[id]-a[id-1]==g) {
        if(dis[id-1][0]>dis[id][r]+1) {
          dis[id-1][0]=dis[id][r]+1;
          q.push_front(pii(id-1,0));
        }
      }
      else if(r+a[id]-a[id-1]<g) {
        if(dis[id-1][r+a[id]-a[id-1]]>dis[id][r]) {
          dis[id-1][r+a[id]-a[id-1]]=dis[id][r];
          q.push_back(pii(id-1,r+a[id]-a[id-1]));
        }
      }
    }
  }
  ll res=1e18;
  for(ri t=0;t<g;++t) {
    if(dis[m][t]==0x3f3f3f3f) continue;
    ll cur=(ll)dis[m][t]*(r+g)+t;
    if(!t) cur-=r;
    ckmin(res,cur);
  }
  cout<<(res^1000000000000000000ll?res:-1);
  return 0;
}
#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() getchar()
inline ll readl() {
  ll ans=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return ans;
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
int n,m;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=1<<readl();
  vector<vector<ll> >a(n,vector<ll>(n));
  for(ri i=0;i<n;++i) for(ri j=0;j<n;++j) a[i][j]=readl();
  m=readl();
  vector<pii>dt(m);
  for(ri i=0;i<m;++i) dt[i].fi=readl(),dt[i].se=readl();
  for(ri i=1;i<m;++i) dt[i].fi-=dt[0].fi,dt[i].se-=dt[0].se;
  dt[0]=pii(0,0); 
  for(ri t=1;t<=n;t<<=1) {
    vector<vector<ll> >cur(n,vector<ll>(n));
    for(ri i=0;i<n;++i) for(ri j=0;j<n;++j) {
      cur[i][j]=0;
      for(ri k=0;k<m;++k) cur[i][j]^=a[((i-dt[k].fi)%n+n)%n][((j-dt[k].se)%n+n)%n];
    }
    a=cur;
    for(ri i=0;i<m;++i) dt[i].fi<<=1,dt[i].se<<=1;
  }
  int res=0;
  for(ri i=0;i<n;++i) for(ri j=0;j<n;++j) if(a[i][j]) ++res;
  cout<<res;
  return 0;
}
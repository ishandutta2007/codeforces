#include<bits/stdc++.h>
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
inline int read() {
  int ans=0;
  char ch=gc();
  bool f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
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
const int N=1005;
pii a[N];
int n;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  for(ri i=1;i<=n;++i) a[i].fi=read(),a[i].se=read();
  while(1) {
    bool ff1=1,ff2=1;
    for(ri i=1;i<=n;++i) if((a[i].fi^a[i].se)&1) ff1=0;else ff2=0;
    if(!(ff1||ff2)) break;
    if(ff1) for(ri i=1;i<=n;++i) --a[i].fi;
    else for(ri i=1,a0,a1;i<=n;++i) a0=a[i].fi,a1=a[i].se,a[i].fi=(a0+a1)>>1,a[i].se=(a0-a1)>>1;
  }
  vector<int>res;
  for(ri i=1;i<=n;++i) if((a[i].fi^a[i].se)&1) res.pb(i);
  cout<<(int)res.size()<<'\n';
  for(ri i=0;i<(int)res.size();++i) cout<<res[i]<<' ';
  return 0;
}
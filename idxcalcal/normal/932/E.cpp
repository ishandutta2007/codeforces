#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
#define pb push_back
#define fi first
#define se second
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
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
using namespace modular;
const int N=5005;
int fac[N],ifac[N],s[N][N],n,K;
inline void init() {
  fac[0]=fac[1]=ifac[0]=ifac[1]=1;
  for(ri i=2;i<=K;++i) {
    fac[i]=mul(fac[i-1],i);
    ifac[i]=mul(ifac[mod-mod/i*i],mod-mod/i);
  }
  for(ri i=2;i<=K;++i) Mul(ifac[i],ifac[i-1]);
  s[0][0]=1;
  for(ri i=1;i<=K;++i) for(ri j=1;j<=i;++j) s[i][j]=add(s[i-1][j-1],mul(s[i-1][j],j));
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),K=read();
  init();
  int mt1=ksm(2,n-1),iv=mod+1>>1,mt2=n,res=0;
  for(ri i=1;i<=K;Mul(mt1,iv),Mul(mt2,n-i),++i) Add(res,mul(mul(mt1,mt2),s[K][i]));
  cout<<res;
  return 0;
}
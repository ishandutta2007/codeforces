#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
const int rlen=1<<18|1,inf=0x3f3f3f3f,blo=(1<<15)-1;
const ll Inf=1e18;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  int ans=0;
  char ch=gc();
  bool f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline int Read(char*s) {
  int top=0;
  char ch=gc();
  while(!isalpha(ch)) ch=gc();
  while(isalpha(ch)) s[++top]=ch,ch=gc();
  return top;
}
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
template<typename T> inline T gcd(T a,T b) { return b?gcd(b,a%b):a; }
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
const int N=1505,M=1e5+5;
int n,m,p0,K,P[M],pw1[M],pw2[M],fac[M],ifac[M],ss[M],s1[2][N],s2[2][N],s3[2][N],cur;
inline int C(int n,int m) { return n<m||m<0?0:mul(fac[n],mul(ifac[m],ifac[n-m])); }
inline void init_fac() {
  fac[0]=fac[1]=ifac[0]=ifac[1]=pw1[0]=pw2[0]=1;
  pw1[1]=p0,pw2[1]=dec(1,p0);
  for(ri i=2;i<=K;++i) {
    pw1[i]=mul(pw1[i-1],pw1[1]);
    pw2[i]=mul(pw2[i-1],pw2[1]);
    fac[i]=mul(fac[i-1],i);
    ifac[i]=mul(ifac[mod-mod/i*i],mod-mod/i);
  }
  for(ri i=2;i<=K;++i) Mul(ifac[i],ifac[i-1]);
  for(ri i=0;i<=K;++i) P[i]=mul(C(K,i),mul(pw1[i],pw2[K-i]));
  ss[0]=P[0];
  for(ri i=1;i<=m;++i) ss[i]=add(ss[i-1],P[i]);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),p0=read(),Mul(p0,Inv(read())),K=read();
  init_fac();
  cur=0,s1[cur][m]=s2[cur][m]=1,s3[cur][m]=P[m];
  for(ri i=1;i<=n;++i) {
    cur^=1;
    for(ri r=1;r<=m;++r) {
      s1[cur][r]=mul(dec(s2[cur^1][m],s2[cur^1][m-r]),mul(ss[r-1],P[m-r]));
      Dec(s1[cur][r],mul(P[m-r],s3[cur^1][r-1]));
      s2[cur][r]=add(s2[cur][r-1],s1[cur][r]);
      s3[cur][r]=add(s3[cur][r-1],mul(s2[cur][r],P[r]));
    }
  }
  cout<<s2[cur][m];
  return 0;
}
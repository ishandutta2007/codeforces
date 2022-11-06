#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
#define fi first
#define se second
#define pb push_back
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
}
using namespace modular;
const int N=3505;
int n,a[N],m,k,vl[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    n=read(),m=read(),k=read();
    for(ri i=1;i<=n;++i) a[i]=read();
    int len=n-m+1;
    for(ri x=0;x<=m-1;++x) vl[x]=max(a[x+1],a[n-(m-1-x)]);
    int res=0;
    k=min(k,m-1);
    for(ri x=0;x<=k;++x) {
      int mn=0x3f3f3f3f;
      for(ri i=x;i<=m-1-(k-x);++i) mn=min(mn,vl[i]);
      res=max(res,mn);
    }
    cout<<res<<'\n';
  }
  return 0;
}
#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define rsz resize
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
  while(!isdigit(ch)&&!isalpha(ch)) ch=gc();
  while(isdigit(ch)||isalpha(ch)) s[++top]=ch,ch=gc();
  return top;
}
namespace modular {
  const int mod=10007;
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
}
using namespace modular;
const int N=1805;
inline void operator+=(poly&a,poly b) {
  int n=b.size();
  if(a.size()<n) a.resize(n);
  for(ri i=0;i<n;++i) Add(a[i],b[i]);
}
namespace BM {
  poly f[2],bst;
  int cur=0,Bst=0,cnt=0,dt[N],fail[N],a[N];
  inline void ins(int n) {
    dt[n]=a[n];
    for(ri i=1;i<f[cur].size();++i) Dec(dt[n],mul(f[cur][i],a[n-i]));
    if(!dt[n]) return;
    fail[cnt++]=n,cur^=1;
    if(cnt==1) return f[cur].rsz(n+1,0);
    int t=mul(Inv(dt[fail[Bst]]),dt[n]);
    f[cur].rsz(0),f[cur].rsz(n-fail[Bst]),f[cur].pb(t),t=t?mod-t:0;
    for(ri i=1;i<bst.size();++i) f[cur].pb(mul(t,bst[i]));
    if(f[cur].size()>=f[cur^1].size()) Bst=cnt-1,bst=f[cur^1];
    f[cur]+=f[cur^1];
  }
  inline poly solve(int*_a,int n) { for(ri i=1;i<=n;++i) a[i]=_a[i],ins(i);return f[cur].size()?f[cur]:poly(1,0); }
}
char s[205];
int F[N],lm,f[N][205][205],g[N],a[N];
inline poly operator*(poly a,poly b) {
  int n=a.size(),m=b.size(),t=n+m-1;
  if(!n||!m) return poly(0);
  poly c(t);
  for(ri i=0;i<n;++i) if(a[i]) for(ri j=0;j<m;++j) Add(c[i+j],mul(a[i],b[j]));
  return c;
}
inline poly operator%(poly a,poly b) {
  int n=a.size(),m=b.size(),iv;
  if(n<m) return a;
  iv=b.back();
  for(ri i=0;i<b.size();++i) Mul(b[i],iv);
  for(ri t,i=n-m;~i;--i) if((t=a[t=i+m-1])>0)
  for(ri dt=0;dt<m;++dt) Dec(a[i+dt],mul(t,b[dt]));
  return a.rsz(m-1),a;
}
inline void solve(int*a,int m,int n) {
  poly md=BM::solve(a,m);
  md[0]=mod-1;
  reverse(md.begin(),md.end());
  for(ri i=0;i<md.size();++i) md[i]=md[i]?mod-md[i]:0;
  poly res=poly(1,1),A(2);
  A[1]=1;
  for(;n;n>>=1,A=A*A%md) if(n&1) res=res*A%md;
  int ss=0;
  for(ri i=0;i<res.size();++i) Add(ss,mul(res[i],a[i]));
  cout<<ss;
}
int n,m;
inline void DP() {
  f[0][1][n]=1,lm=n<<3|5;
  for(ri t=1,trs;t+t<=lm;++t) {
    g[t]=mul(g[t-1],26);
    for(ri l=1;l<=n;++l) for(ri r=l;r<=n;++r) if((trs=f[t-1][l][r])>0) {
      if(s[l]==s[r]) {
        Add(f[t][l][r],mul(trs,25));
        if(l+1<=r-1) Add(f[t][l+1][r-1],trs);
        else Add(g[t],trs);
      }
      else {
        Add(f[t][l][r],mul(trs,24));
        Add(f[t][l+1][r],trs);
        Add(f[t][l][r-1],trs);
      }
    }
  }
  for(ri t=1;t<=lm;++t) {
    if(t&1) {
      F[t]=mul(26,g[t>>1]);
      for(ri i=1;i<=n;++i) Add(F[t],f[t>>1][i][i]);
    }
    else F[t]=g[t>>1];
  }
  solve(F+n,lm-n,m);
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=Read(s),m=read();
  DP();
  return 0;
}
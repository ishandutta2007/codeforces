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
inline int Read(char*s) {
  int top=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) s[++top]=ch,ch=gc();
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
const int N=2e5+5;
char s[N];
int n,nxt[N],blo,pre[N];
tr1::unordered_map<ll,int> cnt;
inline ll C2(int x) { return (ll)x*(x-1)>>1; }
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=Read(s),blo=min(n,150);
  for(ri i=n,nxt_=n+1;i;--i) {
    if(s[i]=='1') nxt_=i;
    nxt[i]=nxt_;
  }
  for(ri i=1;i<=n;++i) pre[i]=pre[i-1]+(s[i]=='1');
  ll res=0;
  for(ri t=1;t<=blo;++t) {
    cnt.clear();
    for(ri i=0;i<=n;++i) ++cnt[i-pre[i]*t];
    for(tr1::unordered_map<ll,int>::iterator it=cnt.begin();it!=cnt.end();++it) res+=C2(it->se);
  }
  for(ri r,len,l=1,tm;l<=n;++l) {
    tm=1;
    r=nxt[l];
    while(r<=n&&l-1+tm*blo<=n) {
      len=(nxt[r+1]-l)/tm;
      res+=max(0,len-max(blo,(r-l)/tm));
      r=nxt[r+1],++tm;
    }
  }
  cout<<res;
  return 0;
}
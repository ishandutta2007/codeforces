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
const int N=1e6+5;
int n,nxt[N],du[N],que[N],hd,tl;
bool vs[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    n=read();
    for(ri i=1;i<=n;++i) du[i]=vs[i]=0;
    for(ri i=1;i<=n;++i) nxt[i]=i-read(),++du[nxt[i]];
    for(ri i=1;i<=n;++i) if(!du[i]) que[++tl]=i;
    while(hd<=tl) {
      int x=que[hd++];
      vs[x]=1;
      --du[nxt[x]];
      if(!du[nxt[x]]) que[++tl]=nxt[x];
    }
    for(ri i=1;i<=n;++i) if(!vs[i]) {
      vector<int>res;
      while(!vs[i]) {
        res.pb(i);
        vs[i]=1;
        i=nxt[i];
      }
      cout<<(int)res.size()<<'\n';
      for(ri i=0;i<(int)res.size();++i) cout<<res[i]<<' ';
      puts("");
      break;
    }
  }
  return 0;
}
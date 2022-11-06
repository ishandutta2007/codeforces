#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
#define pb push_back
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
inline int reads(char*s) {
  int top=0;
  char ch=gc();
  while(!isalpha(ch)) ch=gc();
  while(isalpha(ch)) s[++top]=ch,ch=gc();
  return top;
}
inline int readf(int*s) {
  int top=0;
  char ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) s[++top]=ch^48,ch=gc();
  return top;
}
namespace modular {
  const int mod=1e9+7;
  inline int add(int a,int b){return a+b<mod?a+b:a+b-mod;}
  inline int dec(int a,int b){return a<b?a-b+mod:a-b;}
  inline int mul(int a,int b){return (ll)a*b%mod;}
  inline void Add(int&a,int b){a=a+b<mod?a+b:a+b-mod;}
  inline void Dec(int&a,int b){a=a<b?a-b+mod:a-b;}
  inline void Mul(int&a,int b){a=(ll)a*b%mod;}
  inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
  inline int Inv(int a){return ksm(a,mod-2);}
  inline int fix(int a){return (a%mod+mod)%mod;}
}
using namespace modular;
const int N=65;
char s[65][65];
bool trans1[N],trans2[N];
int n,m;
signed main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    n=read(),m=read();
    bool ff1=0,ff2=0;
    for(ri i=1;i<=n;++i) trans1[i]=1;
    for(ri i=1;i<=m;++i) trans2[i]=1;
    for(ri i=1;i<=n;++i) {
      reads(s[i]);
      for(ri j=1;j<=m;++j) {
        if(s[i][j]=='A') ff1=1;
        else {
          ff2=1;
          trans1[i]=trans2[j]=0;
        }
      }
    }
    if(!ff1) { puts("MORTAL");continue; }
    if(!ff2) { puts("0");continue; }
    if(trans1[1]||trans1[n]||trans2[1]||trans2[m]) { puts("1");continue; }
    bool ff=0;
    for(ri i=2;i<n;++i) if(trans1[i]) ff=1;
    for(ri i=2;i<m;++i) if(trans2[i]) ff=1;
    if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A') ff=1;
    if(ff) { puts("2");continue; }
    for(ri i=1;i<=n;i+=n-1) {
      bool fff=0;
      for(ri j=1;j<=m;++j) if(s[i][j]=='A') fff=1;
      if(fff) ff=1;
    }
    for(ri i=1;i<=m;i+=m-1) {
      bool fff=0;
      for(ri j=1;j<=n;++j) if(s[j][i]=='A') fff=1;
      if(fff) ff=1;
    }
    if(ff) { puts("3");continue; }
    puts("4");
  }
  return 0;
}
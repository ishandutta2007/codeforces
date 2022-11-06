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
const int N=505;
int s[2000005];
signed main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri t,tt=read();tt;--tt) {
    t=read();
    int all,len=readf(s);
    all=len;
    for(ri i=1;i<=t;++i) {
      int lim=len,limm=all;
      for(ri j=1;j<s[i];++j) {
        Add(all,dec(limm,i));
        int ps=i+1;
        while(ps<=lim&&len<t) {
          s[++len]=s[ps];
          ++ps;
        }
      }
    }
    cout<<all<<'\n';
  }
  return 0;
}
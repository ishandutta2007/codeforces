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
using namespace modular;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
  	int mx1=0,mx2=0,n,a,b;
  	n=read(),a=read(),b=read();
  	for(ri i=1;i<=a;++i) mx1=max(mx1,read());
  	for(ri i=1;i<=b;++i) mx2=max(mx2,read());
  	cout<<(mx1>mx2?"YES":"NO")<<'\n';
	}
  return 0;
}
#include<bits/stdc++.h>
#define ri register int
using namespace std;
typedef long long ll;
typedef vector<int> poly;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define pb push_back
#define rez resize
const ll Inf=1e18;
const int rlen=1<<20;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans,f;
  static char ch;
  ans=0,ch=gc(),f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
}
inline ll readl() {
  static ll ans;
  static int f;
  static char ch;
  ans=0,ch=gc(),f=1;
  while(!isdigit(ch)) f^=ch=='-',ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return f?ans:-ans;
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
  inline int sqr(int a) { return (ll)a*a%mod; }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
} using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=2005;
string s[10];
int sta[10],ss[N],cnt[10],Cnt[N],n,m;
bool f[N][N];
inline void dfs(int ps,int lm) {
  if(ps==n+1) return;
  for(ri i=9;~i;--i) if((sta[i]&ss[ps])==ss[ps]) {
    int dt=cnt[i]-Cnt[ps];
    if(lm>=dt&&f[ps+1][lm-dt]) return cout<<i,dfs(ps+1,lm-dt);
  }
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  s[0]="1110111";
  cnt[0]=6;
  s[1]="0010010";
  cnt[1]=2;
  s[2]="1011101";
  cnt[2]=5;
  s[3]="1011011";
  cnt[3]=5;
  s[4]="0111010";
  cnt[4]=4;
  s[5]="1101011";
  cnt[5]=5;
  s[6]="1101111";
  cnt[6]=6;
  s[7]="1010010";
  cnt[7]=3;
  s[8]="1111111";
  cnt[8]=7;
  s[9]="1111011";
  cnt[9]=6;
  for(ri i=0;i<10;++i) for(ri j=0;j<7;++j) sta[i]<<=1,sta[i]|=(s[i][j]-'0');
  n=read(),m=read();
  for(ri i=1;i<=n;++i) {
    char ch=gc();
    while(!isdigit(ch)) ch=gc();
    while(isdigit(ch)) ss[i]=(ss[i]<<1)+(ch^48),Cnt[i]+=ch^48,ch=gc();
  }
  f[n+1][0]=1;
  for(ri i=n;i;--i) {
    for(ri j=0;j<10;++j) {
      if((sta[j]&ss[i])==ss[i]) {
        int dt=cnt[j]-Cnt[i];
        for(ri k=dt;k<=m;++k) f[i][k]|=f[i+1][k-dt];
      }
    }
  }
  if(!f[1][m]) return cout<<-1,0;
  dfs(1,m);
  return 0;
}
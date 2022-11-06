#include<bits/stdc++.h>
#include<tr1/unordered_map>
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
#define gc() getchar()//(((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read() {
  static int ans;
  static char ch;
  ans=0,ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return ans;
}
inline ll readl() {
  static ll ans;
  static char ch;
  ans=0,ch=gc();
  while(!isdigit(ch)) ch=gc();
  while(isdigit(ch)) ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc();
  return ans;
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
  inline int Inv(int a) { return ksm(a,mod-2); }
  inline int sqr(int a) { return (ll)a*a%mod; }
  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
} using namespace modular;
template<typename T> inline void ckmax(T&a,T b) { a<b?a=b:0; }
template<typename T> inline void ckmin(T&a,T b) { a>b?a=b:0; }
const int N=105;
int a[N],b[N],n,ct=0,id[N*N<<1];
int res[N];
inline void ins(int x) { --ct,cout<<"+ "<<x<<endl<<endl,a[ct]=read(),b[ct]=read(); }
int main() {
  n=read(),a[n+1]=read(),b[n+1]=read();
  id[0]=1;
  for(ri i=1;i<=n;++i) id[i*(i+1)/2]=i+1;
  ct=n+1;
  for(ri i=2;i<n-1;++i) ins(i);
  ins(n),ins(n-1),ins(n);
  res[n]=id[a[1]-a[2]]-1;
  res[n-2]=(b[1]-b[2])-(b[3]-b[4])-1;
  res[n-1]=(b[1]-b[2])/(res[n-2]+1)-1;
  res[n-3]=(b[2]-b[3])/(res[n-2]+1)-res[n]-1-(n>4);
  for(ri i=n-4;i;--i) res[i]=(b[n-i]-b[n-i+1]-res[i+3]*res[i+4])/(res[i+1]+1)-res[i+3]-(i>1);
  cout<<"! ";
  for(ri i=1;i<=n;++i) {
    cout<<res[i];
    if(i==n) cout<<endl<<endl;
    else cout<<' ';
  }
  return 0;
}
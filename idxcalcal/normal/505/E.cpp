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
}
using namespace modular;
const int N=1e5+5;
int n,m,K;
ll cur[N],a[N],h[N],dt;
typedef pair<ll,int> pli;
inline bool check(ll t) {
  priority_queue<pli>q;
  for(ri i=1;i<=n;++i) {
    cur[i]=t;
    if(t-a[i]*m<h[i]) q.push(pli(-t/a[i],i));
  }
  ll tmp;
  for(ri id,Turn=1;Turn<=m;++Turn) for(ri tim=K;tim;--tim) {
    if(!q.size()) return 1;
    pli cr=q.top();
    q.pop(),tmp=-cr.fi,id=cr.se;
    if(tmp<Turn) return 0;
    cur[id]+=dt;
    if(cur[id]-a[id]*m<h[id]) q.push(pli(-cur[id]/a[id],id));
  }
  return !q.size();
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read(),m=read(),K=read(),dt=read();
  ll L=0,R=0,res;
  for(ri i=1;i<=n;++i) h[i]=read(),L=max(L,a[i]=read()),R=max(R,h[i]+a[i]*m);
  res=R;
  while(L<=R) {
    ll mid=(L+R)>>1;
    if(check(mid)) R=mid-1,res=mid;
    else L=mid+1;
  }
  cout<<res;
  return 0;
}
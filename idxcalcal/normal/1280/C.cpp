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
const int N=6e5+5;
vector<pii>e[N<<1];
int n,siz[N],_siz[N];
ll res1=0,res2=0;
void dfs(int p,int ft) {
  siz[p]=1,_siz[p]=1;
  for(ri i=0,v;i<(int)e[p].size();++i) {
    if((v=e[p][i].fi)==ft) continue;
    dfs(v,p),siz[p]+=siz[v];
    if(siz[v]&1) res1+=e[p][i].se;
    res2+=(ll)_siz[v]*e[p][i].se;
    _siz[p]+=_siz[v];
  }
  _siz[p]=min(_siz[p],n-siz[p]);
}
signed main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    n=read()<<1;
    for(ri i=1;i<=n;++i) e[i].clear();
    for(ri i=1,u,v,w;i<n;++i) {
      u=read(),v=read(),w=read();
      e[u].pb(pii(v,w));
      e[v].pb(pii(u,w));
    }
    res1=res2=0;
    dfs(1,0);
    cout<<res1<<' '<<res2<<'\n';
  }
  return 0;
}
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
const int N=3005;
int f[N][N],tf[N];
ll g[N][N],tg[N];
int n,a[N],m,siz[N];
vector<int>e[N];
void dfs(int p,int ft) {
  f[p][1]=0;
  g[p][1]=a[p];
  siz[p]=1;
  for(ri i=0,v;i<(int)e[p].size();++i) {
    if((v=e[p][i])==ft) continue;
    dfs(v,p);
    for(ri x=1;x<=siz[p]+siz[v]&&x<=m;++x) tf[x]=0,tg[x]=-1e18;
    for(ri a=1;a<=siz[v]&&a<=m;++a) for(ri b=1;b<=siz[p]&&a+b<=m+1;++b) {
      if(a+b<=m) {
        if(tf[a+b]<f[v][a]+f[p][b]+(g[v][a]>0)) tf[a+b]=f[v][a]+f[p][b]+(g[v][a]>0),tg[a+b]=g[p][b];
        else if(tf[a+b]==f[v][a]+f[p][b]+(g[v][a]>0)) tg[a+b]=max(tg[a+b],g[p][b]);
      }
      if(tf[a+b-1]<f[v][a]+f[p][b]) tf[a+b-1]=f[v][a]+f[p][b],tg[a+b-1]=g[v][a]+g[p][b];
      else if(tf[a+b-1]==f[v][a]+f[p][b]) tg[a+b-1]=max(tg[a+b-1],g[v][a]+g[p][b]);
    }
    siz[p]+=siz[v];
    for(ri x=1;x<=siz[p]&&x<=m;++x) f[p][x]=tf[x],g[p][x]=tg[x];
  }
}
signed main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  for(ri tt=read();tt;--tt) {
    n=read(),m=read();
    for(ri i=1;i<=n;++i) e[i].clear();
    for(ri i=1;i<=n;++i) a[i]=-read();
    for(ri i=1;i<=n;++i) a[i]+=read();
    for(ri i=1,u,v;i<n;++i)  {
      u=read(),v=read();
      e[u].pb(v);
      e[v].pb(u);
    }
    dfs(1,0);
    cout<<f[1][m]+(g[1][m]>0)<<'\n';
  }
  return 0;
}
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
//namespace modular {
//  const int mod=998244353;
//  inline int add(int a,int b) { return a+b<mod?a+b:a+b-mod; }
//  inline int dec(int a,int b) { return a<b?a-b+mod:a-b; }
//  inline int mul(int a,int b) { return (ll)a*b%mod; }
//  inline void Add(int&a,int b) { a=a+b<mod?a+b:a+b-mod; }
//  inline void Dec(int&a,int b) { a=a<b?a-b+mod:a-b; }
//  inline void Mul(int&a,int b) { a=(ll)a*b%mod; }
//  inline int ksm(int a,int p) { int ret=1;for(;p;p>>=1,Mul(a,a)) (p&1)&&(Mul(ret,a),1);return ret; }
//  inline int Inv(int a) { return ksm(a,mod-2); }
//  inline int sqr(int a) { return (ll)a*a%mod; }
//  inline int cub(int a) { return (ll)a*a%mod*a%mod; }
//}
namespace modular {
  inline int add(int a,int b,int mod) { return a+b<mod?a+b:a+b-mod; }
  inline int dec(int a,int b,int mod) { return a<b?a-b+mod:a-b; }
  inline int mul(int a,int b,int mod) { return (ll)a*b%mod; }
  inline void Add(int&a,int b,int mod) { a=a+b<mod?a+b:a+b-mod; }
  inline void Dec(int&a,int b,int mod) { a=a<b?a-b+mod:a-b; }
  inline void Mul(int&a,int b,int mod) { a=(ll)a*b%mod; }
  inline int ksm(int a,int p,int mod) { int ret=1;for(;p;p>>=1,Mul(a,a,mod)) (p&1)&&(Mul(ret,a,mod),1);return ret; }
  inline int Inv(int a,int mod) { return ksm(a,mod-2,mod); }
}
using namespace modular;
const int N=3e5+5;
int n,m,siz[N],hson[N],dep[N],top[N],fa[N],st[N][20],Top[N],mdep[N],lson[N],Lg[N];
vector<int>e[N],dwn[N],upp[N];
char s[N];
const int md1=998244353,md2=1e9+7,bs1=37,bs2=41;
inline pii operator+(pii a,pii b) { return pii(add(a.fi,b.fi,md1),add(a.se,b.se,md2)); }
inline pii operator*(pii a,pii b) { return pii(mul(a.fi,b.fi,md1),mul(a.se,b.se,md2)); }
inline pii operator-(pii a,pii b) { return pii(dec(a.fi,b.fi,md1),dec(a.se,b.se,md2)); }
pii A[N],B[N],pw[N],ipw[N];
void dfs1(int p) {
  siz[p]=1,mdep[p]=dep[p];
  for(ri i=1;i<20;++i) st[p][i]=st[st[p][i-1]][i-1];
  B[p]=B[fa[p]]*pii(bs1,bs2)+pii(s[p]-'a'+5,s[p]-'a'+5);
  A[p]=A[fa[p]]+pw[dep[p]]*pii(s[p]-'a'+5,s[p]-'a'+5);
  for(ri i=0,v;i<e[p].size();++i) if((v=e[p][i])!=fa[p]) {
    st[v][0]=fa[v]=p,dep[v]=dep[p]+1,dfs1(v),siz[p]+=siz[v];
    if(mdep[v]>mdep[p]) mdep[p]=mdep[v],lson[p]=v;
    if(siz[v]>siz[hson[p]]) hson[p]=v;
  }
}
void dfs2(int p,int tp1,int tp2) {
  top[p]=tp1,Top[p]=tp2;
  if(p==tp2) for(ri i=0,x=p,y=p;i<=mdep[p]-dep[p];++i,x=lson[x],y=fa[y]) {
    dwn[p].pb(x);
    upp[p].pb(y); 
  }
  for(ri i=0,v;i<e[p].size();++i) if((v=e[p][i])!=fa[p]) dfs2(v,v^hson[p]?v:tp1,v^lson[p]?v:tp2);
}
inline int lca(int x,int y) {
  while(top[x]^top[y]) dep[top[x]]>dep[top[y]]?x=fa[top[x]]:y=fa[top[y]];
  return dep[x]<dep[y]?x:y;
}
inline int findft(int x,int t) {
  if(!t) return x;
  int k=Lg[t];
  x=st[x][k],t-=(1<<k)+dep[x]-dep[Top[x]];
  return t>=0?upp[Top[x]][t]:dwn[Top[x]][-t];
}
inline pii get(int x,int y,int t,int l) {
  if(dep[x]-dep[t]+1>=l) {
    int X=findft(x,l-1);
    return (A[x]-A[fa[X]])*ipw[dep[X]];
  }
  pii res1=(A[x]-A[fa[t]])*ipw[dep[t]],res2;
  l=(dep[y]-dep[t])-(l-dep[x]+dep[t]-1);
  int X=findft(y,l);
  res2=B[X]-B[t]*pw[dep[X]-dep[t]];
  return res1*pw[dep[X]-dep[t]]+res2;
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in","r",stdin);
  #endif
  n=read();
  Read(s);
  pw[0]=ipw[0]=pii(1,1),pw[1]=pii(bs1,bs2),ipw[1]=pii(Inv(bs1,md1),Inv(bs2,md2));
  for(ri i=2;i<=n;++i) Lg[i]=Lg[i>>1]+1;
  for(ri i=1;i<=n;++i) {
    pw[i]=pw[i-1]*pw[1];
    ipw[i]=ipw[i-1]*ipw[1];
  }
  for(ri i=1,u,v;i<n;++i) {
    u=read(),v=read();
    e[u].pb(v),e[v].pb(u);
  }
  dfs1(1),dfs2(1,1,1);
  for(ri tt=read(),x1,x2,y1,y2,t1,t2,l1,l2;tt;--tt) {
    x1=read(),y1=read(),t1=lca(x1,y1),l1=dep[x1]+dep[y1]-dep[t1]*2+1;
    x2=read(),y2=read(),t2=lca(x2,y2),l2=dep[x2]+dep[y2]-dep[t2]*2+1;
    int L=1,R=min(l1,l2),res=0;
    while(L<=R) {
      int mid=(L+R)>>1;
      if(get(x1,y1,t1,mid)==get(x2,y2,t2,mid)) res=mid,L=mid+1;
      else R=mid-1;
    }
    cout<<res<<'\n';
  }
  return 0;
}
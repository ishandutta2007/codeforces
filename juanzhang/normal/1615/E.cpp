#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=2e5+10;
int n,k;

vi E[maxn];

bool vis[maxn];
int fa[maxn],dfn[maxn],seq[maxn],dep[maxn],sz[maxn];
void dfs(int u,int f){
  static int now;
  dfn[u]=++now,seq[now]=u;
  fa[u]=f,dep[u]=dep[f]+1,sz[u]=1;
  for(int v:E[u])if(v!=f){
    dfs(v,u),sz[u]+=sz[v];
  }
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

pii val[maxn<<2];int tag[maxn<<2];
void pushtag(int k,int x){
  val[k].first+=x,tag[k]+=x;
}
void pushdown(int k){
  int&x=tag[k];
  if(x){
    pushtag(k<<1,x);
    pushtag(k<<1|1,x);
    x=0;
  }
}
void maintain(int k){
  val[k]=max(val[k<<1],val[k<<1|1]);
}
void build(int k,int l,int r){
  if(l==r)val[k]={dep[seq[l]],seq[l]};
  else build(lson),build(rson),maintain(k);
}
void add(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr)return pushtag(k,x);
  pushdown(k);
  if(ql<=mid)add(lson,ql,qr,x);
  if(qr>mid)add(rson,ql,qr,x);
  maintain(k);
}
void del(int k,int l,int r,int x){
  if(l==r)val[k]={-1,-1};
  else pushdown(k),x<=mid?del(lson,x):del(rson,x),maintain(k);
}

#undef mid
#undef lson
#undef rson

void solve(){
  n=read(),k=read();
  rep(i,2,n){
    int u=read(),v=read();
    E[u].push_back(v),E[v].push_back(u);
  }
  dfs(1,0);
  build(1,1,n);
  ll ans=-1e18;
  int can=n;
  rep(i,1,k){
    int u=val[1].second;
    can-=val[1].first;
    del(1,1,n,dfn[u]);
    for(int v=u;v;v=fa[v]){
      if(vis[v])break;
      vis[v]=1;
      add(1,1,n,dfn[v],dfn[v]+sz[v]-1,-1);
    }
    ll tmp=1e18;
    chkmin(tmp,1ll*can*(can-n));
    if(can>=n/2)chkmin(tmp,1ll*(n/2)*(n/2-n));
    if(can>=n/2+1)chkmin(tmp,1ll*(n/2+1)*(n/2+1-n));
    tmp+=1ll*n*i-1ll*i*i;
//    rep(j,0,can)chkmin(tmp,1ll*(n-i-j)*(i-j));
    // n*i-n*j-i*i+j*j
    // n*i-i*i+(j-n)*j
    chkmax(ans,tmp);
    // st r=i,b=0..can : min (n-r-b)(r-b)
  }
  cout<<ans<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}
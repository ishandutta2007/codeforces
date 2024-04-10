#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=2e5+10,P=1e9+7;
int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}
int n=1,q,A[maxn],deg[maxn],inv[maxn];
struct node{
  int op,x,y;
}dat[maxn];
vi E[maxn];int fa[maxn],sz[maxn],son[maxn],top[maxn],dfn[maxn];
void dfs(int u){
  sz[u]=1;
  for(int v:E[u]){
    dfs(v),sz[u]+=sz[v];
    if(sz[son[u]]<sz[v])son[u]=v;
  }
}
void dfs2(int u,int tp){
  static int now;
  dfn[u]=++now,top[u]=tp;
  if(son[u])dfs2(son[u],tp);
  for(int v:E[u])if(v!=son[u])dfs2(v,v);
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int sum[maxn<<2],tag[maxn<<2],pro[maxn<<2];
void pushtag(int k,int x){
  Add(sum[k],1ll*x*pro[k]%P),Add(tag[k],x);
}
void pushdown(int k){
  int&x=tag[k];
  if(x)pushtag(k<<1|1,x),pushtag(k<<1,1ll*x*pro[k<<1|1]%P),x=0;
}
int hf;
void add(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return pushtag(k,hf),hf=1ll*hf*pro[k]%P,void();
  pushdown(k);
  if(qr>mid)add(rson,ql,qr);
  if(ql<=mid)add(lson,ql,qr);
}
void upd(int k,int l,int r,int x,int p){
  if(l==r)return pro[k]=p,void();pushdown(k);
  x<=mid?upd(lson,x,p):upd(rson,x,p),pro[k]=1ll*pro[k<<1]*pro[k<<1|1]%P;
}
int query(int k,int l,int r,int x){
  if(l==r)return sum[k];pushdown(k);
  return x<=mid?query(lson,x):query(rson,x);
}

#undef mid
#undef lson
#undef rson

void solve(){
  cin>>A[1]>>q;deg[1]=inv[1]=1;
  rep(i,2,q)inv[i]=1ll*(P-P/i)*inv[P%i]%P;
  rep(i,1,q){
    if((dat[i].op=read())==1){
      dat[i].x=read(),dat[i].y=read();
      E[dat[i].x].push_back(++n),fa[n]=dat[i].x,dat[i].x=n;
    }else{
      dat[i].x=read();
    }
  }
  dfs(1),dfs2(1,1),upd(1,1,n,1,1),hf=A[1],add(1,1,n,1,1);
  rep(i,1,q){
    int u=dat[i].x;
    if(dat[i].op==1){
      A[u]=dat[i].y;
      int f=fa[u],lst=query(1,1,n,dfn[f]),su=1ll*lst*inv[deg[f]]%P;
      int de=(su+A[u]+1ll*deg[f]*A[u])%P;
      hf=1ll*de*inv[deg[f]]%P,add(1,1,n,dfn[f],dfn[f]);
      upd(1,1,n,dfn[f],++deg[f]),upd(1,1,n,dfn[u],++deg[u]),hf=A[u],add(1,1,n,dfn[u],dfn[u]);
      hf=de,f=fa[f];
      while(f){
        add(1,1,n,dfn[top[f]],dfn[f]);
        f=fa[top[f]];
      }
    }else{
      printf("%d\n",query(1,1,n,dfn[u]));
    }
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
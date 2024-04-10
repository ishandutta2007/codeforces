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
const int maxn=2e5+10;
int n,m,q;

vi E[maxn];
int sz[maxn],dfn[maxn],dep[maxn],fa[maxn][18],up[maxn][18];
struct bus{
  int u,v;
}R[maxn];
void cmp(int&x,int y){if(y&&(!x||dep[x]>dep[y]))x=y;}
void dfs(int u){
  static int now;dfn[u]=++now,dep[u]=dep[fa[u][0]]+1,sz[u]=1;
  rep(i,1,17)fa[u][i]=fa[fa[u][i-1]][i-1];
  for(int v:E[u])dfs(v),sz[u]+=sz[v];
}
int qlca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
  per(i,17,0)if(dep[u]-(1<<i)>=dep[v])u=fa[u][i];
  if(u==v)return u;
  per(i,17,0)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
  return fa[u][0];
}
int qkth(int u,int k){
  per(i,17,0)if(k>>i&1)u=fa[u][i];return u;
}
int run(int&u,int anc){
  int res=0;
  per(i,17,0){
    int x=up[u][i];
    if(x&&dep[x]>dep[anc])u=x,res+=1<<i;
  }
  if(!up[u][0]||dep[up[u][0]]>dep[anc])return -1e9;
  return res;
}

vi fsn[maxn];
int tot,rt[maxn],su[maxn*40],ls[maxn*40],rs[maxn*40];
void ins(int&k,int rt,int l,int r,int x){
  su[k=++tot]=su[rt]+1,ls[k]=ls[rt],rs[k]=rs[rt];
  if(l==r)return;int mid=(l+r)/2;x<=mid?ins(ls[k],ls[rt],l,mid,x):ins(rs[k],rs[rt],mid+1,r,x);
}
int query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return su[k];int mid=(l+r)/2,res=0;
  if(ql<=mid)res=query(ls[k],l,mid,ql,qr);
  if(qr>mid)res+=query(rs[k],mid+1,r,ql,qr);
  return res;
}
int yysy(int x,int y){
  return query(rt[x],1,n,1,y);
}
bool check(int x1,int x2,int y1,int y2){
  int res=yysy(x2,y2);
  if(x1>1)res-=yysy(x1-1,y2);
  if(y1>1)res-=yysy(x2,y1-1);
  if(x1>1&&y1>1)res+=yysy(x1-1,y1-1);
  return res>0;
}

void solve(){
  cin>>n;
  rep(i,2,n)E[fa[i][0]=read()].push_back(i);
  dfs(1);
  cin>>m;
  rep(i,1,m){
    int u=read(),v=read(),anc=qlca(u,v);
    R[i]={u,v},cmp(up[u][0],anc),cmp(up[v][0],anc);
    fsn[dfn[u]].push_back(dfn[v]),fsn[dfn[v]].push_back(dfn[u]);
  }
  per(i,n,2)cmp(up[fa[i][0]][0],up[i][0]);
  rep(i,1,n){
    cmp(up[i][0],i);
    rep(j,1,17)up[i][j]=up[up[i][j-1]][j-1];
  }
//  putchar('#');rep(i,1,n)printf("%d ",up[i][0]);puts("");
  rep(i,1,n){
    rt[i]=rt[i-1];
    for(int x:fsn[i])ins(rt[i],rt[i],1,n,x);
  }
  cin>>q;
  while(q--){
    int u=read(),v=read(),anc=qlca(u,v);
    if(dep[u]<dep[v])swap(u,v);
    int res=run(u,anc);
    int l=0,r=dep[v]-dep[anc],nxt=anc;
    while(l<=r){
      int mid=(l+r)>>1;
      int ff=qkth(v,mid);
      check(dfn[u],dfn[u]+sz[u]-1,dfn[ff],dfn[ff]+sz[ff]-1)?nxt=ff,r=mid-1:l=mid+1;
    }
    res+=run(v,nxt);
    printf("%d\n",res<0?-1:res+1+(nxt!=v));
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
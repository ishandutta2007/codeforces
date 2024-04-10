#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=5e5+10;
int n,q;
int S,T,ecnt=1,h[maxn],eid[maxn<<1];
struct edges{int nxt,to,w;}E[maxn<<1];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}

int dfn[maxn],arr[maxn],dis[maxn],col[maxn],sz[maxn];
int bfs(int S){
  static int Q[maxn];
  memset(dis,-1,sizeof dis);
  int l=1,r=1;Q[1]=S,dis[S]=0;
  while(l<=r){
    int u=Q[l++];
    for(int i=h[u];i;i=E[i].nxt){
      int v=E[i].to;
      if(dis[v]==-1)dis[v]=dis[u]+1,Q[++r]=v;
    }
  }
  int res=S;
  rep(i,1,n)if(dis[res]<dis[i])res=i;
  return res;
}
void dfs(int u,int f){
  static int now;
  dfn[u]=++now,arr[now]=u,sz[u]=1;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f){
      col[v]=col[u]^E[i].w,eid[i^1]=eid[i]=v,dfs(v,u),sz[u]+=sz[v];
    }
  }
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

struct SGT{
  int val[maxn<<2][2],tag[maxn<<2];
  void maintain(int k){
    rep(t,0,1)val[k][t]=max(val[k<<1][t],val[k<<1|1][t]);
  }
  void pushtag(int k){
    tag[k]^=1,swap(val[k][0],val[k][1]);
  }
  void pushdown(int k){
    if(tag[k])tag[k]=0,pushtag(k<<1),pushtag(k<<1|1);
  }
  void build(int k,int l,int r){
    if(l==r)return val[k][col[arr[l]]]=dis[arr[l]],val[k][col[arr[l]]^1]=-1,void();
    build(lson),build(rson),maintain(k);
  }
  void upd(int k,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return pushtag(k),void();
    pushdown(k);
    if(ql<=mid)upd(lson,ql,qr);
    if(qr>mid)upd(rson,ql,qr);
    maintain(k);
  }
  int getc(int k,int l,int r,int p){
    if(l==r)return val[k][0]==-1?1:0;
    return pushdown(k),p<=mid?getc(lson,p):getc(rson,p);
  }
}TS,TT;

#undef mid
#undef lson
#undef rson

void solve() {
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read(),w=read();addline(u,v,w),addline(v,u,w);
  }
  dfs(1,0);
  S=bfs(1),T=bfs(S);
  TS.build(1,1,n);
  bfs(T);
  TT.build(1,1,n);
  cin>>q;
  while(q--){
    int id=read(),v=eid[id*2];
    TS.upd(1,1,n,dfn[v],dfn[v]+sz[v]-1);
    TT.upd(1,1,n,dfn[v],dfn[v]+sz[v]-1);
    int cs=TS.getc(1,1,n,dfn[S]),ct=TT.getc(1,1,n,dfn[T]);
//    printf("#%d %d\n",cs,ct);
    printf("%d\n",max(TS.val[1][cs],TT.val[1][ct]));
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
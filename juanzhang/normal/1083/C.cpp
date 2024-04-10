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
const int maxn=2e5+10;
int n,q,A[maxn],mp[maxn];
vi E[maxn];
int now,fa[maxn],dep[maxn],in[maxn],out[maxn],eul[maxn<<1];
void dfs(int u,int f){
  eul[++now]=u,in[u]=out[u]=now,dep[u]=dep[f]+1;
  for(int v:E[u])if(v!=f){
    dfs(v,u);
    eul[++now]=u,out[u]=now;
  }
}
int lg[maxn<<1],st[19][maxn<<1];
void build(){
  rep(i,2,now)lg[i]=lg[i>>1]+1;
  rep(i,1,now)st[0][i]=eul[i];
  rep(i,1,18)rep(j,1,now-(1<<i)+1){
    int x=st[i-1][j],y=st[i-1][j+(1<<(i-1))];
    st[i][j]=dep[x]<dep[y]?x:y;
  }
}
int query(int l,int r){
  int k=lg[r-l+1];
  int x=st[k][l],y=st[k][r-(1<<k)+1];
  return dep[x]<dep[y]?x:y;
}
int get_lca(int u,int v){
  if(in[u]>in[v])swap(u,v);
  return query(in[u],out[v]);
}
int get_dis(int u,int v){
  return dep[u]+dep[v]-2*dep[get_lca(u,v)];
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

struct Path{
  int u,v,val;
  Path():u(-1),v(-1),val(-1){}
  Path(int _u,int _v,int _val):u(_u),v(_v),val(_val){}

  void print(){printf("(%d %d %d)",u,v,val);}
}val[maxn<<2];

Path unite(Path P,Path Q){
  if(P.u==-1||Q.u==-1)return Path();
//  P.print(),putchar(' '),Q.print();puts("");
  int d=-1,u=-1,v=-1,tmp;
  tmp=get_dis(P.u,P.v);if(d<tmp)d=tmp,u=P.u,v=P.v;
  tmp=get_dis(Q.u,Q.v);if(d<tmp)d=tmp,u=Q.u,v=Q.v;
  tmp=get_dis(P.u,Q.u);if(d<tmp)d=tmp,u=P.u,v=Q.u;
  tmp=get_dis(P.u,Q.v);if(d<tmp)d=tmp,u=P.u,v=Q.v;
  tmp=get_dis(P.v,Q.u);if(d<tmp)d=tmp,u=P.v,v=Q.u;
  tmp=get_dis(P.v,Q.v);if(d<tmp)d=tmp,u=P.v,v=Q.v;
//  printf("!(%d %d)\n",u,v);
  if(P.u!=u)swap(P.u,P.v);
  if(Q.u!=v)swap(Q.u,Q.v);
  int anc=get_lca(u,v);
  if(get_lca(P.v,anc)!=anc)return Path();
  if(get_lca(Q.v,anc)!=anc)return Path();
  if(get_lca(P.u,anc)!=anc)return Path();
  if(get_lca(Q.u,anc)!=anc)return Path();
  if(get_lca(u,P.v)!=P.v&&get_lca(v,P.v)!=P.v)return Path();
  if(get_lca(u,Q.v)!=Q.v&&get_lca(v,Q.v)!=Q.v)return Path();
  if(get_lca(u,P.u)!=P.u&&get_lca(v,P.u)!=P.u)return Path();
  if(get_lca(u,Q.u)!=Q.u&&get_lca(v,Q.u)!=Q.u)return Path();
  return {u,v,max(P.val,Q.val)};
}

void build(int k,int l,int r){
  if(l==r)return val[k]={mp[l],mp[l],l},void();
  build(lson),build(rson),val[k]=unite(val[k<<1],val[k<<1|1]);
//  printf("(%d %d) %d %d %d\n",l,r,val[k].u,val[k].v,val[k].val);
}

void upd(int k,int l,int r,int x,int u){
  if(l==r)return val[k]={u,u,l},void();
  x<=mid?upd(lson,x,u):upd(rson,x,u),val[k]=unite(val[k<<1],val[k<<1|1]);
}

Path ans;

void query(int k,int l,int r){
  Path tmp=unite(ans,val[k]);
  if(tmp.u!=-1)return ans=tmp,void();
  if(l==r)return;
  tmp=unite(ans,val[k<<1]);
  if(tmp.u==-1)query(lson);
  else ans=tmp,query(rson);
}

#undef mid
#undef lson
#undef rson

void solve() {
  cin>>n;
  rep(i,1,n){
    A[i]=read(),mp[A[i]]=i;
  }
  rep(i,2,n){
    fa[i]=read(),E[fa[i]].push_back(i);
  }
  dfs(1,0),build(),build(1,0,n-1);
  cin>>q;
  while(q--){
    int op=read();
    if(op==1){
      int x=read(),y=read();
      upd(1,0,n-1,A[x],y),upd(1,0,n-1,A[y],x),swap(A[x],A[y]),swap(mp[A[x]],mp[A[y]]);
    }else{
      ans={mp[0],mp[0],0},query(1,0,n-1);
      printf("%d\n",ans.val+1);
    }
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
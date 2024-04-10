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
const int maxn=1e5+10,P=1e9+7;
int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int Dec(int x,int y){return x<y?x-y+P:x-y;}
void Add(int &x,int y){x+=y;if(x>=P)x-=P;}
void Sub(int &x,int y){x-=y;if(x<0)x+=P;}
int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}
int n,q;

int ecnt=1,h[maxn];
struct edges{
  int nxt,to,w;
}E[maxn<<1];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}

int sum1[maxn],sum2[maxn];
int fa[maxn],sz[maxn],dep[maxn],son[maxn],top[maxn],dis[maxn],dfn[maxn];
void dfs1(int u,int f){
  fa[u]=f,sz[u]=1,dep[u]=dep[f]+1;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f){
      dis[v]=Inc(dis[u],E[i].w),dfs1(v,u);if(sz[son[u]]<sz[v])son[u]=v;
      sz[u]+=sz[v],Add(sum1[u],(sum1[v]+1ll*sz[v]*E[i].w)%P),Add(sum2[u],(sum2[v]+2ll*sum1[v]*E[i].w%P+1ll*E[i].w*E[i].w%P*sz[v]%P)%P);
    }
  }
}
int dp1[maxn],dp2[maxn];
void dfs2(int u,int tp){
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=fa[u]){
      dp1[v]=(dp1[u]+1ll*E[i].w*(n-sz[v]*2+P)%P)%P;
      dp2[v]=(dp2[u]-(1ll*E[i].w*E[i].w%P*sz[v]%P+2ll*E[i].w*sum1[v]%P)%P+1ll*E[i].w*E[i].w%P*(n-sz[v])%P+2ll*E[i].w%P*(dp1[u]-sum1[v]-1ll*E[i].w*sz[v]%P+P+P)%P)%P;
    }
  }
  static int now;
  dfn[u]=++now,top[u]=tp;
  if(son[u])dfs2(son[u],tp);
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=fa[u]&&v!=son[u])dfs2(v,v);
  }
}
int qlca(int u,int v){
  for(;top[u]!=top[v];u=fa[top[u]]){
    if(dep[top[u]]<dep[top[v]])swap(u,v);
  }
  return dep[u]<dep[v]?u:v;
}
struct ZZH{
  int c[maxn];
  void ins(int u,int x){
//    rep(i,dfn[u],dfn[u]+sz[u]-1)Add(c[i],x);
    Add(c[dfn[u]],x),Sub(c[dfn[u]+sz[u]],x);
  }
  void build(){
    rep(i,2,n+1)Add(c[i],c[i-1]);
  }
  int query(int u,int v){
    return Dec(c[dfn[u]],c[dfn[v]]);
  }
}B1_sz,B2_sz,B1_s1,B2_s1,B1_y,B2_y,B_w;

void solve(){
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read(),w=read();addline(u,v,w),addline(v,u,w);
  }
  dfs1(1,0),dp1[1]=sum1[1],dp2[1]=sum2[1],dfs2(1,1);
  rep(i,2,n){
    B1_sz.ins(i,1ll*dis[fa[i]]*(sz[fa[i]]-sz[i])%P);
    B2_sz.ins(i,1ll*dis[fa[i]]*dis[fa[i]]%P*(sz[fa[i]]-sz[i])%P);
    int w=Dec(dis[i],dis[fa[i]]);
    B_w.ins(i,(1ll*w*w%P*sz[i]%P+2ll*w*sum1[i]%P)%P);
    int tp=(sum1[fa[i]]-sum1[i]-1ll*w*sz[i]%P+P+P)%P;
    B1_y.ins(i,tp);
    B2_y.ins(i,1ll*dis[fa[i]]*tp%P);
  }
  rep(i,1,n){
    B1_s1.ins(i,sum1[i]);
    B2_s1.ins(i,1ll*dis[i]*sum1[i]%P);
  }
  B1_sz.build(),B2_sz.build(),B_w.build();
  B1_s1.build(),B2_s1.build(),B1_y.build(),B2_y.build();
  cin>>q;
  while(q--){
    int u=read(),v=read(),res=0;
    if(dfn[u]<dfn[v]||dfn[u]>=dfn[v]+sz[v]){
      int l=(dis[u]+dis[v]-2ll*dis[qlca(u,v)]%P+P)%P;
      res=(1ll*l*l%P*sz[v]%P+2ll*l*sum1[v]%P+sum2[v])%P;
    }else{
//      static int path[maxn];int len=0;
//      for(int x=u;;x=fa[x]){
//        path[++len]=x;if(x==v)break;
//      }
//      res=sum2[v];
      res=(sum2[v]+1ll*dis[u]*dis[u]%P*(sz[v]-sz[u])%P)%P;
      res=(res+B2_sz.query(u,v)-2ll*dis[u]*B1_sz.query(u,v)%P+P)%P;
      res=(res-B_w.query(u,v)+P)%P;
//      res=(res+2ll*dis[u]*B1_s1.query(fa[u],fa[v])%P-2ll*B2_s1.query(fa[u],fa[v])%P+P)%P;
      res=(res+2ll*(1ll*dis[u]*B1_y.query(u,v)%P-B2_y.query(u,v)+P)%P+P)%P;
//      res=(res+2ll*dis[u]*B1_y.query(u,v)%P)%P;
//      res=(res-2ll*B2_y.query(u,v)%P+P)%P;
//      rep(i,2,len){
//        int x=path[i],y=path[i-1],l=Dec(dis[u],dis[x]),w=Dec(dis[y],dis[x]);
////        res=(res+2ll*l*(sum1[x]-sum1[y]-1ll*w*sz[y]%P+P+P)%P)%P;
//        res=(res-2ll*l*(sum1[y]+1ll*w*sz[y]%P)%P+P)%P;
//      }
//      rep(i,2,len){
//        int x=path[i],y=path[i-1];
//        int w=Dec(dis[y],dis[x]);
//        res=(res+1ll*(1ll*dis[x]*dis[x]%P-2ll*dis[u]*dis[x]%P+P)%P*(sz[x]-sz[y])%P)%P;
//        int l=Dec(dis[u],dis[x]);
//        res=(res+2ll*dis[u]*(sum1[x]-sum1[y]-1ll*w*sz[y]%P+P)%P)%P;
//        res=(res-2ll*dis[x]*(sum1[x]-sum1[y]-1ll*w*sz[y]%P+P)%P+P)%P;
//      }
    }
    res=(res*2ll-dp2[u]+P)%P;
    printf("%d\n",res);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
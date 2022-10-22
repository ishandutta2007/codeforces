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
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}
inline ll readll(){
  #define nc getchar()
  ll x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}
const int maxn=3e5+10;
int n,dep[maxn];

int ecnt=1,h[maxn];
struct edges{
  int nxt,to;ll w[2];
}E[maxn<<1];
void addline(int u,int v,ll w1,ll w2){
  E[++ecnt]={h[u],v,{w1,w2}},h[u]=ecnt;
}

int fa[19][maxn];ll uw[maxn],ew[maxn][2],dis[19][maxn][2][2],F[maxn],G[maxn];

void dfs1(int u,int f){
  dep[u]=dep[f]+1,F[u]=uw[u];
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f){
      ew[v][0]=E[i].w[0],ew[v][1]=E[i].w[1],dfs1(v,u),chkmin(F[u],F[v]+ew[v][0]+ew[v][1]);
    }
  }
}
void dfs3(int u,int f){
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f){
      chkmin(G[v],G[u]+ew[v][0]+ew[v][1]),dfs3(v,u);
    }
  }
}
void dfs2(int u,int f){
  rep(i,0,18){
    fa[i][u]=i?fa[i-1][fa[i-1][u]]:f;
    if(!fa[i][u])break;
    auto val=dis[i][u];
    if(i){
      int anc=fa[i-1][u];
      rep(p,0,1)rep(q,0,1){
        val[p][q]=1e18;
        rep(k,0,1)chkmin(val[p][q],dis[i-1][u][p][k]+dis[i-1][anc][k][q]);
      }
    }else{
      val[0][0]=min(ew[u][0],uw[u]+uw[f]+ew[u][1]);
      val[1][1]=min(ew[u][1],uw[u]+uw[f]+ew[u][0]);
      val[0][1]=min(uw[u]+ew[u][1],ew[u][0]+uw[f]);
      val[1][0]=min(uw[u]+ew[u][0],ew[u][1]+uw[f]);
    }
  }
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f)dfs2(v,u);
  }
}
int qlca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
  per(i,18,0)if(dep[fa[i][u]]>=dep[v])u=fa[i][u];
  if(u==v)return u;
  per(i,18,0)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
  return fa[0][u];
}
ll dp[2][2];
void jump(int u,int chk,int anc){
//  bool F=1;
  dp[0][0]=chk?uw[u]:0,dp[1][1]=chk?0:uw[u],dp[0][1]=dp[1][0]=uw[u];
  per(i,18,0)if(dep[fa[i][u]]>=dep[anc]){
    ll val[2][2];
    rep(p,0,1)rep(q,0,1){
      val[p][q]=1e18;
//      if(F)printf("####Trans (%d %d) : (%d %d) %lld\n",i,u,p,q,dis[i][u][p][q]);
      rep(k,0,1)chkmin(val[p][q],dp[p][k]+dis[i][u][k][q]);
    }
    memcpy(dp,val,sizeof dp);
    u=fa[i][u];
  }
}

void solve(){
  cin>>n;
  rep(i,1,n)uw[i]=readll();
  rep(i,2,n){
    int u=read(),v=read();ll w1=readll(),w2=readll();addline(u,v,w1,w2),addline(v,u,w1,w2);
  }
  dfs1(1,0);rep(i,1,n)chkmin(uw[i],F[i]),G[i]=F[i];
  dfs3(1,0);rep(i,1,n)chkmin(uw[i],G[i]);
  dfs2(1,0);
  int tpq;cin>>tpq;
  while(tpq--){
    int X=read(),Y=read();
    int u=(X+1)/2,v=(Y+1)/2,chk_u=~X&1,chk_v=~Y&1,anc=qlca(u,v);ll dp_u[2][2],dp_v[2][2];
    jump(u,chk_u,anc),memcpy(dp_u,dp,sizeof dp);
    jump(v,chk_v,anc),memcpy(dp_v,dp,sizeof dp);
    rep(p,0,1)rep(q,0,1){
//      printf("(%d %d) (u : %lld) (v : %lld)\n",p,q,dp_u[p][q],dp_v[p][q]);
      dp[p][q]=1e18;
      rep(k,0,1)chkmin(dp[p][q],dp_u[p][k]+dp_v[q][k]);
    }
    printf("%lld\n",dp[chk_u][chk_v]);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
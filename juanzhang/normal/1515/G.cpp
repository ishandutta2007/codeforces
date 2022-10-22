#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

#define int long long

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=4e5+10;
int n,m;vi G[maxn],Gw[maxn];

int scc,dfn[maxn],low[maxn],st[maxn],top,now,bl[maxn];bool inq[maxn];
void tarjan(int u){
  dfn[u]=low[u]=++now,st[++top]=u,inq[u]=1;
  for(int v:G[u]){
    if(!dfn[v]){
      tarjan(v),chkmin(low[u],low[v]);
    }else if(inq[v])chkmin(low[u],dfn[v]);
  }
  if(dfn[u]==low[u]){
    scc++;
    while(1){
      int v=st[top--];
      inq[v]=0,bl[v]=scc;
      if(v==u)break;
    }
  }
}

int ecnt,h[maxn];vi nod[maxn];
struct edges{
  int nxt,to,w;
}E[maxn];bool ont[maxn],vis[maxn];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}
ll dis[maxn],val[maxn];
void dfs$(int u,int tp){
//  printf("(%d) : %d (%d)\n",u,tp,dis[u]);
  vis[u]=1;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(!vis[v])dis[v]=dis[u]+E[i].w,dfs$(v,tp);
    else{
      int t=dis[u]-dis[v]+E[i].w;
//      printf("(%d %d) (%d %d) %d\n",u,v,dis[u],dis[v],E[i].w);
      val[tp]=__gcd(val[tp],t);
    }
  }
}

void solve(){
  cin>>n>>m;
  rep(i,1,m){
    int u=read(),v=read(),w=read();G[u].push_back(v),Gw[u].push_back(w);
  }
  rep(i,1,n)if(!dfn[i])tarjan(i);
  rep(i,1,n)nod[bl[i]].push_back(i);
  rep(u,1,n)rep(_,0,G[u].size()-1){
    int v=G[u][_],w=Gw[u][_];
    if(bl[u]==bl[v]){
      addline(u,v,w),addline(v,u,-w);
    }
  }
  rep(i,1,n)if(!vis[i])dfs$(i,bl[i]);
//  rep(i,1,scc)printf("#%d\n",val[i]);
  int q;cin>>q;
  while(q--){
    int u=read(),x=read(),P=read();
    if(!x){
      puts("YES");
      continue;
    }
    x=(P-x)%P;
    int k=val[bl[u]];
    k=(k%P+P)%P;
    int g=__gcd(k,P);
    puts(x%g==0?"YES":"NO");
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
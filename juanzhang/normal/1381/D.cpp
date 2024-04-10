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
const int maxn=1e5+10;
int n,rt,S,T,len;
vi E[maxn];

void DFS(int u,int f,int d){
  if(u==T)return len=d,void();
  for(int v:E[u])if(v!=f)DFS(v,u,d+1);
}

int md1[maxn],md2[maxn],md3[maxn],po1[maxn],po2[maxn],po3[maxn];

void check(int u,int t,int v){
  if(md1[u]<t)md3[u]=md2[u],md2[u]=md1[u],md1[u]=t,po1[u]=v;
  else if(md2[u]<t)md3[u]=md2[u],md2[u]=t,po2[u]=v;
  else if(md3[u]<t)md3[u]=t,po3[u]=v;
}

void dfs1(int u,int f){
  md1[u]=1,po1[u]=u;
  for(int v:E[u])if(v!=f){
    dfs1(v,u),check(u,md1[v]+1,v);
  }
}

void dfs2(int u,int f){
  for(int v:E[u])if(v!=f){
    if(po1[u]!=v){
      check(v,md1[u]+1,u);
    }else{
      check(v,md2[u]+1,u);
    }
    dfs2(v,u);
  }
}

int dep[maxn],fa[maxn][17],mx[maxn];

void dfs(int u,int f){
  fa[u][0]=f,mx[u]=u,dep[u]=dep[f]+1;
  rep(i,1,16)fa[u][i]=fa[fa[u][i-1]][i-1];
  for(int v:E[u])if(v!=f){
    dfs(v,u);
    if(dep[mx[u]]<dep[mx[v]])mx[u]=mx[v];
  }
}

int lca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
  per(i,16,0)if(dep[u]-(1<<i)>=dep[v]){
    u=fa[u][i];
  }
  if(u==v)return u;
  per(i,16,0)if(fa[u][i]!=fa[v][i]){
    u=fa[u][i],v=fa[v][i];
  }
  return fa[u][0];
}

int find(int u,int k){
  per(i,16,0)if(k>>i&1)u=fa[u][i];
  return u;
}

void solve() {
  cin>>n>>S>>T;rep(i,1,n)E[i].clear(),md1[i]=md2[i]=md3[i]=po1[i]=po2[i]=po3[i]=mx[i]=0;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  DFS(S,0,1),dfs1(1,0),dfs2(1,0),rt=0;
//  rep(i,1,n)printf("(%d %d %d)\n",md1[i],md2[i],md3[i]);
  rep(i,1,n)if(md3[i]>=len){
    rt=i;break;
  }
//  printf("#%d\n",rt);
  if(!rt)return puts("NO"),void();
  rep(i,1,n)rep(j,0,16)fa[i][j]=0;
  dfs(rt,0);
  bool flg=0;
  rep(zzh,1,n){
    int anc=lca(S,T);
    if(S==anc||T==anc){
      flg=1;break;
    }
    if(S!=mx[S]){
      int d=dep[mx[S]]-dep[S];
      S=mx[S],T=find(T,d);if(!T)T=rt;
    }else{
      int d=dep[mx[T]]-dep[T];
      T=mx[T],S=find(S,d);if(!S)S=rt;
    }
  }
  puts(flg?"YES":"NO");
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}
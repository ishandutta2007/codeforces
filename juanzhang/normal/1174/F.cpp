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

inline int abso(int x) {
  return x < 0 ? -x : x;
}

inline int rnd() {
  int x = Rnd();
  while (abso(x) < 0) x = Rnd();
  return abso(x);
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=2e5+10;
int n;

vector<int>E[maxn];

int lsj,fa[maxn],sz[maxn],dep[maxn],son[maxn],mxd[maxn];

void dfs1(int u,int f){
  fa[u]=f,sz[u]=1,mxd[u]=dep[u];
  for(int v:E[u])if(v!=f){
    dep[v]=dep[u]+1,dfs1(v,u),sz[u]+=sz[v],chkmax(mxd[u],mxd[v]);
    if(sz[son[u]]<sz[v])son[u]=v;
  }
}

vi vec;
void DFS(int u,int f){
  for(int v:E[u])if(v!=f)DFS(v,u);vec.push_back(u);
}

void solve() {
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  dfs1(1,0);
  puts("d 1"),fflush(stdout);
  cin>>lsj;
  if(lsj==0)return puts("! 1"),fflush(stdout),void();
  int u=1;
  while(1){
    if(dep[u]==lsj)return printf("! %d\n",u),fflush(stdout),void();
    vec.clear(),DFS(son[u],u);int v=vec[rnd()%((int)vec.size())];
    printf("d %d\n",v),fflush(stdout);int ddd;cin>>ddd;
    if(!ddd)return printf("! %d\n",v),fflush(stdout),void();
    ddd=(lsj+dep[v]-ddd)/2;
    while(dep[v]>ddd)v=fa[v];
    if(ddd==dep[u]){
      printf("s %d\n",u),fflush(stdout);cin>>v;
    }
    u=v;
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
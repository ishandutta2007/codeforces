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
const int maxn=2010;
int n,D[maxn][maxn];
struct lsj{
  int u,v,w;
}dat[maxn*maxn];int tot;

int par[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

int h[maxn];ll dis[maxn][maxn];
struct edges{
  int nxt,to,w;
}E[maxn<<1];
void addline(int u,int v,int w){
  static int ecnt=1;
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}
void dfs(int u,int f,ll *dis){
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(v!=f)dis[v]=dis[u]+E[i].w,dfs(v,u,dis);
  }
}

void solve() {
  cin>>n;
  rep(i,1,n)rep(j,1,n){
    D[i][j]=read(),dat[++tot]={i,j,D[i][j]};
  }
  sort(dat+1,dat+tot+1,[](lsj P,lsj Q){
    return P.w<Q.w;
  });
  rep(i,1,n){
    par[i]=i;
    if(D[i][i])return puts("NO"),void();
    rep(j,i+1,n)if(D[i][j]!=D[j][i])return puts("NO"),void();
  }
  rep(i,1,tot){
    int u=dat[i].u,v=dat[i].v;
    if(find(u)!=find(v)){
      if(!dat[i].w)return puts("NO"),void();
//      printf("(%d %d)\n",u,v);
      par[find(u)]=find(v),addline(u,v,dat[i].w),addline(v,u,dat[i].w);
    }
  }
  rep(i,1,n)dfs(i,0,dis[i]);
//  rep(i,1,n)rep(j,1,n)printf("%d%c",dis[i][j],"\n "[j<n]);puts("");
  rep(i,1,n)rep(j,1,n)if(dis[i][j]!=D[i][j])return puts("NO"),void();
  puts("YES");
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
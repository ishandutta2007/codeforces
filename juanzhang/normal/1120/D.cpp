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
int n,A[maxn];
vi G[maxn];

int tot,L[maxn],R[maxn];

void dfs(int u,int f){
  L[u]=tot;
  for(int v:G[u])if(v!=f)dfs(v,u);
  R[u]=(tot+=u>1&&(int)G[u].size()==1);
}

int par[maxn];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}
struct edge{
  int u,v,w,tid;
}E[maxn];

void solve() {
  cin>>n;
  rep(i,1,n)A[i]=read(),par[i]=i;
  rep(i,2,n){
    int u=read(),v=read();G[u].push_back(v),G[v].push_back(u);
  }
  dfs(1,0);
  rep(i,1,n){
    E[i]={L[i],R[i],A[i],i};
  }
  sort(E+1,E+n+1,[](edge P,edge Q){
    return P.w<Q.w;
  });
  ll ans=0;
  vi vec;
  rep(i,1,n){
    int j=i;
    while(j<n&&E[j+1].w==E[i].w)j++;
    rep(k,i,j){
      int u=E[k].u,v=E[k].v;
      if(find(u)!=find(v))vec.push_back(E[k].tid);
    }
    rep(k,i,j){
      int u=E[k].u,v=E[k].v;
      if(find(u)!=find(v)){
        par[find(u)]=find(v),ans+=E[k].w;
      }
    }
    i=j;
  }
  cout<<ans<<' '<<(int)vec.size()<<endl;
  sort(vec.begin(),vec.end());for(int x:vec)printf("%d ",x);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
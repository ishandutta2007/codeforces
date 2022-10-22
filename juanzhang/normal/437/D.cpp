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
int n,m,A[maxn],par[maxn],sz[maxn],vis[maxn];pii dat[maxn];
vector<int>E[maxn];
int find(int x){return par[x]==x?x:par[x]=find(par[x]);}

void solve() {
  cin>>n>>m;rep(i,1,n)A[i]=read(),par[i]=i,dat[i]={A[i],i},sz[i]=1;
  rep(i,1,m){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  sort(dat+1,dat+n+1),reverse(dat+1,dat+n+1);
  ll su=0;
  rep(T,1,n){
    int u=dat[T].second;vis[u]=1;
    for(int v:E[u])if(vis[v]){
      int x=find(u),y=find(v);
      if(x==y)continue;
      su+=1ll*A[u]*sz[x]*sz[y],par[y]=x,sz[x]+=sz[y];
    }
  }
  db ans=(db)su/(1ll*n*(n-1)/2);
  printf("%.10lf\n",ans);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
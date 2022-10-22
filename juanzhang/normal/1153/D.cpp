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
const int maxn=3e5+10;
int n,k,A[maxn],fa[maxn],dp[maxn];
vi E[maxn];

void dfs(int u,int f){
  if(E[u].empty()){
    k++,dp[u]=1;return;
  }
  if(A[u])dp[u]=1e9;
  for(int v:E[u]){
    dfs(v,u);
    if(A[u]){
      chkmin(dp[u],dp[v]);
    }else{
      dp[u]+=dp[v];
    }
  }
}

void solve() {
  cin>>n;
  rep(i,1,n)A[i]=read();
  rep(i,2,n)fa[i]=read(),E[fa[i]].push_back(i);
  dfs(1,0);
  printf("%d\n",k-dp[1]+1);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 3e5 + 10;
int n, dp[N], sz[N];
vector<int> G[N];
void dfs(int u, int fa = 0) {
  sz[u] = 1;
  int son1 = -1, son2 = -1;
  for(int v : G[u]) {
    if(v != fa) {
      dfs(v, u);
      if(son1 == -1) son1 = v;
      else if(son2 == -1) son2 = v;
      sz[u] += sz[v];
    }
  }
  if(son1 == -1) dp[u] = 0;
  else if(son2 == -1) dp[u] = sz[son1] - 1;
  else dp[u] = max(dp[son1] + sz[son2] - 1, dp[son2] + sz[son1] - 1);
}
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    int u, v;
    rep(i, 1, n) G[i].clear();
    rep(i, 1, n - 1) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
    }
    dfs(1);
    printf("%d\n", dp[1]);
  }
  return 0;
}
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 4e5 + 10;

int n, f[N], sz[N], dp[N], g[N], pre[N], suf[N];
vector<int> G[N];
void dfs(int u, int fa = 0) {
   sz[u] = 1; dp[u] = 0; f[u] = fa;
   for(int v : G[u]) if(v != fa) {
      dfs(v, u); sz[u] += sz[v];
      pre[v] = dp[u];
      dp[u] = max(dp[u], sz[v] <= n / 2 ? sz[v] : dp[v]);
   }
   int t = 0;
   per(i, (int) G[u].size() - 1, 0) {
      int v = G[u][i];
      if(v == fa) continue ;
      suf[v] = t;
      t = max(t, sz[v] <= n / 2 ? sz[v] : dp[v]);
   }
}
void dfs2(int u, int fa = 0) {
   if(!fa) {
      g[u] = 0;
   } else {
      g[u] = n - sz[u] <= n / 2 ? n - sz[u] : max(g[fa], max(pre[u], suf[u]));
   }
   for(int v : G[u]) if(v != fa) {
      dfs2(v, u);
   }
}
int main() {
   scanf("%d", &n);
   int u, v;
   rep(i, 1, n - 1) {
      scanf("%d%d", &u, &v);
      G[v].pb(u); G[u].pb(v);
   }
   dfs(1); dfs2(1);
   rep(i, 1, n) {
      bool ans = 1;
      for(int v : G[i]) {
         if(f[i] == v) {
            if(n - sz[i] > n / 2) {
               ans = n - sz[i] - g[i] <= n / 2;
            }
         } else {
            if(sz[v] > n / 2) {
               ans = sz[v] - dp[v] <= n / 2;
            }
         }
      }
      printf("%d ", ans ? 1 : 0);
   }
   putchar('\n');
   return 0;
}
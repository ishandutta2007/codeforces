#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 105;
const int mod = 1e9 + 7;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline void upd(int &x, const int &y) { (x += y) >= mod ? x -= mod : 0; }

int n, sz[N], pw[N], dp[N][N][2], f[N], g[N], c[N][N];
vector<int> G[N];
void dfs(int u, int fa = 0) {
   sz[u] = 1;
   dp[u][0][1] = dp[u][0][0] = 1;

   for(int v : G[u]) if(v ^ fa) {
      dfs(v, u);
      static int tmp[N][2];
      rep(i, 0, sz[u] + sz[v] - 1) {
         tmp[i][0] = tmp[i][1] = 0;
      }
      rep(i, 0, sz[u] - 1) rep(j, 0, sz[v] - 1) {
         upd(tmp[i + j + 1][1], 1ll * dp[u][i][0] * dp[v][j][1] % mod);
         upd(tmp[i + j][0], 1ll * dp[u][i][0] * dp[v][j][1] % mod);
         upd(tmp[i + j + 1][1], 1ll * dp[u][i][1] * dp[v][j][0] % mod);
         upd(tmp[i + j + 1][0], 1ll * dp[u][i][0] * dp[v][j][0] % mod);
         upd(tmp[i + j][1], 1ll * dp[u][i][1] * dp[v][j][1] % mod);
      }
      sz[u] += sz[v];
      rep(i, 0, sz[u] - 1) {
         dp[u][i][0] = tmp[i][0];
         dp[u][i][1] = tmp[i][1];
      }
   }
}
int main() {
   scanf("%d", &n);
   int u, v;
   rep(i, 1, n - 1) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
   }
   rep(i, 0, n) {
      c[i][0] = c[i][i] = 1;
      rep(j, 1, i - 1) {
         c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
      }
   }
   dfs(1);
   pw[0] = 1;
   rep(i, 1, n - 1) pw[i] = 1ll * pw[i - 1] * n % mod;
   per(i, n - 1, 0) {
      g[i] = i == n - 1 ? 1 : 1ll * dp[1][i][1] * pw[n - i - 2] % mod;
      rep(j, i + 1, n - 1) {
         g[i] = dec(g[i], 1ll * g[j] * c[j][i] % mod);
      }
   }
   rep(i, 0, n - 1) printf("%d%c", g[i], " \n"[i == n - 1]);
   return 0;
}
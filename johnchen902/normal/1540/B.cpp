#include <stdio.h>
#include <algorithm>
#include <vector>

constexpr int mod = 1'000'000'007;

int modpow(int x, int n) {
  int ans = 1;
  for (; n; n >>= 1, x = (long long) x * x % mod)
    if (n & 1)
      ans = (long long) ans * x % mod;
  return ans;
}

int inv(int x) {
  return modpow(x, mod - 2);
}

int f[201][201];

std::vector<int> adj[200];
int mark[200];

int dfs1(int i, int j, int p) {
  if (i == j) {
    return mark[i] = 1;
  }

  for (int c : adj[i])
    if (c != p)
      if (int x = dfs1(c, j, i); x)
        return mark[i] = x + 1;

  return 0;
}

int dfs2(int i, int p) {
  int cnt = 1;
  for (int c : adj[i])
    if (c != p && !mark[c])
      cnt += dfs2(c, i);
  return cnt;
}

int solve(int u, int v, int n) {
  std::fill_n(mark, n, 0);
  dfs1(u, v, -1);

  //       u < v
  //       u --> v
  // mark: d --> 1

  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (mark[i]) {
      ans += (long long) dfs2(i, -1) * f[mark[i] - 1][mark[u] - mark[i]] % mod;
    }

  return ans % mod * inv((long long) n * modpow(2, mark[u] - 1) % mod) % mod;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0)
        f[i][j] = modpow(2, j);
      else if (j == 0)
        f[i][j] = 0;
      else
        f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;

  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans += solve(i, j, n);
  printf("%lld\n", ans % mod);
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, bsz, ans, a[maxn], val[maxn], dp[2][maxn];

vector <int> e[maxn];

int tot, prime[maxn];
bitset <maxn> bit[90];

void sieve() {
  int N = 2e5;
  bsz = sqrt(N);
  for (int i = 2; i <= N; i++) {
    if (prime[i]) continue;
    prime[++tot] = i;
    if (i <= bsz) bit[tot][i] = 1;
    for (int j = i << 1; j <= N; j += i) {
      prime[j] = 1;
      if (i <= bsz) bit[tot][j] = 1;
    }
  }
}

void dfs1(int u, int f) {
  int pos = 0;
  dp[0][u] = val[u];
  for (int v : e[u]) {
    if (v == f) continue;
    dfs1(v, u);
    if (val[u] && dp[0][u] < dp[0][v] + 1) {
      dp[0][u] = dp[0][v] + 1, pos = v;
    }
  }
  for (int v : e[u]) {
    if (v != f && v != pos && val[u]) {
      dp[1][u] = max(dp[1][u], dp[0][v]);
    }
  }
  dp[1][u] += dp[0][u];
}

void dfs2(int u, int f) {
  int pos = 0;
  dp[0][u] = val[u] > 1;
  for (int v : e[u]) {
    if (v == f) continue;
    dfs2(v, u);
    if (val[u] > 1 && val[u] == val[v] && dp[0][u] < dp[0][v] + 1) {
      dp[0][u] = dp[0][v] + 1, pos = v;
    }
  }
  for (int v : e[u]) {
    if (val[u] > 1 && v != f && v != pos && val[u] == val[v]) {
      dp[1][u] = max(dp[1][u], dp[0][v]);
    }
  }
  dp[1][u] += dp[0][u];
}

int main() {
  sieve();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[u].push_back(v), e[v].push_back(u);
  }
  for (int k = 1; k <= 86; k++) {
    for (int i = 1; i <= n; i++) {
      val[i] = bit[k][a[i]];
    }
    memset(dp, 0, sizeof dp);
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) {
      ans = max(ans, dp[1][i]);
    }
  }
  memcpy(val, a, sizeof a);
  for (int k = 1; k <= 86; k++) {
    for (int i = 1; i <= n; i++) {
      while (val[i] % prime[k] == 0) {
        val[i] /= prime[k];
      }
    }
  }
  memset(dp, 0, sizeof dp);
  dfs2(1, 0);
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[1][i]);
  }
  printf("%d", ans);
  return 0;
}
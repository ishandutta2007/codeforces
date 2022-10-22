#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e4 + 10;
ll ans;
int n, k, dp[maxn][505];

vector <int> e[maxn];

void dfs(int u, int f) {
  dp[u][0] = 1;
  for (int v : e[u]) {
    if (v == f) continue;
    dfs(v, u);
    for (int i = 1; i <= k; i++) {
      dp[u][i] += dp[v][i - 1];
    }
  }
  ll sum = 0;
  for (int v : e[u]) {
    if (v == f) continue;
    for (int i = 1; i < k; i++) {
      sum += 1ll * dp[v][i - 1] * (dp[u][k - i] - dp[v][k - i - 1]);
    }
  }
  ans += sum / 2 + dp[u][k];
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    e[u].push_back(v), e[v].push_back(u);
  }
  dfs(1, 0);
  printf("%I64d", ans);
  return 0;
}
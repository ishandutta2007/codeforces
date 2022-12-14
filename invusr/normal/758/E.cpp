#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

const s64 INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<pair<int, int>> edges(n - 1);
  vector<s64> weight(n), strength(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    s64 w, s;
    scanf("%d %d %lld %lld", &u, &v, &w, &s);
    edges[i] = make_pair(--u, --v);
    adj[u].push_back(v);
    weight[v] = w;
    strength[v] = s;
  }
  weight[0] = 1;
  strength[0] = INF;

  vector<s64> delta(n), sum(n);
  function<s64(int)> build = [&](int u) {
    sum[u] = 0;
    for (int v : adj[u]) {
      sum[u] += build(v);
      if (sum[u] >= INF) {
        return INF;
      }
    }
    if (sum[u] > strength[u]) {
      return INF;
    } else {
      delta[u] = min(weight[u] - 1, strength[u] - sum[u]);
      weight[u] -= delta[u];
      strength[u] -= delta[u];
      return sum[u] + weight[u];
    }
  };

  if (build(0) >= INF) {
    printf("-1\n");
    return 0;
  }

  function<s64(int, s64)> dfs = [&](int u, s64 remain) {
    s64 current = min(delta[u], remain);
    weight[u] += current;
    strength[u] += current;
    remain = min(remain - current, strength[u] - sum[u]);
    for (int v : adj[u]) {
      s64 next = dfs(v, remain);
      current += next;
      remain -= next;
    }
    return current;
  };

  dfs(0, INF);

  printf("%d\n", n);
  for (int i = 0; i < n - 1; ++i) {
    int u = edges[i].first, v = edges[i].second;
    printf("%d %d ", u + 1, v + 1);
    printf("%lld %lld\n", weight[v], strength[v]);
  }

  return 0;
}
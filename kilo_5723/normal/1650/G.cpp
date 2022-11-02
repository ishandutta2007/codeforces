#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 5;
struct edge {
  int u, v;
  edge() {}
  edge(int u, int v) : u(u), v(v) {}
};
vector<edge> ed;
vector<int> e[maxn];
int d1[maxn], d2[maxn];
int a[maxn];
ll dp1[maxn], dp2[maxn];
queue<int> que;
void solve(int s, int n, int d[], ll dp[]) {
  fill(d, d + n + 1, -1);
  d[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto v : e[u])
      if (!~d[v]) {
        d[v] = d[u] + 1;
        que.push(v);
      }
  }
  for (int i = 0; i < n; i++) a[i] = i + 1;
  sort(a, a + n, [d](int i, int j) { return d[i] < d[j]; });
  fill(dp, dp + n + 1, 0);
  dp[s] = 1;
  for (int i = 0; i < n; i++) {
    int u = a[i];
    for (auto v : e[u])
      if (d[v] == d[u] + 1) dp[v] = (dp[v] + dp[u]) % mod;
  }
  // for (int i = 1; i <= n; i++) printf("%d ", d[i]);
  // puts("");
  // for (int i = 1; i <= n; i++) printf("%lld ", dp[i]);
  // puts("");
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) e[i].clear();
    int s, t;
    scanf("%d%d", &s, &t);
    ed.clear();
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
      ed.push_back(edge(u, v));
    }
    solve(s, n, d1, dp1);
    solve(t, n, d2, dp2);
    ll ans = dp1[t];
    int dis = d1[t];
    for (auto e : ed) {
      if (d1[e.u] == d1[e.v] && d1[e.u] + d2[e.v] == dis)
        ans = (ans + dp1[e.u] * dp2[e.v]) % mod;
      if (d1[e.v] == d1[e.u] && d1[e.v] + d2[e.u] == dis)
        ans = (ans + dp1[e.v] * dp2[e.u]) % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
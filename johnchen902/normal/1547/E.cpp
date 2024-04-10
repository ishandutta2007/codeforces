#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

constexpr int inf = 1'000'000'000 + 300'000;

int d[300'000];
int a[300'000];

void solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  std::fill_n(d, n, inf);

  for (int i = 0; i < m; i++) {
    scanf("%d", a + i);
    a[i]--;
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    d[a[i]] = t;
    q.emplace(t, a[i]);
  }

  while (!q.empty()) {
    auto [c, u] = q.top();
    q.pop();
    if (d[u] != c)
      continue;
    for (int v : {u - 1, u + 1})
      if (v >= 0 && v < n && d[v] > c + 1) {
        d[v] = c + 1;
        q.emplace(c + 1, v);
      }
  }

  for (int i = 0; i < n; i++)
    printf("%d%c", d[i], i == n - 1 ? '\n' : ' ');
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
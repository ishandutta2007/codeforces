#include <cstdio>
#include <vector>

const int N = 1000000 + 10;

int n, f[N];

int m, g[N], h[N];

std::vector<int> pool[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);
  for (int i = 1; i <= n; ++i) pool[f[i]].push_back(i);
  for (int i = 1; i <= n; ++i) {
    if (f[i] != i) continue;
    ++m;
    for (int j = 0; j < pool[i].size(); ++j) g[pool[i][j]] = m;
    h[m] = i;
  }
  m = std::max(m, 1);
  for (int i = 1; i <= m; ++i) if (!h[i] || g[h[i]] != i) return puts("-1"), 0;
  for (int i = 1; i <= n; ++i) if (!g[i] || h[g[i]] != f[i]) return puts("-1"), 0;
  printf("%d\n", m);
  for (int i = 1; i <= n; ++i) printf("%d ", g[i]);
  puts("");
  for (int i = 1; i <= m; ++i) printf("%d ", h[i]);
  return 0;
}
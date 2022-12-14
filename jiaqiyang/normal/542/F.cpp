#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

const int LOG = 15, N = (1 << LOG) + 1;

int n, m, t[N], q[N], size[N], f[N], g[N];
std::vector<int> pool[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", t + i, q + i);
    pool[m - t[i]].push_back(q[i]);
  }
  for (int i = m; i > 0; --i) {
    std::sort(pool[i].begin(), pool[i].end(), std::greater<int>());
    if (pool[i].size() & 1) pool[i].push_back(0);
    for (int j = 0; j < pool[i].size(); j += 2) pool[i - 1].push_back(pool[i][j] + pool[i][j + 1]);
  }
  printf("%d\n", *std::max_element(pool[0].begin(), pool[0].end()));
  return 0;
}
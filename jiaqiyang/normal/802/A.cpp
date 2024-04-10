#include <cstdio>
#include <set>
#include <algorithm>

const int N = 80 + 10;

int n, k, a[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  std::set<int> pool;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    if (pool.count(x)) continue;
    ++ans;
    pool.insert(x);
    if (pool.size() > k) {
      std::pair<int, int> max(i, x);
      for (auto y : pool) max = std::max(max, {std::find(a + i, a + n + 1, y) - a, y});
      pool.erase(max.second);
    }
  }
  printf("%d\n", ans);
  return 0;
}
#include <cstdio>
#include <set>
#include <algorithm>

const int N = 400000 + 10;

int n, k, a[N], succ[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  static int last[N];
  for (int i = n; i > 0; --i) succ[i] = last[a[i]] ? last[a[i]] : (n + 1), last[a[i]] = i;
  static int cur[N];
  std::set<std::pair<int, int>> pool;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x = a[i];
    if (pool.count({i, x})) pool.erase({i, x}); else ++ans;
    if (pool.size() >= k) pool.erase(*pool.rbegin());
    pool.emplace(cur[x] = succ[i], x);
  }
  printf("%d\n", ans);
  return 0;
}
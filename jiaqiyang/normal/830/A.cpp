#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>

typedef long long i64;

const int N = 2000 + 10;

int n, m, a[N], b[N];

void init() {
  int p;
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] -= p;
  for (int i = 1; i <= m; ++i) scanf("%d", &b[i]), b[i] -= p;
  std::sort(a + 1, a + n + 1);
  std::sort(b + 1, b + m + 1);
}

bool solve(i64 t) {
  static std::pair<i64, i64> info[N];
  for (int i = 1; i <= n; ++i) {
    i64 x = (t - abs(a[i])) / 2;
    i64 l = std::min(a[i], 0) - x, r = std::max(a[i], 0) + x;
    info[i] = {r, l};
  }
  std::sort(info + 1, info + n + 1);
  std::set<i64> pool;
  for (int i = 1, j = 1; i <= n; ++i) {
    for (; j <= m && b[j] <= info[i].first; ++j) pool.insert(b[j]);
    auto it = pool.lower_bound(info[i].second);
    if (it == pool.end()) return false;
    pool.erase(it);
  }
  return true;
}

int main() {
  init();
  i64 l = 0, r = 1LL << 32;
  for (int i = 1; i <= n; ++i) l = std::max<i64>(l, abs(a[i]));
  while (l < r) {
    i64 mid = (l + r) >> 1;
    if (solve(mid)) r = mid; else l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}
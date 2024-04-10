#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 100 + 10;

int n, a[N];
i64 m;

std::vector<std::pair<int, int>> info;

int main() {
  scanf("%d%lld", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) m += a[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= a[i]; j = a[i] / (a[i] / j) + 1) {
      if (j > 1) info.emplace_back(j - 1, i);
      info.emplace_back(j, i);
    }
    info.emplace_back(a[i], i);
  }
  std::sort(info.begin(), info.end());
  info.erase(std::unique(info.begin(), info.end()), info.end());
  i64 ans = 0, sum = 0;
  static i64 cur[N];
  for (int i = 0; i < info.size();) {
    int d = info[i].first, j = i;
    for (; j <= info.size() && d == info[j].first; ++j) {
      int x = info[j].second;
      sum -= cur[x];
      sum += (cur[x] = (a[x] + d - 1) / d);
    }
    i64 t = m / sum;
    if (j < info.size()) t = std::min(t, info[j].first - 1LL);
    if (t >= d) ans = std::max(ans, t);
    i = j;
  }
  printf("%lld\n", ans);
  return 0;
}
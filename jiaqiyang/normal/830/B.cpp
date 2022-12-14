#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;

int bit[N];

int n, m, a[N];

void add(int p, int v) {
  for (; p <= n; p += p & -p) bit[p] += v;
}

int query(int p) {
  int res = 0;
  for (; p; p ^= p & -p) res += bit[p];
  return res;
}

inline int solve(int l, int r) { return l <= r ? (query(r) - query(l - 1)) : (query(n) - query(l - 1) + query(r)); }

int main() {
  scanf("%d", &n);
  static std::vector<int> pos[N];
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pos[a[i]].push_back(i);
  for (int i = 1; i <= n; ++i) add(i, 1);
  i64 ans = 0;
  for (int i = 1, j = 1; i < N; ++i) {
    if (pos[i].empty()) continue;
    auto it = std::lower_bound(pos[i].begin(), pos[i].end(), j);
    if (it != pos[i].end()) std::rotate(pos[i].begin(), it, pos[i].end());
    for (auto k : pos[i]) {
      ans += solve(j, k);
      add(j = k, -1);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
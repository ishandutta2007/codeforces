#include <cstdio>
#include <algorithm>

typedef std::pair<int, int> Info;

const int N = 200000 + 10;

int n;

Info info[N];

int bit[2 * N], sorted[2 * N], tot;

inline void update(int p, int v) {
  for (; p <= tot; p += p & -p) bit[p] = std::max(bit[p], v);
}

inline int query(int p) {
  int res = 0;
  for (; p; p ^= p & -p) res = std::max(res, bit[p]);
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &info[i].first, &info[i].second);
  std::sort(info + 1, info + n + 1);
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    sorted[++tot] = info[i].first - info[i].second;
    sorted[++tot] = info[i].first + info[i].second;
  }
  std::sort(sorted + 1, sorted + tot + 1);
  tot = std::unique(sorted + 1, sorted + tot + 1) - sorted - 1;
  static int f[N];
  for (int i = 1; i <= n; ++i) {
    int a = std::lower_bound(sorted + 1, sorted + tot + 1, info[i].first - info[i].second) - sorted;
    int b = std::lower_bound(sorted + 1, sorted + tot + 1, info[i].first + info[i].second) - sorted;
    update(b, f[i] = query(a) + 1);
  }
  printf("%d\n", *std::max_element(f + 1, f + n + 1));
  return 0;
}
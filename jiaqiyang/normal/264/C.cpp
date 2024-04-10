#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;
const i64 INF = 1LL << 60;

int n, q, v[N], c[N];
int a, b;

std::pair<i64, int> max, sub;

inline void check(i64 &lhs, i64 rhs) { if (rhs > lhs) lhs = rhs; }

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
  while (q--) {
    scanf("%d%d", &a, &b);
    static i64 f[N], g[N];
    std::fill(g, g + n + 1, -INF);
    max = sub = std::make_pair(0LL, 0);
    for (int i = 1; i <= n; ++i) {
      f[i] = (max.second == c[i] ? sub.first : max.first) + (i64)b * v[i];
      check(f[i], g[c[i]] + (i64)a * v[i]);
      check(g[c[i]], f[i]);
      if (c[i] == max.second) {
        check(max.first, f[i]);
      } else if (c[i] == sub.second) {
        check(sub.first, f[i]);
      } else if (f[i] > max.first) {
        sub = max;
        max = std::make_pair(f[i], c[i]);
      } else if (f[i] > sub.first) {
        sub = std::make_pair(f[i], c[i]);
      }
      if (sub > max) std::swap(max, sub);
    }
    printf("%lld\n", std::max(0LL, *std::max_element(f + 1, f + n + 1)));
  }
  return 0;
}
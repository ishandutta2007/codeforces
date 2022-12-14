#include <cctype>
#include <stdio.h>
#include <algorithm>

typedef long long i64;

const int N = 1000000 + 10;
const i64 INF = 1LL << 60;

int nextInt() {
  char ch;
  while (ch = getchar(), !isdigit(ch) && ch != '-') {}
  bool sig = (ch == '-');
  if (sig) ch = getchar();
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return sig ? -res : res;
}

int n, m, a[N], sorted[N];

struct BIT {
  i64 data[N];
  BIT() { std::fill(data, data + N, -INF); }
  inline void update(int p, i64 v) {
    for (; p <= m; p += p & -p) data[p] = std::max(data[p], v);
  }
  inline i64 query(int p) {
    i64 res = -INF;
    for (; p; p ^= p & -p) res = std::max(res, data[p]);
    return res;
  }
} bit[2];

i64 f[N];

int main() {
  n = nextInt();
  for (int i = 1; i <= n; ++i) sorted[i] = a[i] = nextInt();
  std::sort(sorted + 1, sorted + n + 1);
  m = std::unique(sorted + 1, sorted + n + 1) - sorted - 1;
  for (int i = 1; i <= n; ++i) a[i] = std::lower_bound(sorted + 1, sorted + m + 1, a[i]) - sorted;
  for (int i = 1; i <= n; ++i) {
    bit[0].update(a[i], f[i - 1] - sorted[a[i]]);
    bit[1].update(m - a[i] + 1, f[i - 1] + sorted[a[i]]);
    // a[j] <= a[i] : f[j - 1] + sorted[a[i]] - sorted[a[j]];
    f[i] = sorted[a[i]] + bit[0].query(a[i]);
    // a[j] >= a[i] : f[j - 1] + sorted[a[j]] - sorted[a[i]];
    f[i] = std::max(f[i], bit[1].query(m - a[i] + 1) - sorted[a[i]]);
  }
  printf("%lld\n", f[n]);
  return 0;
}
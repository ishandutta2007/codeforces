#include <cstdio>
#include <set>
#include <algorithm>

typedef long long i64;

const int N = 200000 + 10;

int n, d, m;

struct Info {
  int x, p;
  inline bool operator< (const Info &rhs) const { return x < rhs.x; }
} info[N];


int main() {
  scanf("%d%d%d", &d, &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &info[i].x, &info[i].p);
  std::sort(info + 1, info + m + 1);
  static int q[N];
  info[m + 1].x = d;
  int f = 1, r = 0;
  static int succ[N];
  for (int i = 0; i <= m + 1; ++i) {
    for (; f <= r && info[q[r]].p >= info[i].p; --r) succ[q[r]] = i;
    q[++r] = i;
  }
  f = 1, r = 0;
  i64 ans = 0;
  int rem = 0;
  for (int i = 0, j = 1; i <= m;) {
    for (; j <= m + 1 && info[i].x + n >= info[j].x; ++j) {
      while (f <= r && info[q[r]].p >= info[j].p) --r;
      q[++r] = j;
    }
    while (f <= r && info[q[f]].x <= info[i].x) ++f;
    if (info[i].x + n >= info[succ[i]].x) {
      int det = std::max(info[succ[i]].x - info[i].x - rem, 0);
      rem += det;
      ans += (i64)info[i].p * det;
      rem -= info[succ[i]].x - info[i].x;
      i = succ[i];
    } else {
      if (f > r) return puts("-1"), 0;
      int det = n - rem;
      rem += det;
      ans += (i64)info[i].p * det;
      rem -= info[q[f]].x - info[i].x;
      i = q[f];
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
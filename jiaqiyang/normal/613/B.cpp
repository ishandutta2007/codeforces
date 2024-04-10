#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;

inline bool check(i64 &lhs, i64 rhs) {
  return rhs > lhs ? (lhs = rhs, true) : false;
}

int n, b, p, q;
struct Info {
  int x, y;
  Info() {}
  Info(int _x, int _y): x(_x), y(_y) {}
  inline bool operator< (const Info &rhs) const {
    return x < rhs.x;
  }
} a[N];
i64 m, sum[N];

i64 get(i64 x, int lim) {
  int t = std::upper_bound(sum + 1, sum + n + 1, x) - sum - 1;
  if (t > lim) t = lim;
  x -= sum[t];
  return std::min<i64>(b, a[t].x + x / t);
}

int main() {
  scanf("%d%d%d%d%lld", &n, &b, &p, &q, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].x), a[i].y = i;
  static int cur[N];
  for (int i = 1; i <= n; ++i) cur[i] = a[i].x;
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i].x;
  for (int i = 1; i <= n; ++i) sum[i] = (i64)a[i].x * i - sum[i];
  i64 ans = -1;
  int t;
  i64 temp = m;
  for (int i = n; i > 0 && m >= 0; --i) {
    if (check(ans, q * get(m, i) + (i64)p * (n - i))) t = i;
    m -= b - a[i].x;
  }
  if (m >= 0 && check(ans, (i64)q * b + (i64)p * n)) {
    std::fill(cur + 1, cur + n + 1, b);
  } else {
    for (int i = n; i > t; --i) cur[a[i].y] = b, temp -= b - a[i].x;
    t = std::min<int>(std::upper_bound(sum + 1, sum + n + 1, temp) - sum - 1, t);
    temp -= sum[t];
    int val = std::min<i64>(b, a[t].x + temp / t);
    for (int i = 1; i <= t; ++i) cur[a[i].y] = val;
    //    temp -= temp / t * t;
    //    for (int i = 1; i <= temp; ++i) cur[a[i].y];
  }
  printf("%lld\n", ans);
  for (int i = 1; i <= n; ++i) printf("%d ", cur[i]);
  return 0;
}
#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 40 + 10;

int n, bx, m, by;
int a[N], b[N];

int main() {
  scanf("%d%d", &n, &bx);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  scanf("%d%d", &m, &by);
  for (int i = 0; i < m; ++i) scanf("%d", b + i);
  i64 p = 0, q = 0;
  std::reverse(a, a + n);
  std::reverse(b, b + m);
  i64 t = 1;
  for (int i = 0; i < n; ++i, t *= bx) p += a[i] * t;
  t = 1;
  for (int i = 0; i < m; ++i, t *= by) q += b[i] * t;
  if (p > q) puts(">"); else if (p == q) puts("="); else puts("<");
  return 0;
}
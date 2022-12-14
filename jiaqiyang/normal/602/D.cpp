#include <cstdio>
#include <cstdlib>

typedef long long i64;

const int N = 100000 + 10;

int n, q, a[N], b[N];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 2; i <= n; ++i) b[i] = abs(a[i] - a[i - 1]);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l == r) {
      puts("0");
      continue;
    }
    i64 ans = 0;
    ++l;
    static int stk[N], left[N], right[N];
    int top = 0;
    for (int i = l; i <= r; ++i) left[i] = l - 1, right[i] = r + 1;
    for (int i = l; i <= r; ++i) {
      while (top && b[stk[top]] <= b[i]) right[stk[top--]] = i;
      stk[++top] = i;
    }
    top = 0;
    for (int i = r; i >= l; --i) {
      while (top && b[stk[top]] < b[i]) left[stk[top--]] = i;
      stk[++top] = i;
    }
    for (int i = l; i <= r; ++i) ans += ((i64)i - left[i]) * (right[i] - i) * b[i];
    printf("%I64d\n", ans);
  }
  return 0;
}
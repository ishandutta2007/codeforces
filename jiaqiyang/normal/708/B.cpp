#include <cstdio>
#include <cstdlib>
#include <map>

typedef long long i64;

const int N = 1000000 + 10;

void fail() {
  puts("Impossible");
  exit(0);
}

std::map<i64, int> pool;

int a[2][2];

int main() {
  for (int i = 1; i <= 100000; ++i) pool[i * (i - 1LL) / 2] = i;
  scanf("%d%d%d%d", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
  if (!pool.count(a[0][0])) fail();
  if (!pool.count(a[1][1])) fail();
  i64 tot = (i64)a[0][0] + a[0][1] + a[1][0] + a[1][1];
  if (!pool.count(tot)) fail();
  int n = pool[a[0][0]], m = pool[a[1][1]];
  if ((n + m) * (n + m - 1LL) / 2 != tot) {
    if (a[0][0] && a[1][1]) fail();
    if (!a[0][0]) --n; else --m;
    if ((n + m) * (n + m - 1LL) / 2 != tot) fail();
  }
  static char ans[N];
  for (int i = 1, t = a[0][1], p = n, q = m; i <= n + m; ++i) {
    if (t >= q && p) {
      --p;
      t -= q;
      ans[i] = '0';
    } else {
      --q;
      ans[i] = '1';
    }
  }
  puts(ans + 1);
  return 0;
}
#include <stdio.h>
#include <cstdlib>
#include <set>

const int N = 100000 + 10;

int n, l, x, y, a[N];
std::set<int> pool;

int mask;

void check(int p) {
  if (p < 0 || p > l) return;
  int cur = mask;
  if (pool.count(p - x) || pool.count(p + x)) cur |= 1;
  if (pool.count(p - y) || pool.count(p + y)) cur |= 2;
  if (cur == 3) {
    printf("1\n%d\n", p);
    exit(0);
  }
}

int main() {
  scanf("%d%d%d%d", &n, &l, &x, &y);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), pool.insert(a[i]);
  mask = 0;
  for (int i = 1; i <= n; ++i) {
    if (pool.count(a[i] - x) || pool.count(a[i] + x)) mask |= 1;
    if (pool.count(a[i] - y) || pool.count(a[i] + y)) mask |= 2;
  }
  if (mask == 3) return puts("0"), 0;
  for (int i = 1; i <= n; ++i) {
    check(a[i] - x);
    check(a[i] + x);
    check(a[i] - y);
    check(a[i] + y);
  }
  printf("2\n%d %d\n", x, y);
  return 0;
}
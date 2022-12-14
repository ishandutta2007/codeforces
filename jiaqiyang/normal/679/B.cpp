#include <cmath>
#include <cassert>
#include <cstdio>
#include <algorithm>

typedef long long i64;

inline i64 cube(i64 x) { return x * x * x; }

int greedy(i64 m) {
  int x = 0;
  i64 y = 0;
  for (int i = 1; cube(i) <= m; ++i) while (y + cube(i) < std::min(cube(i + 1), m + 1)) ++x, y += cube(i);
  return x;
}

i64 dfs(int rem, i64 m) {
  if (rem > m) return -(1LL << 60);
  if (!rem) return 0;
  int x = pow(m, 1. / 3.) - .5;
  while (cube(x) <= m) ++x;
  --x;
  i64 res = dfs(rem - 1, m - cube(x)) + cube(x);
  if (x > 1) res = std::max(res, dfs(rem - 1, cube(x) - 1 - cube(x - 1)) + cube(x - 1));
  return res;
}

i64 m;

int main() {
  scanf("%I64d", &m);
  int ans = greedy(m);
  printf("%d %I64d\n", ans, dfs(ans, m));
  return 0;
}
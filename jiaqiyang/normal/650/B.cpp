#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 500000 + 10;

int n, a, b, t;
char photo[N];

i64 c[N], sum[N];

inline bool check(int i, int j) {
  return sum[i] + sum[n] - sum[j - 1] + (i64)a * (i - 1 + n - j + 1 + std::min(i - 1, n - j + 1)) <= t;
}

int main() {
  scanf("%d%d%d%d %s", &n, &a, &b, &t, photo + 1);
  for (int i = 1; i <= n; ++i) c[i] = 1 + (photo[i] == 'w' ? b : 0);
  for (int i = 1; i <= n + 1; ++i) sum[i] = sum[i - 1] + c[i];
  int j = 2;
  while (j <= n && !check(1, j)) ++j;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (j = std::max(j, i + 1); j <= i || (j <= n && !check(i, j));) ++j;
    if (check(i, j)) ans = std::max(ans, n - (j - i - 1));
  }
  printf("%d\n", ans);
  return 0;
}
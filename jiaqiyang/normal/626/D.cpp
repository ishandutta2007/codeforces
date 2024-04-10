#include <cmath>
#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 5000 + 10;

int n, a[N];
int cnt[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      ++cnt[a[j] - a[i]];
  static i64 sum[2 * N];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      sum[i + j] += cnt[i] * cnt[j];
  for (int i = 1; i < 2 * N; ++i) sum[i] += sum[i - 1];
  i64 ans = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      ans += sum[a[j] - a[i] - 1];
  printf("%.10f\n", ans / pow(n * (n - 1.) / 2., 3.));
  return 0;
}
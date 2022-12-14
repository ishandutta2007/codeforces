#include <cstdio>
#include <numeric>
#include <algorithm>

const int N = 1000000 + 100;

int n, a[N], cnt[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ++cnt[a[i]];
  for (int i = 0; i < N; ++i) cnt[i + 1] += (cnt[i] >> 1), cnt[i] &= 1;
  printf("%d\n", std::accumulate(cnt, cnt + N, 0));
  return 0;
}
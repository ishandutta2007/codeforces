#include <cstdio>
#include <algorithm>

const int N = 1000000 + 10;

int n, a[N];

int cnt[N], sum[N], last[N], ans;

void solve(int x) {
  for (int i = x; i < N;) {
    int j = std::min(i + x, N) - 1, k = last[j];
    if (k >= x) ans = std::max(ans, k % x);
    i = j + 1;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ++cnt[a[i]];
  for (int i = 1; i < N; ++i) if (cnt[i]) last[i] = i; else last[i] = last[i - 1];
  for (int i = 1; i < N; ++i) if (cnt[i]) solve(i);
  printf("%d\n", ans);
  return 0;
}
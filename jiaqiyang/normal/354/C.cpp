#include <stdio.h>
#include <algorithm>

const int N = 1000000 + 10;

int n, k, a[N];

int cnt[N], last[N];

bool check(int m) {
  for (int i = m; i < N; i += m) {
    int j = std::min(i + m, N) - 1;
    if (last[j] - i > k) return false;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ++cnt[a[i]];
  for (int i = 1; i < N; ++i) if (cnt[i]) last[i] = i; else last[i] = last[i - 1];
  for (int i = *std::min_element(a + 1, a + n + 1); i > 1; --i) if (check(i)) return printf("%d\n", i), 0;
  puts("1");
  return 0;
}
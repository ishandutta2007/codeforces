#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;

int n, m;
char s[N];

i64 count() {
  static int sum[N];
  sum[n] = 0;
  for (int i = n - 1; i > 0; --i) sum[i] = sum[i + 1] + (s[i] != s[i + 1]);
  i64 res = 0;
  for (int i = 1; i <= n; ++i) res += (m - 1LL) * sum[i];
  return res;
}

int main() {
  scanf("%d%d %s", &n, &m, s + 1);
  i64 ans = (m - 1LL) * n;
  ans += count();
  std::reverse(s + 1, s + n + 1);
  ans += count();
  std::reverse(s + 1, s + n + 1);
  static int right[N];
  for (int i = 1; i <= n; ++i) right[i] = i;
  for (int i = n - 2; i > 0; --i) if (s[i] == s[i + 2]) right[i] = right[i + 2];
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i + 1]) continue;
    int j = std::min(right[i], right[i + 1]) + 1;
    ans -= j - i;
  }
  printf("%I64d\n", ans);
  return 0;
}
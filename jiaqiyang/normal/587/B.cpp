#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

typedef long long i64;
typedef std::pair<int, int> Info;

const int N = 2000000 + 10, MOD = 1000000007;

int n, k, m, a[N], b[N];
i64 l, x, y;

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int main() {
  int t;
  std::cin >> n >> l >> t;
  for (int i = 0; i < n; ++i) a[i] = nextInt();
  memcpy(b, a, sizeof b);
  std::sort(b, b + n);
  m = std::unique(b, b + n) - b;
  for (int i = 0; i < n; ++i) a[i] = std::lower_bound(b, b + m, a[i]) - b;
  int ans = 0;
  static int f[N], cnt[N];
  for (int i = 0; i < n; ++i) ++cnt[a[i]];
  f[0] = 1;
  x = l / n, y = l % n;
  for (int k = 1; k <= t; ++k) {
    for (int i = 1; i < m; ++i) (f[i] += f[i - 1]) %= MOD;
    i64 cur = x - k + 2;
    if (cur > 0) {
      cur %= MOD;
      for (int i = 0; i < y; ++i) ans = (ans + cur * f[a[i]]) % MOD;
    }
    cur = x - k + 1;
    if (cur > 0) {
      cur %= MOD;
      for (int i = y; i < n; ++i) ans = (ans + cur * f[a[i]]) % MOD;
    }
    for (int i = 0; i < m; ++i) f[i] = (i64)f[i] * cnt[i] % MOD;
  }
  std::cout << ans << '\n';
  return 0;
}
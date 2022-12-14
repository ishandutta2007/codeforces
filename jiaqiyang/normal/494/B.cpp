#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 100000 + 10, MOD = 1000000007;

int n, m;
char s[N], t[N];

int main() {
  scanf(" %s %s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  static int next[N];
  next[1] = 0;
  for (int i = 2; i <= m; ++i) {
    int k = next[i - 1];
    while (k && t[k + 1] != t[i]) k = next[k];
    if (t[k + 1] == t[i]) ++k;
    next[i] = k;
  }
  static bool flag[N];
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j && t[j + 1] != s[i]) j = next[j];
    if (t[j + 1] == s[i]) ++j;
    if (j == m) flag[i] = true, j = next[j];
  }
  static int f[N], g[N], sum[N], pre[N];
  pre[0] = -1;
  for (int i = 1; i <= n; ++i) if (flag[i]) pre[i] = i - m; else pre[i] = pre[i - 1];
  f[0] = sum[0] = 1;
  for (int i = 1; i <= n; ++i) {
    if (pre[i] >= 0) f[i] = ((pre[i] + 1LL) * sum[pre[i]] - g[pre[i]]) % MOD;
    sum[i] = (sum[i - 1] + f[i]) % MOD;
    g[i] = (g[i - 1] + (i64)f[i] * i) % MOD;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) (ans += f[i]) %= MOD;
  printf("%d\n", (ans + MOD) % MOD);
  return 0;
}
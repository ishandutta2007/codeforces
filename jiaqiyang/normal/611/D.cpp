#include <cstdio>

const int N = 5000 + 10, MOD = 1000000007;

int n;
char s[N];

int f[N];

int main() {
  scanf("%d %s", &n, s + 1);
  f[0] = 1;
  for (int j = 1; j <= n; ++j) {
    static int g[N];
    for (int k = n - j + 1; k <= n; ++k) g[k] = 0;
    for (int k = n - j; k > 0; --k)
      if (s[k] == s[k + j]) g[k] = g[k + 1] + 1; else g[k] = 0;
    static int cur[N];
    for (int i = 0; i <= n; ++i) cur[i] = 0;
    for (int i = j; i <= n; ++i) {
      if (s[i - j + 1] == '0') continue;
      cur[i] = f[i - j];
      if (i >= 2 * j) {
        int t = g[i - 2 * j + 1];
        if (t < j && s[i - 2 * j + 1 + t] < s[i - j + 1 + t]) cur[i] = (cur[i] + cur[i - j]) % MOD;
      }
    }
    for (int i = 0; i <= n; ++i) f[i] = (f[i] + cur[i]) % MOD;
  }
  printf("%d\n", f[n]);
  return 0;
}
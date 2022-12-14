#include <cstdio>

const int N = 1000000 + 10, MOD = 1000000007;

typedef long long i64;

int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

int n, k, m, f[N];

int fact[N];

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = (i64)fact[i - 1] * i % MOD;
  scanf("%d%d", &n, &k);
  m = k + 2;
  for (int i = 1; i <= m; ++i) f[i] = (f[i - 1] + power(i, k)) % MOD;
  static int pre[N], suf[N];
  pre[0] = suf[m + 1] = 1;
  for (int i = 1; i <= m; ++i) pre[i] = (i64)pre[i - 1] * (n - i + MOD) % MOD;
  for (int i = m; i > 0; --i) suf[i] = (i64)suf[i + 1] * (n - i + MOD) % MOD;
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    int numer = (i64)pre[i - 1] * suf[i + 1] % MOD;
    int denom = (i64)fact[i - 1] * fact[m - i] % MOD;
    if ((m - i) & 1) denom = MOD - denom;
    ans = (ans + (i64)numer * power(denom, MOD - 2) % MOD * f[i]) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}
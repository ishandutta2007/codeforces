#include <cstdio>

typedef long long i64;

const int N = 200000 + 10, MOD = 1000000007;

int fact[N], ifact[N];

inline int binom(int n, int m) { return m > n ? 0 : ((i64)fact[n] * ifact[m] % MOD * ifact[n - m] % MOD); }

int n, a[N];

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = (i64)fact[i - 1] * i % MOD;
  ifact[1] = 1;
  for (int i = 2; i < N; ++i) ifact[i] = ((i64)MOD - MOD / i) * ifact[MOD % i] % MOD;
  ifact[0] = 1;
  for (int i = 1; i < N; ++i) ifact[i] = (i64)ifact[i - 1] * ifact[i] % MOD;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int sig = 1; n > 1 && ((n & 1) || sig < 0); --n)
    for (int i = 1; i < n; ++i) a[i] = (a[i] + sig * a[i + 1]) % MOD, sig = -sig;
  int x = 0, y = 0;
  for (int i = 1; i <= n; i += 2) x = (x + (i64)binom((n - 1) / 2, (i - 1) / 2) * a[i]) % MOD;
  for (int i = 2; i <= n; i += 2) y = (y + (i64)binom((n - 1) / 2, (i - 1) / 2) * a[i]) % MOD;
  if (!(n & 1)) x = (x + (n % 4 == 2 ? 1 : -1) * y) % MOD;
  printf("%d\n", (x + MOD) % MOD);
  return 0;
}
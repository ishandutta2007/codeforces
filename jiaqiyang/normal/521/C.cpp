#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, MOD = 1000000007;

int n, k;
char s[N];

int hash[N];

int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

int fact[N], inv[N];

inline int binom(int n, int m) {
  if (m > n) return 0;
  return (i64)fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = (i64)fact[i - 1] * i % MOD;
  inv[N - 1] = power(fact[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1LL) % MOD;
  scanf("%d%d %s", &n, &k, s + 1);
  std::reverse(s + 1, s + n + 1);
  int ans = 0;
  for (int i = 1, cur = 0; i <= n; ++i) {
    ans = (ans + (cur + (i64)power(10, i - 1) * binom(n - i, k)) % MOD * (s[i] - '0')) % MOD;
    cur = (cur + (i64)power(10, i - 1) * binom(n - i - 1, k - 1)) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}
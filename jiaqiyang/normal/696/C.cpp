#include <cstdio>

typedef long long i64;

const int N = 100000 + 10, MOD = 1000000007;

int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

int n;
i64 a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  bool flag = true;
  for (int i = 1; i <= n; ++i) if (!(a[i] & 1)) flag = false;
  int k = 1;
  for (int i = 1; i <= n; ++i) k = a[i] % (MOD - 1) * k % (MOD - 1);
  k = (k - 1 + MOD - 1) % (MOD - 1);
  int q = power(2, k);
  int p = (q + (flag ? -1LL : 1LL)) * power(3, MOD - 2) % MOD;
  p = (p + MOD) % MOD;
  printf("%d/%d\n", p, q);
  return 0;
}
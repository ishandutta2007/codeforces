#include <bits/stdc++.h>

typedef long long int64;

const int N = (1 << 25) + 10, MOD = 1051131;

inline void INC(int &a, int b) { a = (a + b) % MOD; }
inline int sum(int a, int b) { return (a + b) % MOD; }
inline int dif(int a, int b) { return ((a - b) % MOD + MOD) % MOD; }
inline void MUL(int &a, int b) { a = (int64)a * b % MOD; }
inline int pdt(int a, int b) { return (int64)a * b % MOD; }
inline void DIV2(int &a) { MUL(a, 525566); }

inline int _1(int x) { return 1 << x; }

int m, a[N];
int64 t;

inline int pow(int base, int64 exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) MUL(res, base);
    MUL(base, base);
  }
  return res;
}

void divide(int k, int p, int q) {
  if (k == 0) {
    MUL(a[1], pow(p + q, t));
    return;
  }
  int n = _1(k - 1);
  for (int i = 1; i <= n; ++i) {
    int u = a[i], v = a[i + n];
    a[i] = sum(u, v);
    a[i + n] = dif(u, v);
  }
  divide(k - 1, pdt(2, p), (((int64)n * p - p + q) % MOD + MOD) % MOD);
  int tmp = pow((((int64)p + q - n * p) % MOD + MOD) % MOD, t);
  for (int i = n + 1; i <= 2 * n; ++i)  MUL(a[i], tmp);
  for (int i = 1; i <= n; ++i) {
    int u = a[i], v = a[i + n];
    a[i] = sum(u, v);
    a[i + n] = dif(u, v);
  }
  for (int i = 1; i <= 2 * n; ++i) DIV2(a[i]);
}

int main() {
  int s;
  scanf("%d%I64d%d", &m, &t, &s);
  for (int i = 1; i <= s; ++i) scanf("%d", a + i);
  for (int i = s + 1; i <= _1(m); ++i) a[i] = sum(pdt(101, a[i - s]), 10007);
  divide(m, 1, 0);
  int ans = 0;
  for (int i = 1; i <= _1(m); ++i) ans ^= a[i];
  printf("%d\n", ans);
  return 0;
}
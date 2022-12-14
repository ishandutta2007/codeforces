#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 30 + 10, MOD = 1000000007;

int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

int n;

int bit[N], m;

int f[N][N][2];

void trans(int i, int f[N][2], int res[N][2]) {
  for (int j = 0; j <= m; ++j) {
    for (int k = 0; k < 2; ++k) {
      int cur = f[j][k];
      if (!cur) continue;
      int t = (j ? ((i64)cur << (j - 1)) % MOD : cur);
      (res[j][k || bit[i]] += t) %= MOD;
      if (k || bit[i]) {
        (res[j + 1][k] += cur) %= MOD;
        if (j) (res[j][k] += t) %= MOD;
      }
    }
  }
}

void init() {
  f[0][0][0] = 1;
  for (int i = 0; i < m; ++i) trans(i, f[i], f[i + 1]);
}

int main() {
  scanf("%d", &n);
  m = 0;
  for (int i = n; i; i >>= 1) bit[m++] = i & 1;
  std::reverse(bit, bit + m);
  init();
  int ans = 0;
  for (int i = 0; i <= m; ++i)
    for (int j = 0; j < 2; ++j)
      ans = (ans + f[m][i][j]) % MOD;
  printf("%d\n", ans);
  return 0;
}
#include <cstdio>

typedef long long i64;

const int N = 200 + 10, S = 10, MOD = 1000000007;

int fact[N], inv[N];

const int trans[S][S] = {
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
  {1, 2, 0, 1, 0, 0, 0, 0, 0, 0},
  {1, 2, 0, 0, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 1, 0, 0, 0, 0},
  {1, 0, 2, 0, 0, 0, 1, 0, 0, 0},
  {1, 3, 0, 2, 1, 0, 0, 1, 0, 0},
  {1, 2, 1, 1, 0, 2, 0, 0, 1, 0},
  {1, 4, 0, 4, 2, 0, 0, 4, 0, 1}
};

const int x[S] = {12, 9, 6, 6, 6, 3, 0, 3, 0, 0};
const int y[S] = {4, 2, 1, 1, 0, 0, 0, 0, 0, 0};

int n, k;
int f[N][N][S];

inline int binom(int n, int m) {
  if (m > n) return 0;
  return (i64)fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = (i64)fact[i - 1] * i % MOD;
  fprintf(stderr, "%d\n", fact[N - 1]);
  inv[N - 1] = 930755077;
  for (int i = N - 2; i >= 0; --i) inv[i] = (i64)inv[i + 1] * (i + 1) % MOD;
  scanf("%d%d", &n, &k);
  f[0][0][0] = 1;
  f[0][1][1] = 4, f[0][1][2] = 4;
  f[0][2][3] = 4, f[0][2][4] = 2, f[0][2][5] = 8, f[0][2][6] = 2;
  f[0][3][7] = 4, f[0][3][8] = 4;
  f[0][4][9] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= k; ++j) {
      for (int s = 0; s < S; ++s) {
        int cur = f[i][j][s];
        if (!cur) continue;
        for (int t = 0; t < S; ++t) {
          if (!trans[s][t]) continue;
          for (int b = 0; b <= y[t] && j + b <= k; ++b)
            for (int a = 0; 2 * b + a <= x[t] && j + b + a <= k; ++a)
              (f[i + 1][j + b + a][t] += (i64)cur * trans[s][t] % MOD * binom(y[t], b) % MOD * binom(x[t] - 2 * b, a) % MOD) %= MOD;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < S; ++i) (ans += f[n][k][i]) %= MOD;
  ans = (i64)ans * fact[k] % MOD;
  printf("%d\n", ans);
  return 0;
}
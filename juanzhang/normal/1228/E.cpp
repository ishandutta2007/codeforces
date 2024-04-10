#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int P = 1e9 + 7;
int n, m, pw1[255], pw2[255], C[255][255], f[255][255];

int main() {
  scanf("%d %d", &n, &m);
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw1[i] = 1ll * pw1[i - 1] * m % P;
    pw2[i] = 1ll * pw2[i - 1] * (m - 1) % P;
  }
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
  }
  for (int i = 1; i <= n; i++) {
    f[1][i] = 1ll * C[n][i] * pw2[n - i] % P;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = 1ll * f[i - 1][j] * (pw1[j] - pw2[j] + P) % P * pw2[n - j] % P;
      for (int k = 1; k < j; k++) {
        f[i][j] = (f[i][j] + 1ll * f[i - 1][k] * C[n - k][j - k] % P * pw1[k] % P * pw2[n - j]) % P;
      }
    }
  }
  printf("%d", f[n][n]);
  return 0;
}
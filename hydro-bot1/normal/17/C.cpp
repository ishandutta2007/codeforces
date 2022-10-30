// Hydro submission #61c43e0e2c3670e73888c5db@1640755187288
#include <cstdio>
#include <algorithm>

using ll = long long;

const int N = 150;
const ll MOD = 51123987;

int n;
char S[N + 5];

int Nxt[N + 5][3];
int F[N + 5][N / 3 + 3][N / 3 + 3][N / 3 + 3];

int main() {
  scanf ("%d%s", &n, S + 1);
  for (int i = n; i >= 0; --i) {
    for (int j = 0; j < 3; ++j) Nxt[i][j] = Nxt[i + 1][j];
    if (i) Nxt[i][S[i] - 'a'] = i;
  
  }int ans = 0;
  F[0][0][0][0] = 1;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n / 3 + 1; ++j)
      for (int k = 0; k <= n / 3 + 1; ++k)
        for (int l = 0; l <= n / 3 + 1; ++l) {
          int f = F[i][j][k][l];
          if (Nxt[i][0]) (F[Nxt[i][0]][j + 1][k][l] += f) %= MOD;
          if (Nxt[i][1]) (F[Nxt[i][1]][j][k + 1][l] += f) %= MOD;
          if (Nxt[i][2]) (F[Nxt[i][2]][j][k][l + 1] += f) %= MOD;

          if (j + k + l == n && std::abs (j - k) <= 1 && std::abs (j - l) <= 1 && std::abs (k - l) <= 1) (ans += f) %= MOD;
        }
  printf ("%d\n", ans);
  return 0;
}
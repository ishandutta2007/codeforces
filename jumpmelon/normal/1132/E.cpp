#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int M = 8, L = 840;
big W, Cnt[M + 1], F[M + 1][L];

int main() {
  scanf("%lld", &W);
  F[0][0] = 0;
  for (int j = 1; j < L; j++)
    F[0][j] = LLONG_MIN;
  for (int i = 1; i <= M; i++) {
    scanf("%lld", &Cnt[i]);
    F[i][0] = 0;
    for (int j = 0; j < L; j++)
      F[i][j] = LLONG_MIN;
    for (int c = 0; c * i < L && c <= Cnt[i]; c++)
      for (int j = 0; j < L; j++) {
        int j1 = (j + c * i) % L;
        F[i][j1] = max(F[i][j1], F[i - 1][j] + (j + c * i) / L + (Cnt[i] - c) / (L / i));
      }
  }
  big ans = 0;
  for (int j = 0; j < L && j <= W; j++)
    if (F[M][j] >= 0)
      ans = max(ans, j + min(F[M][j], (W - j) / L) * L);
  printf("%lld\n", ans);
  return 0;
}
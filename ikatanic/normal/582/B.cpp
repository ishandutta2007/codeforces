#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int K = 400;
const int MAX = 110;
const int MAXV = 310;

int f[K*MAX][MAXV];
int g[K*MAX][MAXV];
int a[MAX];
int cnt[MAXV];

int main(void) {
  int N, T;
  scanf("%d %d", &N, &T);
  REP(i, N) scanf("%d", &a[i]);
  REP(i, N) cnt[a[i]]++;

  for (int i = 0; i < K; ++i)
    for (int j = 0; j < N; ++j) {
      int x = i * N + j;
      for (int k = 0; k < MAXV; ++k) {
        f[x+1][k] = max(f[x+1][k], f[x][k]);
        if (a[j] >= k) f[x+1][a[j]] = max(f[x+1][a[j]], f[x][k] + 1);
        g[x+1][k] = max(g[x+1][k], g[x][k]);
        if (a[N-j-1] <= k) g[x+1][a[N-j-1]] = max(g[x+1][a[N-j-1]], g[x][k] + 1);
      }
    }

  for (int i = 0; i <= K*N; ++i) {
    for (int k = 1; k < MAXV; ++k)
      f[i][k] = max(f[i][k], f[i][k-1]);
    for (int k = MAXV-2; k >= 0; --k)
      g[i][k] = max(g[i][k], g[i][k+1]);
  }

  int ans = 0;
  for (int L = 0; L <= K; ++L)
    for (int R = 0; R <= K && L+R <= T; ++R) {
      int M = T - L - R;
      REP(x, MAXV) ans = max(ans, cnt[x]*M + f[L*N][x] + g[R*N][x]);
    }
  printf("%d\n", ans);
  return 0;
}
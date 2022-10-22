#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef pair <int, int> pii;
int n, m, a[12][12], A[12][2010], val[1 << 12], dp[12][1 << 12];

pii data[2010];

void chkmin(int &x, int y) {
  if (x > y) x = y;
}

void chkmax(int &x, int y) {
  if (x < y) x = y;
}

void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    data[i] = pii(0, i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &A[i][j]);
      chkmax(data[j].first, A[i][j]);
    }
  }
  int k = min(n, m);
  sort(data, data + m);
  reverse(data, data + m);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      a[j][i] = A[j][data[i].second];
    }
  }
  int all = (1 << n) - 1;
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < k; i++) {
    for (int S = 0; S <= all; S++) {
      val[S] = 0;
      for (int j = 0; j < n; j++) {
        int s = 0;
        for (int k = 0; k < n; k++) {
          if (S >> k & 1) {
            s += a[(j + k) % n][i];
          }
        }
        chkmax(val[S], s);
      }
    }
    for (int S = 0; S <= all; S++) {
      dp[i][S] = val[S];
      for (int sub = S; sub; sub = (sub - 1) & S) {
        chkmax(dp[i][S], (i ? dp[i - 1][sub] : 0) + val[S ^ sub]);
      }
    }
  }
  printf("%d\n", dp[k - 1][all]);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
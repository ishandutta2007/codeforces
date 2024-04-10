#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

const int maxn = 5010;
int n, m, k, a[maxn], b[maxn], c[maxn], cst[maxn], pos[maxn], dp[2][maxn];

vector <int> vec[maxn], e[maxn];

int main() {
  scanf("%d %d %d", &n, &m, &k);
  int sum = k;
  rep(i, 1, n) {
    scanf("%d %d %d", a + i, b + i, c + i);
    sum += b[i];
  }
  rep(i, 1, m) {
    int u, v;
    scanf("%d %d", &u, &v);
    vec[v].push_back(u);
  }
  cst[n] = a[n];
  per(i, n - 1, 1) {
    cst[i] = max(a[i], cst[i + 1] - b[i]);
  }
  rep(i, 1, n) {
    sort(vec[i].begin(), vec[i].end());
    if (vec[i].empty()) {
      pos[i] = i;
    } else {
      pos[i] = vec[i].back();
    }
    e[pos[i]].push_back(i);
  }
  int sel = 1;
  rep(i, k + 1, sum) {
    dp[0][i] = -1e9;
  }
  rep(i, 1, n) {
    rep(p, cst[i] + b[i], sum) {
      dp[sel][p] = dp[sel ^ 1][p - b[i]];
    }
    rep(p, 0, cst[i] + b[i] - 1) {
      dp[sel][p] = -1e9;
    }
    sel ^= 1;
//    putchar('#');
//    rep(p, 0, sum) {
//      int x = dp[sel ^ 1][p];
//      printf("%d%c", x < 0 ? -1 : x, "\n "[p < sum]);
//    }
    for (int j : e[i]) {
      dp[sel][sum] = dp[sel ^ 1][sum];
      rep(p, 0, sum - 1) {
        dp[sel][p] = max(dp[sel ^ 1][p], dp[sel ^ 1][p + 1] + c[j]);
      }
      sel ^= 1;
    }
//    rep(p, 0, sum) {
//      int x = dp[sel ^ 1][p];
//      printf("%d%c", x < 0 ? -1 : x, "\n "[p < sum]);
//    }
  }
  int ans = -1e9 - 10;
  rep(i, 0, sum) {
    chkmax(ans, dp[sel ^ 1][i]);
  }
  printf("%d", ans < 0 ? -1 : ans);
  return 0;
}
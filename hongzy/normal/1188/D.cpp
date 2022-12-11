#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
const int INF = 1e9;
int n, w, dp[64][N], ord[N], cur[N];
ll a[N], m;
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%lld", a + i), m = max(m, a[i]);
  rep(i, 0, 58) if(m >> i & 1) w = i;
  rep(i, 0, w + 2) rep(j, 0, n) dp[i][j] = INF;
  dp[0][n] = 0;
  rep(i, 1, n) ord[i] = i;
  rep(i, 0, w + 1) {
    int z = 0;
    rep(j, 1, n) if(!(a[ord[j]] >> i & 1)) cur[++ z] = ord[j];
    int _z = z;
    rep(j, 1, n) if(a[ord[j]] >> i & 1) cur[++ z] = ord[j];
    int x = 0, y = _z; // < (x)
    int c = _z;
    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + c);
    rep(j, 1, n) {
      if(x < _z && cur[x + 1] == ord[j]) {
        x ++;
        c --;
      } else {
        y ++;
        c ++;
      }
      dp[i + 1][x] = min(dp[i + 1][x], dp[i][j] + c);
    }
    c = n - _z;
    dp[i + 1][_z] = min(dp[i + 1][_z], dp[i][0] + c);
    x = 0; y = _z;
    rep(j, 1, n) {
      if(x < _z && cur[x + 1] == ord[j]) {
        x ++;
        c ++;
      } else {
        y ++;
        c --;
      }
      dp[i + 1][y] = min(dp[i + 1][y], dp[i][j] + c);
    }
    copy(cur + 1, cur + n + 1, ord + 1);
  }
  printf("%d\n", dp[w + 2][n]);
  return 0;
}
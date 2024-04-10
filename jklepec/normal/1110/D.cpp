#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back


const int MAXN = 1e6 + 5, inf = 1e9;

int num[MAXN];
int dp[7][7], ndp[7][7];

int main() {

  int n, m; cin >> n >> m;
  REP(i, n) {
    int x; cin >> x;
    num[x] ++;
  }
  int sol = 0;
  REP(i, MAXN) {
    if(num[i] > 10) {
      sol += (num[i] - 10) / 3;
      num[i] -= ((num[i] - 10) / 3) * 3;
    }
  }

  REP(i, 7) REP(j, 7) dp[i][j] = -inf;
  dp[0][0] = 0;

  for(int in = MAXN - 3; in >= 1; --in) {
    REP(i, 7) REP(j, 7) ndp[i][j] = -inf;
    REP(i, 7) REP(j, 7) REP(k, 7) {
      if(k > i || k > j || k > num[in] || dp[i][j] < 0) continue;

      int ni = num[in] - k;
      int nj = i - k;

      int tmp = dp[i][j] + k;

      ndp[min(6, ni)][nj] = max(ndp[min(6, ni)][nj], tmp);
      if(ni - 3 < 7 && ni - 3 >= 0) {
        ndp[ni - 3][nj] = max(ndp[ni - 3][nj], tmp + 1);
      }
      if(ni - 6 < 7 && ni - 6 >= 0) {
        ndp[ni - 6][nj] = max(ndp[ni - 6][nj], tmp + 2);
      }
      if(ni - 9 < 7 && ni - 9 >= 0) {
        ndp[ni - 9][nj] = max(ndp[ni - 9][nj], tmp + 3);
      }
      if(ni - 12 < 7 && ni - 12 >= 0) {
        ndp[ni - 12][nj] = max(ndp[ni - 12][nj], tmp + 4);
      }
    }

    memcpy(dp, ndp, sizeof dp);
  }

  int tmp = 0;
  REP(i, 3) REP(j, 3) tmp = max(tmp, dp[i][j]);

  cout << sol + tmp;
}
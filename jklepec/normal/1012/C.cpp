#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 5e3 + 5, inf = 1e9;

int a[MAXN];
int dp[MAXN][MAXN];

int p[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  REP(i, n) cin >> a[i];

  REP(i, n) for(int j = n - 1; j >= 0; --j) {
    dp[i][j] = inf;

    if(j > (i + 2) / 2) continue;

    if(j == 0) {
      p[i][j] = i;
      dp[i][j] = min(dp[i][j], max(0, i ? a[i - 1] - a[i] + 1 : 0));
      continue;
    }

    int lo = 0;
    if(i) lo = p[i - 1][j];

    int hi = i - 2;
    if(p[i][j + 1] != 0) hi = p[i][j + 1];

    FOR(k, lo, hi + 1) {
      int tmp = dp[k][j - 1];

      if(k == i - 2) {
        tmp += max(0, a[i - 1] - min(a[i], a[k]) + 1);
      }
      else {
        tmp += max(0, a[i - 1] - a[i] + 1);
        tmp += max(0, a[k + 1] - a[k] + 1);
      }

      if(tmp < dp[i][j]) {
        p[i][j] = k;
      }

      dp[i][j] = min(dp[i][j], tmp);
    }

  }

//  REP(i, n) REP(j, n) {
//    cout << p[i][j] << " ";
//    if(j == n - 1) cout << endl;
//  }

  REP(j, (n + 1) / 2) {
    int sol = inf;
    REP(i, n) {
      sol = min(sol, dp[i][j] + max(0, a[i + 1] - a[i] + 1));
    }
    cout << sol << " ";
  }
  cout << endl;
}
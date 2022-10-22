#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;

const int MAXN = 2005;

int suff[MAXN][2][2];
int pref[MAXN][2][2];
int dp[MAXN][MAXN][2][2];

int a[MAXN], b[MAXN];

int main() {
  int n; cin >> n;

  REP(i, n) {
    cin >> a[i];
    b[n - i - 1] = a[i];
  }

  REP(i, n) {
    dp[i][i][0][1] ++;
    if(b[i] == 1) dp[i][i][0][0] ++;
    else dp[i][i][1][1] ++;
  }

  REP(i, n) FOR(j, i + 1, n) {
    dp[i][j][0][0] += dp[i][j - 1][0][0] + (b[j] == 1);
    dp[i][j][0][1] = dp[i][j - 1][0][0] + 1;
    dp[i][j][0][1] = max(dp[i][j][0][1], dp[i][j - 1][0][1] + (b[j] == 2));
    dp[i][j][1][1] = dp[i][j - 1][1][1] + (b[j] == 2);
  }

  pref[0][0][1] = 1;
  if(a[0] == 1) {
    pref[0][0][0] = 1;
  }
  else {
    pref[0][1][1] = 1;
  }

  FOR(i, 1, n) {
    pref[i][0][0] = pref[i - 1][0][0] + (a[i] == 1);
    pref[i][0][1] = pref[i - 1][0][0] + 1;
    pref[i][0][1] = max(pref[i][0][1], pref[i - 1][0][1] + (a[i] == 2));
  }

  for(int i = n - 1; i >= 0; --i) {
    suff[i][1][1] = suff[i + 1][1][1] + (a[i] == 2);
    suff[i][0][1] = suff[i + 1][1][1] + 1;
    suff[i][0][1] = max(suff[i][0][1], suff[i + 1][0][1] + (a[i] == 1));
  }

  int sol = 0;
  REP(i, n) FOR(j, i, n) {
    int x = n - j - 1;
    int y = n - i - 1;

    int tmp = dp[x][y][0][1] + (i ? pref[i - 1][0][0] : 0) + suff[j + 1][1][1];
    tmp = max(tmp, dp[x][y][0][0] + (i ? pref[i - 1][0][0] : 0) + suff[j + 1][0][1]);
    tmp = max(tmp, dp[x][y][1][1] + (i ? pref[i - 1][0][1] : 0) + suff[j + 1][1][1]);

    sol = max(sol, tmp);
  }

  cout << sol;

}
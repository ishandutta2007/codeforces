#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5, MAXK = 109, mod = 998244353;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}

int a[MAXN];

int dp[MAXN][MAXK];
int pref[MAXN][MAXK];

int uk[MAXN];

int main() {
  int n, k, l; cin >> n >> k >> l;

  REP(i, n) {
    cin >> a[i];
    if(a[i] > 0) a[i] --;
    pref[i + 1][a[i] + 1] ++;
  }

  FOR(i, 1, n + 1) REP(j, MAXK) {
    pref[i][j] += pref[i - 1][j];
  }

  if(l == 1) {
    cout << 0;
    return 0;
  }

  REP(i, k) {
    if(a[0] == -1 || a[0] == i) {
      dp[0][i] = 1;
      uk[0] ++;
    }
  }

  FOR(i, 1, n) {
    FOR(j, 0, k) {
      if(a[i] != j && a[i] != -1) {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = uk[i - 1];
      if(i + 1 < l) continue;

      int sums = 0;
      sums += pref[i + 1][0] - pref[i - l + 1][0];
      sums += pref[i + 1][j + 1] - pref[i - l + 1][j + 1];

      if(sums != l) continue;

      if(i == l - 1) dp[i][j] = sub(dp[i][j], 1);
      else {
        dp[i][j] = sub(dp[i][j], uk[i - l]);
        dp[i][j] = add(dp[i][j], dp[i - l][j]);
      }
    }

    REP(j, k) {
      uk[i] = add(uk[i], dp[i][j]);
    }
  }


  cout << uk[n - 1] << endl;
}
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define pb push_back
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

const int off = 1 << 13, MAXN = 15, MAX = 105;

int a[MAXN];

int val[off];
int cnt[off];
int dp[off][MAX];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, q, m; cin >> n >> m >> q;
  REP(i, n) {
    cin >> a[i];
  }

  REP(i, m) {
    string x; cin >> x;
    int ms = 0;
    REP(j, n) {
      if(x[j] == '1') ms += (1 << j);
    }
    cnt[ms] ++;
  }

  FOR(j, 1, (1 << n)) {
    REP(i, n) {
      if((1 << i) & j) {
        val[j] = val[j ^ (1 << i)] + a[i];
        break;
      }
    }
  }

  REP(i, (1 << n)) {
    REP(j, (1 << n)) {
      int k = ((1 << n) - 1) ^ (i ^ j);
      if(val[k] >= MAX) continue;
      dp[i][val[k]] += cnt[j];
    }
  }

  REP(i, (1 << n)) for(int j = 1; j < MAX; ++j ) {
    dp[i][j] += dp[i][j - 1];
  }

  REP(i, q) {
    int k, ms = 0;
    string s; cin >> s >> k;
    REP(j, n) {
      if(s[j] == '1') ms += (1 << j);
    }
    cout << dp[ms][k] << "\n";
  }

}
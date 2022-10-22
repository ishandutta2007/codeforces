#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5, MAXK = 3e2 + 5;

int n, m, s, e;

int a[MAXN];
int dp[MAXK][MAXN];

vector<int> in[MAXN];
int pt[MAXN];

void solve() {
  fill(dp[0], dp[0] + n, -1);

  FOR(j, 1, MAXK) {
    REP(i, MAXN) {
      pt[i] = in[i].size() - 1;
    }
    REP(i, n) {
      int x = -1;
      if(i) {
        x = dp[j - 1][i - 1];
      }
      else if(j > 1) {
        x = m;
      }

      int v = (i ? dp[j][i - 1] : m);
      while(pt[a[i]] > 0 && in[a[i]][pt[a[i]] - 1] > x) {
        pt[a[i]] --;
      }

      dp[j][i] = min(v, in[a[i]][pt[a[i]]]);
    }
  }

  int sol = 0;

  FOR(j, 1, MAXK) REP(i, n) {
    if(dp[j][i] < m && i + dp[j][i] + e * j <= s) {
      sol = j;
    }
  }

  cout << sol;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> m >> s >> e; s -= 2;

  REP(i, n) {
    cin >> a[i];
  }
  REP(i, m) {
    int x; cin >> x;
    in[x].push_back(i);
  }
  REP(i, MAXN) {
    in[i].push_back(m);
  }

  solve();
}
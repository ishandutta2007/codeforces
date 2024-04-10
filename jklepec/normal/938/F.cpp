#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 5e3 + 5;

int n, lg;
string s;

int N;

bool dp[MAXN][MAXN];
vector<point> good[MAXN];

char sol[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> s; n = s.size();
  while((1 << lg) * 2 <= n) lg ++;

  REP(i, MAXN) {
    sol[i] = 'z' + 1;
  }

  REP(i, n) REP(j, (1 << lg)) {
    int len = i + 1 - j;

    if(len == 0) {
      dp[i][j] = 1;
    }
    if(len <= 0) {
      continue;
    }

    REP(k, lg) {
      if(!((1 << k) & j)) {
        continue;
      }

      if(dp[i - (1 << k)][j ^ (1 << k)]) {
        dp[i][j] = 1;
        break;
      }
    }

    bool ok = !i || dp[i - 1][j];

    if(ok && (sol[len - 1] > s[i] || len == N + 1)) {
      sol[len - 1] = s[i];
      for(int k = len; good[k].size(); ++k) {
        for(auto p: good[k]) {
          dp[p.first][p.second] = 0;
        }
        good[k].clear();
      }
      N = len;
    }

    if(sol[len - 1] < s[i]) {
      ok = false;
    }
    if(ok) {
      dp[i][j] = 1;
    }

    if(dp[i][j]) {
      good[len].push_back({i, j});
    }
  }

  REP(i, n - (1 << lg) + 1) {
    cout << sol[i];
  }
}
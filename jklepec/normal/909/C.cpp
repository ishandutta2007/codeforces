#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 5005, mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}

char a[MAXN];
int n;
int dp[MAXN][MAXN];

int main() {
  cin >> n;
  REP(i, n)
    cin >> a[i];

  int poc = 1;
  if(a[0] == 's')
    poc = 0;

  dp[0][poc] = 1;

  FOR(i, 1, n) for(int j = n - 1; j >= 0; --j) {
    if(j == 0 && a[i] == 'f') continue;
    if(a[i - 1] == 'f') {
      int old_j = j;
      if(a[i] == 'f')
        old_j --;
      if(old_j >= 0)
        dp[i][j] = add(dp[i][j], dp[i - 1][old_j]);
    }
    else {
      dp[i][j] = add(dp[i][j], dp[i][j + 1]);
      int old_j = j;
      if(a[i] == 'f')
        old_j --;
      if(old_j >= 0)
        dp[i][j] = add(dp[i][j], dp[i - 1][old_j]);
    }
  }

  int sol = 0;
  REP(i, n) {
    sol = add(sol, dp[n - 1][i]);
  }

  cout << sol;
}
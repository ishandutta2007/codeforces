#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int t[3][3];
llint dp[3][3][44];

llint solve(int a, int b, int n) {
  llint &r = dp[a][b][n];
  if (r != -1) return r;
  if (n == 0) return r = 0;

  int c = 3-a-b;
  llint w1 = solve(a, c, n-1) + t[a][b] + solve(c, b, n-1);
  llint w2 = solve(a, b, n-1) + t[a][c] + solve(b, a, n-1) + t[c][b] + solve(a, b, n-1);
  return r = min(w1, w2);
}

int main(void) {
  REP(i, 3) REP(j, 3) scanf("%d", t[i]+j);
  int n;
  scanf("%d", &n);

  memset(dp, -1, sizeof(dp));
  cout << solve(0, 2, n) << endl;
  return 0;
}
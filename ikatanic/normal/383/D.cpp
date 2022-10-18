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

const int mod = 1e9 + 7;

const int MAXN = 1010;
const int MAXS = 10050;
const int off = 5001;

int a[MAXN];
int dp[MAXN][MAXS];

int add(int x, int y) {
  if (x+y >= mod) return x+y-mod;
  return x+y;
}

int mul(int x, int y) {
  return (llint(x)*y)%mod;
}
  
int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);

  int ans = 0;
  REP(i, n) {
    dp[i][off+0] = add(dp[i][off+0], 1);
    REP(j, MAXS)
      if (dp[i][j]) {
        if (j-a[i] >= 0) dp[i+1][j-a[i]] = add(dp[i+1][j-a[i]], dp[i][j]);
        if (j+a[i] < MAXS) dp[i+1][j+a[i]] = add(dp[i+1][j+a[i]], dp[i][j]);
      }
    ans = add(ans, dp[i+1][off+0]);
  }

  printf("%d\n", ans);
  return 0;
}
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

const int mod = 1000000007;

int dp[2][350][350];

void update(int i, int j, int k, int r) {
  if ((dp[i][j][k] += r) >= mod) dp[i][j][k] -= mod;
}

int main(void)
{
  int n, m, x;
  scanf("%d %d %d", &m, &n, &x); --x;
  
  if (m > n) { printf("0\n"); return 0; }

  dp[0][0][0] = 1;
  REP(i, n) {
    int now = i&1, next = now^1;
    REP(j, m+1) REP(k, m+1) {
      int r = dp[now][j][k];
      dp[now][j][k] = 0;

      update(next, j+1, k, r); // otvori
      update(next, j, k+1, r); // otvori i zatvori
      
      if (i != x) {
        if (j > 0) update(next, j-1, k+1, r); // zatvori
        update(next, j, k, r); // nista
      }
    }
  }

  int ans = dp[n%2][0][m];
  for (int i = 1; i <= m; ++i)
    ans = (llint(ans)*i)%mod;

  printf("%d\n", ans);
  return 0;
}
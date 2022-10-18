#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int mod = 1e9 + 7;
const int MAXN = 32;

int f[MAXN][MAXN][2];
bool bit[MAXN];

int solve(int x, int y, bool dira) {
  if (f[x][y][dira] != -1) return f[x][y][dira];
  if (y == 30) return f[x][y][dira] = 1;

  int ans = 0;

  // mat[x][y] = 0
  int ways0 = (x == 0 ? 1 : (1LL<<(x-1)));
  int ways1 = ((1<<x) - ways0 + mod)%mod;
  ans = (ans + llint(ways0)*solve(x, y+1, dira & !bit[y]))%mod;
  if (!dira || bit[y])
    ans = (ans + llint(ways1)*solve(x, y+1, dira & bit[y]))%mod;
  
  // mat[x][y] = 1
  if (!dira || bit[y])
    ans = (ans + solve(x+1, y+1, dira & bit[y]))%mod;
  return f[x][y][dira] = ans;
}

int main(void) {
  memset(f, -1, sizeof(f));
  int m;
  scanf("%d", &m);
  REP(i, 30) bit[30-i-1] = (m>>i)&1;
  printf("%d\n", solve(0, 0, 1));
  return 0;
}
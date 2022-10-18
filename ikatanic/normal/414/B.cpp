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

const int MAXN = 2020;

int f[MAXN][MAXN];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  
  f[0][1] = 1;
  REP(i, k)
    for (int j = 1; j <= n; ++j)
      if (f[i][j])
        for (int k = j; k <= n; k += j)
          if ((f[i+1][k] += f[i][j]) >= mod) f[i+1][k] -= mod;
  
  int ans = 0;
  REP(j, n+1)
    if ((ans += f[k][j]) >= mod) ans -= mod;
  printf("%d\n", ans);
  return 0;
}
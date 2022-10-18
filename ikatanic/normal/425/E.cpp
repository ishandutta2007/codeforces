#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int mod = 1e9 + 7;
const int MAXN = 505;

int f[MAXN][MAXN];
int pw[MAXN*MAXN];

int add(int x, int y) {
  return x+y >= mod ? x+y-mod : x+y;
}

int mul(int x, int y) {
  return (llint(x)*y)%mod;
}

int main(void) {
  int n, K;
  scanf("%d %d", &n, &K);
  
  pw[0] = 1;
  for (int i = 1; i <= n*n; ++i)
    pw[i] = add(pw[i-1], pw[i-1]);

  f[0][0] = 1;
  REP(i, n) REP(k, K)
    if (f[i][k])
      for (int j = i; j < n; ++j) {
        int ways = pw[j-i+1] - 1;
        if (ways < 0) ways += mod;
        ways = mul(ways, pw[(j-i+1)*(n-1-j)]);
        f[j+1][k+1] = add(f[j+1][k+1], mul(ways, f[i][k]));
      }

  int ans = 0;
  REP(i, n+1)
    ans = add(ans, f[i][K]);

  printf("%d\n", ans);
  return 0;
}
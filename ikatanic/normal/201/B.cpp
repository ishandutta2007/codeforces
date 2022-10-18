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

const int MAXN = 1001;

int a[MAXN][MAXN];
int sx[MAXN], sy[MAXN];

llint solve(int n, int *s, int &x) {
  llint ans = 1e18;
  for (int i = 0; i <= n; ++i) {
    llint cost = 0;
    REP(j, n) {
      llint d = 2;
      if (j < i) d += 4*(i-1-j); else
        d += 4*(j-i);
      cost += s[j]*d*d;
    }
    if (cost < ans) ans = cost, x = i;
  }
  return ans;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) REP(j, m) {
    scanf("%d", a[i]+j);
    sx[i] += a[i][j];
    sy[j] += a[i][j];
  }

  llint ans = 0;
  int x, y;
  ans += solve(n, sx, x);
  ans += solve(m, sy, y);

  cout << ans << endl;
  cout << x << " " << y << endl;
  
  return 0;
}
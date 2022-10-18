#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

llint solve(int n, int m, int k, int xx) {
  llint ans = -1;
  FOR(x, xx-1, xx+2) {
    int y = k - x;
    if (x < 0 || y < 0 || x >= n || y >= m) continue;
    ans = max(ans, llint(n/(x+1))*(m/(y+1)));
  }
  return ans;
}

int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  llint ans = -1;
  FOR(x, 1, 100000) {
    if (n%x == 0) {
      ans = max(ans, solve(n, m, k, x));
      ans = max(ans, solve(n, m, k, n/x));
    }
    if (m%x == 0) {
      ans = max(ans, solve(m, n, k, x));
      ans = max(ans, solve(m, n, k, m/x));
    }
  }

  ans = max(ans, solve(n, m, k, 0));
  ans = max(ans, solve(m, n, k, 0));

  cout << ans << endl;
  return 0;
}
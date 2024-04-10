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

const int MAXN = 100010;

llint a[MAXN], b[MAXN];

llint solve(llint *a, int n, llint *b, int m) {
  llint sum = accumulate(b, b + m, 0LL);
  llint ans = sum;
  REP(i, n-1)
    ans += min(sum, a[i]);
  return ans;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) { int x; scanf("%d", &x); a[i] = x; }
  REP(i, m) { int x; scanf("%d", &x); b[i] = x; }


  sort(a, a + n);
  sort(b, b + m);

  llint ans = min(solve(a, n, b, m), solve(b, m, a, n));
  cout << ans << endl;
  return 0;
}
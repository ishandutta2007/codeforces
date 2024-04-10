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

const llint inf = 1e12;
const int K = 32000;

int main(void) {
  int n;
  llint k;
  scanf("%d %lld", &n, &k);

  vector<int> a(n);
  REP(i, n) scanf("%d", &a[i]);

  vector<llint> d;
  FOR(i, 1, K) d.push_back(i);
  REP(i, n) {
    FOR(j, 1, K) if (j <= a[i]) d.push_back((a[i] + j - 1) / j);
  }

  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  d.push_back(inf);

  llint ans = 0;
  REP(i, (int)d.size() - 1) {
    llint x = d[i];
    llint y = d[i + 1] - 1;

    llint s = 0, c = 0;
    REP(i, n) {
      c += a[i];
      s += (a[i] + x - 1) / x;
    }

    if (s*x - c <= k) {
      ans = max(ans, min(y, (k + c) / s));
    }
  }

  printf("%lld\n", ans);
  return 0;
}
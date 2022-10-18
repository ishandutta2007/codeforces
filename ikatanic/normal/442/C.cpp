#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 500500;

int a[MAXN];
int n;

llint solve() {
  static int p[MAXN];
  REP(i, n) p[i] = i;
  sort(p, p + n, [] (const int &x, const int &y) {
      return a[x] < a[y];
    }
  );
  
  static set<int> S;
  REP(i, n) S.insert(i);
  
  llint ans = 0;
  REP(pi, n-2) {
    int i = p[pi];

    auto it = S.lower_bound(i);
    auto itn = it; ++itn;

    if (it == S.begin() || itn == S.end()) ans += a[i]; else {
      auto itp = it; --itp;
      if (itn != S.end()) ans += min(a[*itn], a[*itp]);
    }
    S.erase(it);
  }
  return ans;
}
  
int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  
  llint ans = solve();
  cout << ans << endl;
  return 0;
}
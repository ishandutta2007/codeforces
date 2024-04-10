#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 300000;

llint a[MAX];
llint b[MAX];

pair<int, bool> normalize(llint* b, int n) {
  int m = 0;
  while (m < n || b[m]) {
    b[m+1] += b[m] / 2;
    b[m] %= 2;
    if (b[m] == -1 && (m < n || b[m+1])) b[m] = 1, b[m+1]--;
    m++;
  }
  
  bool negate = false;
  if (b[m-1] == -1) {
    b[m-1] = 0;
    REP(i, m-1) {
      assert(0 <= b[i] && b[i] <= 1);
      b[i] ^= 1;
    }
    b[0]++;
    auto p = normalize(b, m + 1);
    assert(!p.second);
    m = p.first;
    negate = true;
  }
  
  while (m > 0 && b[m-1] == 0) m--;
  return {m, negate};
}
  
int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  REP(i, n+1) scanf("%lld", &a[i]);

  int ans = 0;

  REP(i, n+1) b[i] = a[i];
  auto p = normalize(b, n + 1);
  int m = p.first;
  assert(m > 0);
  m--;

  int f = 0;
  while (b[f] == 0) f++;

  REP(i, n+1) {
    if (i > f) break;
    if (m - i > 50) continue;
    
    llint x = 0;
    for (int j = f; j <= m; ++j)
      x |= b[j] << (j - i);
    if (!p.second) x *= -1;
    x += a[i];

    if (i < n || x)
      if (x >= -k && x <= k) {
        ans++;
      }
  }

  printf("%d\n", ans);
  return 0;
}
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

const int MAX = 10010;
const llint inf = 1e18;

int p[MAX], s[MAX];
llint f[MAX], nf[MAX];

int main(void) {
  int n, c;
  scanf("%d %d", &n, &c);
  REP(i, n) scanf("%d", &p[i]);
  REP(i, n) scanf("%d", &s[i]);

  f[0] = 0;
  REP(i, n) {
    REP(j, i+2) nf[j] = inf;
    REP(j, i+1) {
      nf[j] = min(nf[j], f[j] + j*1LL*c + p[i]);
      nf[j+1] = min(nf[j], f[j] + s[i]);
    }
    REP(j, i+2) f[j] = nf[j];
  }

  llint ans = *min_element(f, f + n + 1);
  printf("%lld\n", ans);
  return 0;
}
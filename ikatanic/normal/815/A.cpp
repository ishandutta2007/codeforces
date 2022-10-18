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

const int MAX = 555;

int g[MAX][MAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) REP(j, m) scanf("%d", &g[i][j]);

  int best = -1;
  vector<int> best_a, best_b;
  REP(x, MAX) {
    vector<int> a(n), b(m);
    a[0] = x;
    REP(j, m) b[j] = g[0][j] - x;
    REP(i, n) a[i] = g[i][0] - b[0];

    bool ok = true;
    REP(i, n) ok &= a[i] >= 0;
    REP(j, m) ok &= b[j] >= 0;
    REP(i, n) REP(j, m) ok &= (a[i] + b[j] == g[i][j]);

    if (ok) {
      int total = accumulate(a.begin(), a.end(), 0) + accumulate(b.begin(), b.end(), 0);
      if (best == -1 || total < best) {
        best = total;
        best_a = a;
        best_b = b;
      }
    }
  }

  printf("%d\n", best);
  if (best != -1) {
    REP(i, n) REP(j, best_a[i]) printf("row %d\n", i+1);
    REP(j, m) REP(i, best_b[j]) printf("col %d\n", j+1);
  }
  return 0;
}
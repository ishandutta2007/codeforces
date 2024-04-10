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

double dd[100][100];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  
  set<int> sx, sy;
  REP(k, 4) {
    if (k <= n) sx.insert(k);
    if (n-k >= 0) sx.insert(n - k);
    if (k <= m) sy.insert(k);
    if (m-k >= 0) sy.insert(m - k);
  }

  vector<int> x, y;
  for (int X: sx)
    for (int Y: sy) {
      x.push_back(X);
      y.push_back(Y);
    }
  
  int k = x.size();
  REP(i, k) REP(j, k)
    dd[i][j] = hypot(x[i]-x[j], y[i]-y[j]);

  double ans = -1;
  int p1, p2, p3, p4;

  REP(a, k) REP(b, k) REP(c, k) REP(d, k) {
    if (a == b || a == c || a == d) continue;
    if (b == c || b == d) continue;
    if (c == d) continue;

    double len = dd[a][b] + dd[b][c] + dd[c][d];
    if (len > ans) {
      ans = len;
      p1 = a, p2 = b, p3 = c, p4 = d;
    }
  }

  printf("%d %d\n", x[p1], y[p1]);
  printf("%d %d\n", x[p2], y[p2]);
  printf("%d %d\n", x[p3], y[p3]);
  printf("%d %d\n", x[p4], y[p4]);
  return 0;
}
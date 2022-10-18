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


int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> a(n, vector<int>(m));
  REP(i, n) REP(j, m) scanf("%d", &a[i][j]);
  
  
  REP(c1, m) REP(c2, c1 + 1) {
    bool ok = true;
    REP(i, n) {
      bool ok_row = false;
      
      auto& v = a[i];
      REP(d1, m) REP(d2, d1 + 1) {
        swap(v[d1], v[d2]);
        swap(v[c1], v[c2]);
        ok_row |= is_sorted(v.begin(), v.end());
        swap(v[c1], v[c2]);
        swap(v[d1], v[d2]);

        swap(v[c1], v[c2]);
        swap(v[d1], v[d2]);
        ok_row |= is_sorted(v.begin(), v.end());
        swap(v[d1], v[d2]);
        swap(v[c1], v[c2]);
      }

      ok &= ok_row;
    }
    if (ok) {
      puts("YES");
      return 0;
    }
  }

  puts("NO");
  return 0;
}
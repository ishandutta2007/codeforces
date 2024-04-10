#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<string> a(N);
  REP(i, N) cin >> a[i];

  int minx = N, miny = M, maxx = 0, maxy = 0;
  REP(i, N) REP(j, M) {
    if (a[i][j] == 'B') {
      minx = min(minx, i);
      miny = min(miny, j);
      maxx = max(maxx, i);
      maxy = max(maxy, j);
    }
  }

  cout << (minx + maxx) / 2 + 1 << " " << (miny + maxy) / 2 + 1 << "\n";
  return 0;
}
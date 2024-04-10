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

const int inf = 2e9;

struct Rect {
  int x1, y1, x2, y2;
};

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<Rect> a(N);
  REP(i, N) cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;

  vector<Rect> pref(N + 1);
  pref[0] = {-inf, -inf, inf, inf};
  REP(i, N) {
    pref[i + 1] = {
        max(pref[i].x1, a[i].x1),
        max(pref[i].y1, a[i].y1),
        min(pref[i].x2, a[i].x2),
        min(pref[i].y2, a[i].y2),
    };
  }

  Rect suf = {-inf, -inf, inf, inf};
  for (int i = N - 1; i >= 0; --i) {
    Rect cur = {
        max(pref[i].x1, suf.x1),
        max(pref[i].y1, suf.y1),
        min(pref[i].x2, suf.x2),
        min(pref[i].y2, suf.y2),
    };

    if (cur.x1 <= cur.x2 && cur.y1 <= cur.y2) {
      cout << cur.x1 << " " << cur.y1 << "\n";
      return 0;
    }

    suf = {
        max(suf.x1, a[i].x1),
        max(suf.y1, a[i].y1),
        min(suf.x2, a[i].x2),
        min(suf.y2, a[i].y2),
    };
  }

  return 0;
}
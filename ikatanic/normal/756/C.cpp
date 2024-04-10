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

const int off = 1<<17;

pair<int, int> T[2*off];
int v[off];

int main(void) {
  int m;
  scanf("%d", &m);
  REP(i, m) {
    int p, t;
    scanf("%d %d", &p, &t);
    --p;

    if (t == 0) {
      T[off+p] = {1, 0};
    } else {
      scanf("%d", &v[p]);
      T[off+p] = {0, 1};
    }

    for (int x = (off + p) / 2; x; x /= 2) {
      int l = x*2, r = x*2+1;
      int match = min(T[l].second, T[r].first);
      T[x] = {T[l].first + T[r].first - match, T[l].second + T[r].second - match};
    }

    if (T[1].second == 0) {
      printf("-1\n");
    } else {
      int x = 1, k = T[1].second;
      while (x < off) {
        int l = x*2, r = x*2+1;

        if (T[l].second <= T[r].first) {
          x = r;
        } else {
          if (k <= T[l].second - T[r].first) {
            x = l;
          } else {
            k -= T[l].second - T[r].first;
            x = r;
          }
        }
      }

      printf("%d\n", v[x-off]);
    }
  }
  return 0;
}
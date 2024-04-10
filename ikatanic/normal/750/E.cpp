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

const int inf = 1e9;
const int off = 1<<18;

struct data {
  int f[5][5];

  data() {
    REP(i, 5) REP(j, 5) f[i][j] = inf;
  };
  
  friend data operator + (const data& a, const data& b) {
    data c;
    for (int i = 0; i < 5; ++i) {
      for (int j = i; j < 5; ++j) {
        for (int k = j; k < 5; ++k) {
          c.f[i][k] = min(c.f[i][k], a.f[i][j] + b.f[j][k]);
        }
      }
    }
    return c;
  };
};

data T[2*off];
data empty;

data query(int i, int lo, int hi, int a, int b) {
  if (lo >= b || hi <= a) return empty;
  if (lo >= a && hi <= b) return T[i];
  return
    query(i*2, lo, (lo+hi)/2, a, b) +
    query(i*2+1, (lo+hi)/2, hi, a, b);
}
                                  
int main(void) {
  REP(x, 5) empty.f[x][x] = 0;
  
  int n, q;
  scanf("%d %d", &n, &q);
  static char s[off];
  scanf("%s", s);
  REP(i, n) {
    int d = s[i] - '0';

    data& f = T[off + i];
    REP(x, 5) {
      if (d == 2) {
        if (x == 0) {
          f.f[x][x] = 1;
          f.f[x][x+1] = 0;
        } else {
          f.f[x][x] = 0;
        }
      } else if (d == 0) {
        if (x == 1) {
          f.f[x][x] = 1;
          f.f[x][x+1] = 0;
        } else {
          f.f[x][x] = 0;
        }
      } else if (d == 1) {
        if (x == 2) {
          f.f[x][x] = 1;
          f.f[x][x+1] = 0;
        } else {
          f.f[x][x] = 0;
        }
      } else if (d == 7) {
        if (x == 3) {
          f.f[x][x] = 1;
          f.f[x][x+1] = 0;
        } else {
          f.f[x][x] = 0;
        }
      } else if (d == 6) {
        if (x == 3 || x == 4) {
          f.f[x][x] = 1;
        } else {
          f.f[x][x] = 0;
        }
      } else {
        f.f[x][x] = 0;
      }
    }
  }

  for (int i = off-1; i > 0; --i)
    T[i] = T[i*2] + T[i*2+1];
  
  REP(i, q) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;

    int ans = query(1, 0, off, a, b+1).f[0][4];
    
    if (ans == inf) puts("-1");
    else printf("%d\n", ans);
  }
    
  return 0;
}
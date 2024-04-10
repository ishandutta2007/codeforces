#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 505;
const int B = 61;

bitset<MAX> f[B][2][MAX];
bitset<MAX> g[B][2][MAX];


bitset<MAX> cur, tmp;
llint len;

int n;

bool go(int k, int flip) {
  tmp.reset();
  REP(i, n) {
    if (cur.test(i)) {
      tmp |= f[k][flip][i];
    }
  }

  if (tmp.any()) {
    cur = tmp;
    len += 1LL<<k;
    return true;
  }

  if (k == 0) return false;

  bool full_left = go(k-1, flip);
  if (full_left) {
    return go(k-1, flip^1);
  } else {
    return false;
  }
}

int main(void) {
  int m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    --a, --b;

    f[0][c][a][b] = 1;
    g[0][c][b][a] = 1;
  }
  
  FOR(k, 1, B) REP(flip, 2) REP(x, n) REP(y, n)
    f[k][flip][x][y] = g[k][flip][y][x] = (f[k-1][flip][x] & g[k-1][flip^1][y]).any();

  cur.set(0);
  go(B-1, 0);

  if (len > (llint)(1e18)) {
    puts("-1");
  } else {
    printf("%lld\n", len);
  }
  return 0;
}
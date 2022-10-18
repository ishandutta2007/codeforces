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

const int MAXL = 11;

struct loga {
  vector<int> L;
  int N;
  
  void init(int n) {
    N = n + 4;
    L.clear();
    L.resize(N);
  }
  
  int sum(int x) {
    int r = 0;
    for (++x; x; x -= x&-x)
      r += L[x];
    return r;
  }

  void add(int x, int v) {
    for (++x; x < N; x += x&-x)
      L[x] += v;
  }
} a[4][MAXL][MAXL];

const int MAX = 100100;

char s[MAX];

int toInt(char c) {
  if (c == 'A') return 0;
  if (c == 'T') return 1;
  if (c == 'G') return 2;
  if (c == 'C') return 3;
  assert(false);
}

int main(void) {
  scanf("%s", s);
  int n = strlen(s);
  REP(i, n) s[i] = toInt(s[i]);

  for (int x = 1; x < MAXL; ++x) {
    REP(i, 4) REP(y, x) a[i][x][y].init(n/x + 1);
    REP(i, n) a[(int)s[i]][x][i%x].add(i / x, 1);
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int type;
    scanf("%d", &type);

    if (type == 1) {
      int i;
      static char b[11];
      scanf("%d %s", &i, b);

      --i;
      int c = toInt(b[0]);

      for (int x = 1; x < MAXL; ++x) {
        a[(int)s[i]][x][i%x].add(i / x, -1);
        a[c][x][i%x].add(i / x, 1);
      }
      s[i] = c;
    } else if (type == 2) {
      int l, r;
      static char e[MAXL];
      scanf("%d %d %s", &l, &r, e);
      --l, --r;

      int ans = 0;
      int x = strlen(e);
      REP(i, x) {
        int first = l + i;
        if (first > r) break;

        int last = r;
        while (last % x != first % x) last--;
        
        int rem = first % x;
        int c = toInt(e[i]);
        ans += a[c][x][rem].sum(last / x) - a[c][x][rem].sum(first / x - 1);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
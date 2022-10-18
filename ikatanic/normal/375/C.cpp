#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

#include <set>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

struct state {
  int x, y, s;
  state(int _x, int _y, int _s) { x = _x; y = _y; s = _s; };
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char a[22][22];
int v[22];
int px[22], py[22];

int d[22][22][1<<8];

struct cmp {
  bool operator() (const state &a, const state &b) {
    if (d[a.x][a.y][a.s] != d[b.x][b.y][b.s]) return d[a.x][a.y][a.s] < d[b.x][b.y][b.s];
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.s < b.s;
  }
};

set<state, cmp> S;

int main(void)
{
  int n, m;
  scanf("%d %d", &n, &m);
  
  int t = 0, p = 0;
  int sx, sy;
  REP(i, n) {
    scanf("%s", a[i]);
    REP(j, m) {
      if (isdigit(a[i][j]) || a[i][j] == 'B') px[p] = i, py[p] = j, p++;
      if (isdigit(a[i][j])) t = max(t, a[i][j]-'0');
      if (a[i][j] == 'S') sx = i, sy = j, a[i][j] = '.';
    }
  }

  REP(i, t) scanf("%d", v+i);

  memset(d, 63, sizeof(d));
  d[sx][sy][0] = 0;
  S.insert(state(sx, sy, 0));
  
  int ans = 0;
  while (S.size()) {
    state s = *S.begin();
    S.erase(S.begin());
    int r = d[s.x][s.y][s.s];
    
    if (s.x == sx && s.y == sy) {
      int sum = 0;
      REP(i, p)
        if (s.s&(1<<i)) {
          if (a[px[i]][py[i]] == 'B') { sum = -1; break; }
          sum += v[a[px[i]][py[i]]-'1'];
        }      
      ans = max(ans, sum-r);
    }

    REP(dd, 4) {
      int x = s.x+dx[dd], y = s.y+dy[dd], ss = s.s;
      if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] != '.') continue;
      if (y != s.y)
        REP(i, p)
          if (py[i] == max(y, s.y) && px[i] < x) ss ^= (1<<i);
      
      if (r+1 < d[x][y][ss]) {
        S.erase(state(x, y, ss));
        d[x][y][ss] = r+1;
        S.insert(state(x, y, ss));
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
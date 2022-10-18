#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;
typedef pair<int, int> par;
#define x first
#define y second

const int MAXN = 200100;
const int off = 100010;

int n;
par a[MAXN];
vector<int> vx[MAXN], vy[MAXN], vd[MAXN];

bool check(int x, int y) {
  par p = {x, y};
  int lo = 0, hi = n-1;
  while (lo < hi) {
    int mid = (lo + hi)/2;
    if (a[mid] < p) lo = mid+1; else
      hi = mid;
  }
  return lo < n && a[lo] == p;
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[i] = {x, y};
    vx[x].push_back(y);
    vy[y].push_back(x);
    vd[x-y+off].push_back(x);
  }

  sort(a, a + n);
  REP(i, MAXN) {
    sort(vx[i].begin(), vx[i].end());
    sort(vy[i].begin(), vy[i].end());
    sort(vd[i].begin(), vd[i].end());
  }
  
  int ans = 0;
  REP(i, n) {
    int x = a[i].x, y = a[i].y, d = a[i].x-a[i].y+off;

    int sx = vx[x].size(), sy = vy[y].size(), sd = vd[d].size();
    if (sx <= sy && sx <= sd) {
      for (int j = 0; j < sx && vx[x][j] < y; ++j)
        if (check(x-y+vx[x][j], y) && check(x-y+vx[x][j], vx[x][j])) ans++;
    } else 
      if (sy <= sx && sy <= sd) {
        for (int j = 0; j < sy && vy[y][j] < x; ++j)
          if (check(x, y-x+vy[y][j]) && check(vy[y][j], y-x+vy[y][j])) ans++;
      } else {
        for (int j = 0; j < sd && vd[d][j] < x; ++j)
          if (check(vd[d][j], y) && check(x, y-x+vd[d][j])) ans++;
      }
  }

  printf("%d\n", ans);
  return 0;
}
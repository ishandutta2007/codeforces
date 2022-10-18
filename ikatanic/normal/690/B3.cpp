#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 100005;

typedef long long llint;
typedef pair<int, int> Pt;
#define x first
#define y second

int convexHull(Pt *a, int n) {
  rotate(a, min_element(a, a + n), a + n);
  
  auto ccw = [](const Pt &a, const Pt &b, const Pt &c) {
    llint ccw = a.x*llint(b.y-c.y) + b.x*llint(c.y-a.y) + c.x*llint(a.y-b.y);
    return ccw < 0 ? -1 : ccw > 0;
  };

  auto dist = [](const Pt &a, const Pt &b) {
    return llint(a.x-b.x)*(a.x-b.x) + llint(a.y-b.y)*(a.y-b.y);
  };

  sort(a + 1, a + n, [&a, &ccw, &dist](const Pt &x, const Pt &y) {
      int c = ccw(a[0], x, y);
      if (c) return c > 0;
      return dist(a[0], x) < dist(a[0], y);
    }
  );
  
  int m = 0;
  REP(i, n) {
    while (m >= 2 && ccw(a[m-2], a[m-1], a[i]) <= 0) m--;
    a[m++] = a[i];
  }

  return m;
}

int touch[MAX], cookie;
int row_lo[MAX];
int row_hi[MAX];
set< pair< int, int > > M, F;

bool is_four(int x, int y) {
  if (x < 0 || x > MAX) return false;
  if (touch[x] != cookie) return false;
  if (M.find({x, y}) != M.end()) return false;
  return y >= row_lo[x] && y <= row_hi[x];
}

int main(void) {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    if (n == 0) break;
    ++cookie;

    M.clear();
    F.clear();

    REP(i, m) {
      int x, y;
      scanf("%d%d", &x, &y);
      M.insert({x, y});

      if (touch[x] != cookie) {
	touch[x] = cookie;
	row_lo[x] = y;
	row_hi[x] = y;
      }

      row_lo[x] = min(row_lo[x], y);
      row_hi[x] = max(row_hi[x], y);
    }

    for (auto c : M) {
      REP(d, 4) {
	int x = c.first + dx[d];
	int y = c.second + dy[d];

	if (is_four(x, y))
	  F.insert({x, y});
      }
    }

    for (auto f : F) M.insert(f);

    vector<Pt> v;
    for (auto c : M) 
      if (M.find({c.first + 1, c.second}) != M.end() &&
	  M.find({c.first, c.second + 1}) != M.end() &&
	  M.find({c.first + 1, c.second + 1}) != M.end())
	v.push_back({c.first, c.second});

    int m = convexHull(&v[0], v.size());
    printf("%d\n", m);
    reverse(v.begin() + 1, v.begin() + m);
    REP(i, m) {
      printf("%d %d\n", v[i].x, v[i].y);
    }
  }
  
  return 0;
}
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

struct Point {
  int x, y, z;

  Point(int _x = 0, int _y = 0, int _z = 0) {
    x = _x; y = _y; z = _z;
  }

  int distance(const Point &p) const {
    return Abs(x - p.x) + Abs(y - p.y) + Abs(z - p.z);
  }
};

#define MAX   100100
Point points[MAX];
int n;
map<int, vector<int>> filterByX;
vector<pair<int, int>> res;

void init(void) {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int x, y, z; scanf("%d%d%d", &x, &y, &z);
    points[i] = Point(x, y, z);
    filterByX[x].push_back(i);
  }
}

bool SortByZ(const int &x, const int &y) {
  return points[x].z < points[y].z;
}
int solve1D(vector<int> &indices) {
  if (indices.empty()) return -1;
  sort(ALL(indices), SortByZ);
  REP(i, indices.size() / 2) res.push_back(make_pair(indices[2 * i], indices[2 * i + 1]));
  return indices.size() % 2 == 1 ? indices.back() : -1;
}

int solve2D(const vector<int> &indices) {
  map<int, vector<int>> filterByY;
  FORE(it, indices) filterByY[points[*it].y].push_back(*it);

  int remain = -1;
  FORE(it, filterByY) {
    vector<int> &ids = it->se;
    if (remain > 0) {
      int best = 0;
      REP(j, ids.size()) if (points[remain].distance(points[ids[j]]) < points[remain].distance(points[ids[best]])) best = j;
      res.push_back(make_pair(remain, ids[best]));
      ids.erase(ids.begin() + best);
    }
    remain = solve1D(ids);
  }

  return remain;
}

void process(void) {
  int remain = -1;
  FORE(it, filterByX) {
    vector<int> &ids = it->se;
    if (remain > 0) {
      int best = 0;
      REP(j, ids.size()) if (points[remain].distance(points[ids[j]]) < points[remain].distance(points[ids[best]])) best = j;
      res.push_back(make_pair(remain, ids[best]));
      ids.erase(ids.begin() + best);
    }
    remain = solve2D(ids);
  }
  FORE(it, res) printf("%d %d\n", it->fi, it->se);
}

int main(void) {
  init();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
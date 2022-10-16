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

class FenwickTree {
  vector<long long> v;
  int n;

 public:
  FenwickTree(int n = 0) {
    this->n = n;
    if (n > 0) v.assign(n + 7, 0);
  }

  void update(int x, long long d) {
    for (; x <= n; x += x & -x) v[x] += d;
  }

  void update(int l, int r, long long d) {
    if (l > r) return;
    update(l, d);
    update(r + 1, -d);
  }

  long long get(int x) const {
    long long res = 0;
    for (; x >= 1; x &= x - 1) res += v[x];
    return res;
  }
};

const int INF = (int)1e9 + 7;
class SegmentTree {
 private:
  vector<int> lazy;
  int n;

  void update(int i, int l, int r, int u, int v, int c) {
    if (l > v || r < u || l > r || v < u) return;
    if (u <= l && r <= v) {
      maximize(lazy[i], c);
      return;
    }

    int m = (l + r) >> 1;
    update(2 * i, l, m, u, v, c);
    update(2 * i + 1, m + 1, r, u, v, c);
  }

  void getResult(int i, int l, int r, int curMax, vector<int> &res) const {
    maximize(curMax, lazy[i]);
    if (l == r) return res.push_back(curMax);

    int m = (l + r) >> 1;
    getResult(2 * i, l, m, curMax, res);
    getResult(2 * i + 1, m + 1, r, curMax, res);
  }
 public:
  SegmentTree(int n = 0) {
    this->n = n;
    if (n > 0) lazy.assign(4 * n + 7, -INF);
  }

  void update(int l, int r, int c) {
    update(1, 1, n, l, r, c);
  }

  vector<int> getResult(void) const {
    vector<int> res;
    getResult(1, 1, n, -INF, res);
    return res;
  }
};

#define MAX   1000100
int numRow, numCol;
vector<int> rows[MAX];
FenwickTree bit;

int nextInt(void) {
  int x; scanf("%d", &x);
  return x;
}

void init(void) {
  numRow = nextInt();
  numCol = nextInt();
  FOR(i, 1, numRow) REP(love, nextInt()) rows[i].push_back(nextInt());
}

struct Query {
  int l, r, v;

  Query(int _l = 0, int _r = 0, int _v = 0) {
    l = _l; r = _r; v = _v;
  }
};
Query queries[MAX];
int numQuery;

void processRow(const vector<int> &row) {
  // printf("PROCESS: "); FORE(it, row) printf("%d ", *it); printf("\n");
  numQuery = 0;
  int rowSize = row.size();
  FOR(i, 1, rowSize) queries[numQuery++] = Query(i, numCol - rowSize + i, row[i - 1]);
  if (rowSize <= numCol / 2) queries[numQuery++] = Query(1, numCol, 0);
  else {
    queries[numQuery++] = Query(1, numCol - rowSize, 0);
    queries[numQuery++] = Query(rowSize + 1, numCol, 0);
  }

  vector<int> points;
  points.push_back(1);
  points.push_back(numCol + 1);
  REP(i, numQuery) {
    points.push_back(queries[i].l);
    points.push_back(queries[i].r + 1);
  }
  sort(ALL(points));
  points.resize(unique(ALL(points)) - points.begin());

  SegmentTree myit(points.size() - 1);
  REP(i, numQuery) {
    int l = lower_bound(ALL(points), queries[i].l) - points.begin() + 1;
    int r = upper_bound(ALL(points), queries[i].r) - points.begin();
    myit.update(l, r, queries[i].v);
  }

  vector<int> values = myit.getResult();
  REP(i, points.size() - 1) bit.update(points[i], points[i + 1] - 1, values[i]);
}

void process(void) {
  bit = FenwickTree(numCol);
  FOR(i, 1, numRow) processRow(rows[i]);
  cerr << "DONE" << endl;
  FOR(i, 1, numCol) cout << bit.get(i) << " ";
  cout << endl;
}

int main(void) {
  init();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
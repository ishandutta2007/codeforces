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

class SegmentTree {
 private:
  int n;
  vector<pair<long long, int>> tree;
  vector<long long> lazy;

  void build(long long a[], int i, int l, int r) {
    if (l == r) {
      tree[i] = make_pair(a[l], -l);
      return;
    }

    int m = (l + r) >> 1;
    build(a, 2 * i, l, m);
    build(a, 2 * i + 1, m + 1, r);
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }

  void pushDown(int i) {
    FOR(j, 2 * i, 2 * i + 1) {
      tree[j].fi += lazy[i];
      lazy[j] += lazy[i];
    }
    lazy[i] = 0;
  }

  void update(int i, int l, int r, int u, int v, long long c) {
    if (l > v || r < u || l > r || v < u) return;
    if (u <= l && r <= v) {
      tree[i].fi += c;
      lazy[i] += c;
      return;
    }

    pushDown(i);
    int m = (l + r) >> 1;
    update(2 * i, l, m, u, v, c);
    update(2 * i + 1, m + 1, r, u, v, c);
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
  }

 public:
  SegmentTree(int n = 0, long long a[] = NULL) {
    this->n = n;
    if (n > 0) {
      tree.assign(4 * n + 7, pair<long long, int>());
      lazy.assign(4 * n + 7, 0);
      build(a, 1, 1, n);
    }
  }

  void update(int l, int r, long long c) {
    update(1, 1, n, l, r, c);
  }

  int getZeroPos(void) const {
    return tree[1].fi == 0 ? -tree[1].se : -1;
  }
};

#define MAX    200200
const long long INF = (long long)1e18 + 7LL;
long long a[MAX];
int perm[MAX], n;

void process(void) {
  cin >> n;
  FOR(i, 1, n) cin >> a[i];

  SegmentTree myit(n, a);
  FOR(i, 1, n) {
    int pos = myit.getZeroPos();
    assert(pos > 0);
    perm[pos] = i;
    myit.update(pos + 1, n, -i);
    myit.update(pos, pos, INF);

  }

  FOR(i, 1, n) printf("%d ", perm[i]); printf("\n");
}

int main(void) {
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
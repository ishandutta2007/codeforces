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

#define MAX   200200
int d[MAX], n;
pair<int, int> p[MAX];

void process(void) {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", &d[i]);

  FOR(i, 1, n) p[i] = make_pair(d[i], i);
  sort(p + 1, p + n + 1, greater<pair<int, int>>());

  vector<int> nodes;
  vector<pair<int, int>> edges;
  FOR(i, 1, n) nodes.push_back(2 * p[i].se);
  REP(i, n - 1) edges.push_back(make_pair(nodes[i], nodes[i + 1]));

  REP(i, n) {
    int j = nodes[i];
    int par = nodes[i + d[j / 2] - 1];
    edges.push_back(make_pair(par, j - 1));
    if (par == nodes.back()) nodes.push_back(j - 1);
  }

  FORE(it, edges) printf("%d %d\n", it->fi, it->se);
}

int main(void) {
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
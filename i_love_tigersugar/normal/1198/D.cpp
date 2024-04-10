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

#define MAX   55
const int INF = (int)1e9 + 7;

char board[MAX][MAX];
int cnt[MAX][MAX];
int n;
int f[MAX][MAX][MAX][MAX];

void init(void) {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%s", board[i] + 1);
  FOR(i, 1, n) FOR(j, 1, n) cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + (board[i][j] == '#');
}

int getCnt(int x1, int y1, int x2, int y2) {
  if (x1 > x2) return 0;
  if (y1 > y2) return 0;
  return cnt[x2][y2] - cnt[x1 - 1][y2] - cnt[x2][y1 - 1] + cnt[x1 - 1][y1 - 1];
}

int minCost(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  int &res = f[x1][y1][x2][y2];
  if (res >= 0) return res;

  res = INF;
  minimize(res, getCnt(x1, y1, x2, y2));
  minimize(res, max(x2 - x1, y2 - y1) + 1);

  FOR(t, x1, x2 - 1) minimize(res, minCost(x1, y1, t, y2) + minCost(t + 1, y1, x2, y2));
  FOR(t, y1, y2 - 1) minimize(res, minCost(x1, y1, x2, t) + minCost(x1, t + 1, x2, y2));
  return res;
}

void process(void) {
  memset(f, -1, sizeof f);
  cout << minCost(1, 1, n, n) << endl;
}

int main(void) {
  init();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
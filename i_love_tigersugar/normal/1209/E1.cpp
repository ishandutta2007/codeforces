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

#define MAX   111
int numRow, numCol;
int initBoard[MAX][MAX], usedBoard[MAX][MAX], maxCol[MAX];

void init(void) {
  memset(initBoard, 0, sizeof initBoard);
  memset(usedBoard, 0, sizeof usedBoard);
  memset(maxCol, 0, sizeof maxCol);

  scanf("%d%d", &numRow, &numCol);
  FOR(i, 1, numRow) FOR(j, 1, numCol) scanf("%d", &initBoard[i][j]);
  FOR(i, 1, numRow) FOR(j, 1, numCol) maximize(maxCol[j], initBoard[i][j]);
}

bool compCol(const int &x, const int &y) {
  return maxCol[x] > maxCol[y];
}

void process(void) {
  vector<int> indices;
  FOR(i, 1, numCol) indices.push_back(i);
  sort(ALL(indices), compCol);

  minimize(numCol, numRow);
  indices.resize(numCol);
  FOR(i, 1, numRow) FOR(j, 1, numCol) usedBoard[i][j] = initBoard[i][indices[j - 1]];
  FOR(i, 1, numRow) FOR(j, 1, numCol) usedBoard[i + numRow][j] = usedBoard[i][j];

  int best = 0;
  REP(ahihi, 256) {
    int mask = ahihi;
    int state[10];
    memset(state, 0, sizeof state);
    REP(i, numCol) {
      state[i] = mask & 3; mask >>= 2;
    }

    int sum = 0;
    FOR(i, 1, numRow) {
      int maxRow = 0;
      FOR(j, 1, numCol) maximize(maxRow, usedBoard[i + state[j]][j]);
      sum += maxRow;
    }
    maximize(best, sum);
  }

  cout << best << endl;
}

int main(void) {
  int t; scanf("%d", &t);
  REP(love, t) {
    init();
    process();
  }
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
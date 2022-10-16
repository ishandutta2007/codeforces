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

#define NMOD    7
int MOD[NMOD] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277, 0, 0, 0};
struct Hash {  
  int value[NMOD];

  Hash(int x = 0) {
    REP(i, NMOD) value[i] = x;
  }

  void operator += (const Hash &x) {
    REP(i, NMOD) {
      value[i] += x.value[i];
      if (value[i] >= MOD[i]) value[i] -= MOD[i];
    }
  }

  Hash operator * (const Hash &x) const {
    Hash res;
    REP(i, NMOD) res.value[i] = 1LL * value[i] * x.value[i] % MOD[i];
    return res;
  }

  bool operator == (const Hash &x) const {
    REP(i, NMOD) if (value[i] != x.value[i]) return false;
    return true;
  }
};

#define MAX   1000100
#define BLOCKED   '#'

int numRow, numCol;
string board[MAX];
vector<Hash> cntStart[MAX], cntEnd[MAX];

char input[MAX];
void init(void) {
  scanf("%d%d", &numRow, &numCol);
  FOR(i, 1, numRow) {
    scanf("%s", input + 1);
    board[i] = string(numCol + 1, '0');
    FOR(j, 1, numCol) board[i][j] = input[j];
  }

  FOR(i, 1, numRow) {
    cntStart[i].assign(numCol + 1, 0);
    cntEnd[i].assign(numCol + 1, 0);
  }
}

bool ok(int x, int y) {
  return 1 <= x && x <= numRow && 1 <= y && y <= numCol && board[x][y] != BLOCKED;
}

int process(void) {
  cntStart[1][1] = 1;
  FOR(i, 1, numRow) FOR(j, 1, numCol) {
    if (ok(i + 1, j)) cntStart[i + 1][j] += cntStart[i][j];
    if (ok(i, j + 1)) cntStart[i][j + 1] += cntStart[i][j];
  }

  cntEnd[numRow][numCol] = 1;
  FORD(i, numRow, 1) FORD(j, numCol, 1) {
    if (ok(i - 1, j)) cntEnd[i - 1][j] += cntEnd[i][j];
    if (ok(i, j - 1)) cntEnd[i][j - 1] += cntEnd[i][j];
  }

  if (cntEnd[1][1] == 0) return 0;
  FOR(i, 1, numRow) FOR(j, 1, numCol) {
    if (i == 1 && j == 1) continue;
    if (i == numRow && j == numCol) continue;
    if (!ok(i, j)) continue;
    if (cntStart[i][j] * cntEnd[i][j] == cntEnd[1][1]) return 1;
  }
  return 2;
}

int main(void) {
  FOR(i, 4, NMOD - 1) MOD[i] = rand() / 2;
  init();
  cout << process() << endl;
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
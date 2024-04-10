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

#define MAX   300300
#define LOG   19

int a[MAX], n, res[MAX];
int maxValue[MAX][LOG + 1], minValue[MAX][LOG + 1], lg2[MAX];

void init(void) {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", &a[i]);
  FOR(i, 1, n) a[i] *= 2;
  FOR(i, n + 1, 3 * n) a[i] = a[i - n];
}

void prepareRMQ(void) {
  FOR(i, 1, 3 * n) minValue[i][0] = maxValue[i][0] = a[i];
  FOR(j, 1, LOG) FOR(i, 1, 3 * n - MASK(j) + 1) {
    minValue[i][j] = min(minValue[i][j - 1], minValue[i + MASK(j - 1)][j - 1]);
    maxValue[i][j] = max(maxValue[i][j - 1], maxValue[i + MASK(j - 1)][j - 1]);
  }
  FOR(i, 1, 3 * n) {
    while (MASK(lg2[i]) <= i) lg2[i]++; lg2[i]--;
  }
}

int getMax(int l, int r) {
  int k = lg2[r - l + 1];
  return max(maxValue[l][k], maxValue[r - MASK(k) + 1][k]);
}
int getMin(int l, int r) {
  int k = lg2[r - l + 1];
  return min(minValue[l][k], minValue[r - MASK(k) + 1][k]);
}

int firstGreater(int pos, int value) {
  if (getMax(pos, 3 * n) < value) return -1;
  int L = pos, R = 3 * n;
  while (true) {
    if (L == R) return L;
    if (R - L == 1) return getMax(pos, L) >= value ? L : R;
    int M = (L + R) >> 1;
    if (getMax(pos, M) >= value) R = M; else L = M + 1;
  }
}
int firstLess(int pos, int value) {
  if (getMin(pos, 3 * n) > value) return -1;
  int L = pos, R = 3 * n;
  while (true) {
    if (L == R) return L;
    if (R - L == 1) return getMin(pos, L) <= value ? L : R;
    int M = (L + R) >> 1;
    if (getMin(pos, M) <= value) R = M; else L = M + 1;
  }
}

void process(void) {
  res[3 * n] = 3 * n;
  FORD(i, 3 * n - 1, 1) {
    if (a[i] <= a[i + 1]) res[i] = res[i + 1];
    else {
      int j = firstGreater(i + 1, a[i]);
      int k = firstLess(i + 1, a[i] / 2 - 1);
      if (j < 0) {
        res[i] = k < 0 ? 3 * n : k - 1;
      } else {
        res[i] = k < 0 || k >= j ? res[i + 1] : k - 1;
      }
    }
  }

  FOR(i, 1, n) printf("%d ", res[i] == 3 * n ? -1 : res[i] - i + 1); printf("\n");
}

int main(void) {
  init();
  prepareRMQ();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
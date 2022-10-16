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

#define MAX   500500
int numValue, values[MAX], cnt[MAX], sumCnt[MAX];
int limValue, limBit;

int process(void) {
  map<int, int> cntValue;
  int n; scanf("%d%d", &n, &limBit); limBit <<= 3;
  REP(love, n) {
    int x; scanf("%d", &x); cntValue[x]++;
  }
  FORE(it, cntValue) {
    numValue++;
    values[numValue] = it->fi;
    cnt[numValue] = it->se;
    sumCnt[numValue] = sumCnt[numValue - 1] + cnt[numValue];
  }

  limBit /= n;
  if (limBit >= 20) return 0;
  if (MASK(limBit) >= numValue) return 0;

  int res = -1;
  FOR(i, 1, numValue - MASK(limBit) + 1) {
    int j = i + MASK(limBit) - 1;
    maximize(res, sumCnt[j] - sumCnt[i - 1]);
  }

  return sumCnt[numValue] - res;
}

int main(void) {
  cout << process() << endl;
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
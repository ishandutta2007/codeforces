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
int a[MAX], last[MAX], n;

void init(void) {
  int q; scanf("%d%d", &n, &q);
  FOR(i, 1, n) scanf("%d", &a[i]);
}

int countGroup(int l, int r) {
  map<int, int> cnt;
  FOR(i, l, r) cnt[a[i]]++;
  int maxCnt = 0;
  FORE(it, cnt) maximize(maxCnt, it->se);
  return r - l + 1 - maxCnt;
}

int findNext(int l) {
  int r = last[l];
  int i = l;
  while (i <= r) {
    maximize(r, last[i]);
    i++;
  }
  return r;
}

void process(void) {
  map<int, int> lastPos;
  FOR(i, 1, n) lastPos[a[i]] = i;
  FOR(i, 1, n) last[i] = lastPos[a[i]];

  int res = 0;
  int i = 0;
  while (i < n) {
    int l = i + 1;
    int r = findNext(l);
    res += countGroup(l, r);
    i = r;
  }

  cout << res << endl;
}

int main(void) {
  init();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
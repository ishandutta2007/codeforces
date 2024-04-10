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

#define OPEN   '('
#define CLOSE   ')'

bool ok(const string &s) {
  int deg = 0;
  FORE(it, s) {
    if (*it == OPEN) deg++; else deg--;
    if (deg < 0) return false;
  }
  return deg == 0;
}

bool solve(string s) {
  if (ok(s)) return true;

  int numOpen = 0, numClose = 0;
  FORE(it, s) {
    if (*it == OPEN) numOpen++; else numClose++;
  }
  if (numOpen != numClose) return false;

  int deg = 0;
  int n = s.size();
  REP(i, n) {
    if (s[i] == OPEN) deg++; else deg--;
    if (deg < 0) {
      string newS = s.substr(0, i) + s.substr(i + 1) + string(1, s[i]);
      if (ok(newS)) return true;

      int lastOpen = -1;
      FOR(j, i + 1, n - 1) if (s[j] == OPEN) lastOpen = j;
      if (lastOpen <= i) return false;
      newS = s.substr(0, i) + "(" + s.substr(i, lastOpen - i) + s.substr(lastOpen + 1);
      if (ok(newS)) return true;

      return false;
    }
  }
}

int main(void) {
  int n; string s; while (cin >> n >> s) cout << (solve(s) ? "Yes" : "No") << endl;
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
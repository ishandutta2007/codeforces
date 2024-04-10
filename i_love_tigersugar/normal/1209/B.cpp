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

bool turnOn(bool init, int a, int b, int t) {
  if (t < b) return init;
  int tmp = (t - b) % (2 * a);
  return tmp < a ? !init : init;
}

#define MAX   100100
char s[MAX];
int a[MAX], b[MAX], n;

void init(void) {
  scanf("%d", &n);
  scanf("%s", s + 1);
  FOR(i, 1, n) scanf("%d%d", &a[i], &b[i]);
}

void process(void) {
  int best = 0;
  REP(i, 555555) {
    int cnt = 0;
    FOR(j, 1, n) if (turnOn(s[j] == '1', a[j], b[j], i)) cnt++;
    maximize(best, cnt);
  }

  cout << best << endl;
}

int main(void) {
  init();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
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

#define MAX   7070
bool better[MAX][MAX];
int n;
long long know[MAX];
int value[MAX], deg[MAX];

void init(void) {
  cin >> n;
  FOR(i, 1, n) cin >> know[i];
  FOR(i, 1, n) cin >> value[i];
}

bool isBetter(long long x, long long y) {
  return (x & ~y) > 0;
}

void process(void) {
  FOR(i, 1, n) FOR(j, 1, n) {
    better[i][j] = isBetter(know[i], know[j]);
    if (better[i][j]) deg[i]++;
  }

  set<int> s;
  FOR(i, 1, n) s.insert(i);
  while (s.size() > 1) {
    int cur = -1;
    FORE(it, s) if (cur < 0 || deg[*it] > deg[cur]) cur = *it;
    if (deg[cur] < s.size() - 1) break;
    
    s.erase(cur);
    FOR(i, 1, n) if (better[i][cur]) deg[i]--;
  }

  long long sum = 0;
  FORE(it, s) sum += value[*it];
  cout << (s.size() > 1 ? sum : 0LL) << endl;
}

int main(void) {
  init();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
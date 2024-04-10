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

#define MAX   1000100
#define NUM_BIT   21

int a[MAX], n;
int score[MASK(NUM_BIT) + 7];
// int lg2[MASK(NUM_BIT) + 7];

void init(void) {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", &a[i]);
  // REP(i, NUM_BIT) lg2[MASK(i)] = i;
}

queue<int> q;
bool inQueue[MASK(NUM_BIT) + 7];
void addNumber(int x) {
  queue<int> q;
  q.push(x); inQueue[x] = true;

  while (!q.empty()) {
    int u = q.front(); q.pop(); inQueue[u] = false;
    score[u]++;

    int tmp = u;
    while (tmp > 0) {
      int maskOfBit = tmp & -tmp;
      int v = u ^ maskOfBit;
      if (score[v] < 2 && !inQueue[v]) {
        q.push(v); inQueue[v] = true;
      }
      tmp ^= maskOfBit;
    }
  }
}

int chooseGreedy(int x) {
  int needMask = 0;
  int res = 0;
  FORD(i, NUM_BIT - 1, 0) {
    bool canBitOne = BIT(x, i) || score[needMask | MASK(i)] >= 2;
    if (canBitOne) {
      res |= MASK(i);
      if (!BIT(x, i)) needMask |= MASK(i);
    }
  }
  return res;
}

void process(void) {
  int res = 0;
  FORD(i, n, 1) {
    maximize(res, chooseGreedy(a[i]));
    addNumber(a[i]);
  }

  cout << res << endl;
}

int main(void) {
  init();
  process();
  return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
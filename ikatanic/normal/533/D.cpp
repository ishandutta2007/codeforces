#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 100100;
const llint inf = 1e10;

llint lval[MAXN];
llint x[MAXN], d[MAXN];
llint rl[MAXN], rr[MAXN];
int n;

llint rem[MAXN];

void calc_r(llint *r) {
  stack<int> alive;
  rem[0] = r[0] = d[0];
  alive.push(0);
  
  for (int i = 1; i < n; ++i) {
    int last = alive.top();
    rem[last] -= x[i] - x[last];
    
    while (rem[alive.top()] < 0) {
      int last = alive.top(); alive.pop();
      rem[alive.top()] -= x[i] - x[last];
    }

    rem[i] = r[i] = d[i] - (x[i] - x[alive.top()]);
    alive.push(i);
  }
}

int main(void) {
  scanf("%d", &n);
  n += 2;
  REP(i, n) scanf("%lld", x+i);
  FOR(i, 1, n-1) scanf("%lld", d+i);
  d[0] = d[n-1] = inf;
  REP(i, n) d[i] *= 2;

  calc_r(rl);
  REP(i, n) x[i] = x[n-1] - x[i];
  reverse(x, x + n);
  reverse(d, d + n);
  
  calc_r(rr);
  reverse(rr, rr + n);
  REP(i, n) x[i] = x[n-1] - x[i];
  reverse(x, x + n);
  reverse(d, d + n);

  FOR(i, 1, n-1)
    if (rem[i] >= 0) {
      puts("0");
      return 0;
    }

  llint ans = inf;
  vector<int> S;
  for (int i = 0; i < n; ++i) {
    llint rval = rr[i] - x[i];
    if (rr[i] > 0 && S.size() && rval >= lval[S[0]]) {
      int lo = 0, hi = (int)S.size() - 1;
      while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (rval >= lval[S[mid]]) lo = mid; else
          hi = mid - 1;
      }
      ans = min(ans, x[i] - x[S[lo]]);
    }

    if (rl[i] > 0) {
      lval[i] = -x[i] - rl[i];
      while (S.size() && lval[i] <= lval[S.back()]) S.pop_back();
      S.push_back(i);
    }
  }

  printf("%.5lf\n", ans / 2.0);
  return 0;
}
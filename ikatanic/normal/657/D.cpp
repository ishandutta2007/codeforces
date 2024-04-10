#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Problem {
  llint p, t;
  llint lt, eq;
};

bool test(vector<Problem>& a, double c) {
  int n = a.size();
  double best = -1;
  int i = 0;
  while (i < n) {
    int j = i;
    double nbest = best;
    while (j < n && a[i].p == a[j].p) {
      double mins = a[i].p * (1 - c*(a[j].lt + a[j].eq));
      double maxs = a[i].p * (1 - c*(a[j].lt + a[j].t));
      if (mins < best) return false;
      nbest = max(nbest, maxs);
      j++;
    }

    best = nbest;
    i = j;
  }
  return true;
}

int main(void) {
  int n;
  scanf("%d", &n);
  vector<Problem> a(n);
  REP(i, n) scanf("%lld", &a[i].p);
  REP(i, n) scanf("%lld", &a[i].t);

  sort(a.begin(), a.end(), [&] (const Problem& a, const Problem& b) {
      return a.p*b.t > b.p*a.t;
    }
  );

  vector<llint> mint(n), maxt(n);

  int i = 0;
  llint sumt = 0;
  while (i < n) {
    int j = i;
    while (j < n && a[i].p*a[j].t == a[j].p*a[i].t) j++;
    
    llint sum = 0;
    FOR(k, i, j) sum += a[k].t;
    FOR(k, i, j) a[k].lt = sumt, a[k].eq = sum;
    sumt += sum;
    
    i = j;
  }

  sort(a.begin(), a.end(), [&] (const Problem& a, const Problem& b) {
      return a.p < b.p;
    }
  );
  
  double lo = 0, hi = 1;
  REP(it, 50) {
    double mid = (lo + hi) / 2;
    if (test(a, mid/sumt)) lo = mid;
    else hi = mid;
  }
  printf("%.10lf\n", lo);
  return 0;
}
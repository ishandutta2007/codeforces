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
typedef long double ldb;

int main(void) {
  int a[4];
  REP(i, 4) scanf("%d", a+i);
  
  ldb lo = 0, hi = 2e9;
  REP(it, 1000) {
    ldb mid = (lo + hi) / 2;

    ldb blo[4], bhi[4];
    REP(i, 4) {
      blo[i] = a[i] - mid;
      bhi[i] = a[i] + mid;
    }
    
    auto get = [&] (int i, int j) {
      vector<ldb> v = {blo[i]*blo[j], blo[i]*bhi[j], bhi[i]*blo[j], bhi[i]*bhi[j]};
      sort(v.begin(), v.end());
      return make_pair(v[0], v[3]);
    };

    auto v1 = get(0, 3);
    auto v2 = get(1, 2);
    if (v1.second < v2.first || v1.first > v2.second) lo = mid; else
      hi = mid;
  }
  
  printf("%.10lf\n", (double)lo);
  return 0;
}
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  llint n;
  cin >> n;

  set<llint> S;
  FOR(k, 1, 62) {
    llint B = (1LL<<k) - 3;

    llint lo = 0, hi = 2e9;
    if (k > 20) hi = min(hi, 2*n / B + 10);

    while (lo < hi) {
      llint mid = (lo + hi)/2;
      if (mid*mid + B*mid < 2*n) lo = mid+1; else
        hi = mid;
    }

    if (lo*lo + B*lo == 2*n && (lo&1) == 1) S.insert(lo << (k-1));
  }
  
  if (S.size() == 0) puts("-1"); else
    for (llint x: S) cout << x << endl;
  return 0;
}
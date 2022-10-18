#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n);
  REP(i, n) scanf("%d", &a[i]);

  int m = min_element(a.begin(), a.end()) - a.begin();
  llint ret = 0;
  REP(i, n) {
    if ((a[i] - a[m]) % k) {
      printf("-1\n");
      return 0;
    }
    ret += (a[i] - a[m]) / k;
  }

  printf("%lld\n", ret);
  return 0;
}
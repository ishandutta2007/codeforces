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
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  REP(i, n) scanf("%d", &a[i]);

  vector<int> f(n + 1);
  f[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    f[i] = max(a[i] - f[i + 1], f[i + 1] - a[i]);
  }

  int sum = accumulate(a.begin(), a.end(), 0);
  int bob = (sum + f[0]) / 2;
  int alice = sum - bob;
  printf("%d %d\n", alice, bob);
  return 0;
}
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

const int MAX = 5000;

int f[MAX];

int maxdiv(int i) {
  for (int j = 2; j*j <= i; ++j)
    if (i % j == 0) return i/j;
  return 1;
}

int main(void) {
  FOR(i, 2, MAX) {
    f[i] = maxdiv(i);
    for (int j = 2; j < i-1; ++j)
      f[i] = min(f[i], f[j] + f[i-j]);
  }

  int n;
  scanf("%d", &n);
  int ans = maxdiv(n);
  for (int i = 2; i < MAX && i < n-1; ++i) {
    ans = min(ans, maxdiv(n-i) + f[i]);
  }

  printf("%d\n", ans);
  return 0;
}
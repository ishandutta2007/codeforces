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

  int rem = 240 - k;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (5*i <= rem) {
      rem -= 5*i;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
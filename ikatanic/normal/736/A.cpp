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
  llint n;
  scanf("%lld", &n);
  
  llint prev = 0;
  llint cur = 0;
  int ans = -1;
  while (cur + 1 <= n) {
    ans++;
    llint tmp = cur;
    cur = prev + cur + 1;
    prev = tmp;
  }

  printf("%d\n", ans);
  return 0;
}
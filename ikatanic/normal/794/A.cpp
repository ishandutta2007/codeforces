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
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int n;
  scanf("%d", &n);
  int ans = 0;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    if (b < x && x < c) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
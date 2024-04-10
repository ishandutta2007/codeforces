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

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, r;
    scanf("%d %d", &n, &r);
    --r;
    int sum = 0;
    REP(i, n-1) {
      int x;
      scanf("%d", &x); --x;
      sum += x;
    }

    sum %= n;
    int ans = (r - sum + n) % n;
    printf("%d\n", ans+1);
  }
  
  return 0;
}
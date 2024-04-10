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

const int MAX = 100010;
const int LIM = 60;

struct Pt {
  int x, y;
} a[MAX];

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

ldb f[LIM];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d %d", &a[i].x, &a[i].y);

  for (int i = 0; i < n; ++i)
    for (int d = 0; d < n-1 && d < LIM; ++d) {
      int j = (i + d + 1) % n;
      int dx = a[j].x - a[i].x;
      int dy = a[j].y - a[i].y;
      f[d] += (a[i].x*1LL*a[j].y - a[i].y*1LL*a[j].x);
      f[d] -= gcd(abs(dx), abs(dy));
    }

  ldb ans = 0;
  REP(d, LIM) {
    if (n < 60) {
      ldb A = (1LL<<(n-2-d)) - 1;
      ldb B = (1LL<<n) - 1 - n - n*(n-1)/2;
      ans += A*f[d] / B;
    } else
      ans += f[d] / (1LL<<(d+2));
  }

  ans /= 2;
  ans += 1;
  printf("%.10lf\n", (double)ans);
  return 0;
}
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

int a[555];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", &a[i]);
  sort(a, a + n);
  n = unique(a, a + n) - a;
  REP(i, n-2)
    if (a[i]+1 == a[i+1] && a[i]+2 == a[i+2]) {
      puts("YES");
      return 0;
    }
  puts("NO");
  return 0;
}
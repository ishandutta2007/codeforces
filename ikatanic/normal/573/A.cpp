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
  int n;
  scanf("%d", &n);
  int v = -1;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    while (x % 2 == 0) x /= 2;
    while (x % 3 == 0) x /= 3;
    if (i == 0) v = x;
    if (v != x) {
      puts("No");
      return 0;
    }
  }

  puts("Yes");
  return 0;
}
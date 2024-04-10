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
  puts("2000");
  for (int i = 1; i <= 1000; ++i)
    printf("%d %d %d %d\n", i, 1, i, 2);
  for (int i = 1000; i >= 1; --i)
    printf("%d %d %d %d\n", i, 1, i, 2);
  return 0;
}
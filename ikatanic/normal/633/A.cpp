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
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  for (int i = 0; i*a <= c; ++i)
    if ((c-i*a) % b == 0) {
      puts("Yes");
      return 0;
    }
  puts("No");
  return 0;
}
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

  if (n%2) {
    printf("%d\n", n/2);
  } else {
    int pw = 1;
    while (pw*2 <= n) pw *= 2;
    printf("%d\n", (n - pw)/2);
  }
  return 0;
}
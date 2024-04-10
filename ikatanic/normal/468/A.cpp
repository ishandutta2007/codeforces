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
  int n;
  scanf("%d", &n);
  
  if (n < 4) {
    puts("NO");
    return 0;
  }
  
  puts("YES");

  int ones = 0;
  while (n >= 6) {
    printf("%d - %d = %d\n", n, n-1, 1);
    n -= 2, ones++;
  }

  if (n == 5) {
    printf("5 + 1 = 6\n");
    printf("6 * 4 = 24\n");
    printf("3 - 2 = 1\n");
    ones++;
  } else {
    assert(n == 4);
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
    ones++;
  }
  
  REP(i, ones) printf("24 * 1 = 24\n");

  return 0;
}
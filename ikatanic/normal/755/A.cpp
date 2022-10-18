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

bool isprime(int x) {
  for (int j = 2; j*j <= x; ++j)
    if (x % j == 0) return false;
  return true;
}


int main(void) {
  int n;
  scanf("%d", &n);
  int m = 1;
  while (isprime(n*m+1)) m++;

  printf("%d\n", m);
  return 0;
}
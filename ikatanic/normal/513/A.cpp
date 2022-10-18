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
  int n1, n2, k1, k2;
  scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
  
  if (n1 > n2) puts("First"); else
    puts("Second");
  return 0;
}
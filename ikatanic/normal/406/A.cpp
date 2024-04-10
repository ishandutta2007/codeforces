#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int main(void) {
  int n;
  scanf("%d", &n);
  
  int ans = 0;
  REP(i, n) REP(j, n) {
    int x;
    scanf("%d", &x);
    if (i == j) ans ^= x;
  }
  
  int q;
  scanf("%d", &q);
  REP(i, q) {
    int tip;
    scanf("%d", &tip);
    if (tip == 3) {
      printf("%d", ans);
      continue;
    }
    int x;
    scanf("%d", &x); --x;
    ans ^= 1;
  }
  printf("\n");
  return 0;
}
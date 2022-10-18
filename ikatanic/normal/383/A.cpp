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
  
  int cntR = 0;
  llint ans = 0;
  REP(i, n) {
    int x;
    scanf("%d", &x);
    if (x == 1) cntR++; else
      ans += cntR;
  }
  printf("%I64d\n", ans);
  return 0;
}
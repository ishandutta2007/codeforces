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
  int N;
  scanf("%d", &N);
  int ret = 1e9;
  for (int i = 1; i <= N; ++i) {
    int r = (N + i - 1) / i;
    ret = min(ret, 2*(r + i));
  }
  printf("%d\n", ret);
  return 0;
}
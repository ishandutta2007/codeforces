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
  int N, U;
  scanf("%d %d", &N, &U);

  vector<int> E(N);
  REP(i, N) scanf("%d", &E[i]);

  int j = 0;
  double ret = -1;
  REP(i, N-2) {
    while (j+1 < N && E[j+1] - E[i] <= U) j++;

    if (i + 1 < j) {
      ret = max(ret, (E[j] - E[i+1]) * 1.0 / (E[j] - E[i]));
    }
  }

  printf("%.15lf\n", ret);

  return 0;
}
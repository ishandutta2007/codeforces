#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  map<int, int> M;

  REP(it, 2) {
    int N;
    scanf("%d", &N);

    REP(i, N) {
      int a, x;
      scanf("%d %d", &a, &x);
      M[a] = max(M[a], x);
    }
  }

  llint ret = 0;
  for (auto& p: M) ret += p.second;
  printf("%lld\n", ret);
  return 0;
}
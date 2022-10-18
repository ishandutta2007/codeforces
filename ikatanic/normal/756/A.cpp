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
  vector<int> p(n);
  REP(i, n) scanf("%d", &p[i]);
  REP(i, n) --p[i];

  vector<int> b(n);
  REP(i, n) scanf("%d", &b[i]);
  int parity = 0;
  REP(i, n) parity ^= b[i];
  
  vector<bool> bio(n, false);
  int cycles = 0;
  REP(i, n) {
    if (!bio[i]) {
      int x = i;
      while (!bio[x]) {
        bio[x] = true;
        x = p[x];
      }
      cycles++;
    }
  }

  int ans = (cycles == 1 ? 0 : cycles) + 1 - parity;
  printf("%d\n", ans);
  return 0;
}
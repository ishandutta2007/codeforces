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

const int MAX = 10100;

int dad[MAX];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) dad[i] = i;
  REP(i, n) {
    int p;
    scanf("%d", &p); --p;
    dad[findset(p)] = findset(i);
  }

  int ans = 0;
  REP(i, n) ans += findset(i) == i;
  printf("%d\n", ans);
  
  return 0;
}
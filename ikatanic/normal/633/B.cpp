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
  vector<int> ans;
  int m;
  scanf("%d", &m);

  int cur = 0, n = 1;
  while (cur <= m) {
    if (cur == m) ans.push_back(n);
    n++;
    int x = n;
    while (x%5 == 0) cur++, x /= 5;
  }
  
  printf("%d\n", (int)ans.size());
  for (int x: ans) printf("%d ", x);
  printf("\n");
  return 0;
}
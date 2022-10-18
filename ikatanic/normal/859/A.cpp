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
  int k;
  scanf("%d", &k);
  vector<int> a(k);
  REP(i, k) scanf("%d", &a[i]);

  int ret = max(0, *max_element(a.begin(), a.end()) - 25);
  printf("%d\n", ret);
  return 0;
}
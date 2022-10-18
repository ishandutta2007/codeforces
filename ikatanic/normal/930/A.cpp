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

  vector<int> p(n, -1);
  vector<int> d(n, 0);
  vector<int> s(n, 0);
  s[0]++;
  FOR(i, 1, n) {
    scanf("%d", &p[i]);
    --p[i];
    d[i] = d[p[i]] + 1;
    s[d[i]]++;
  }

  int ret = 0;
  REP(i, n) ret += s[i] % 2;
  printf("%d\n", ret);
  return 0;
}
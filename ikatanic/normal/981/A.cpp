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
  char a[55];
  scanf("%s", a);

  string s = a;
  int ret = 0;
  REP(j, (int)s.size()) REP(i, j+1) {
    string b = s.substr(i, j - i + 1);
    string c = b;
    reverse(c.begin(), c.end());
    if (b != c) ret = max(ret, j - i + 1);
  }
  printf("%d\n", ret);
  return 0;
}
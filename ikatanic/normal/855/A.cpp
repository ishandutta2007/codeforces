#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  int n;
  scanf("%d", &n);
  set<string> S;
  REP(i, n) {
    char buf[111];
    scanf("%s", buf);
    puts(S.count(buf) ? "YES" : "NO");
    S.insert(buf);
  }
  return 0;
}
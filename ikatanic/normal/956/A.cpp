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
  int N, M;
  scanf("%d %d", &N, &M);
  vector<llint> a;
  REP(i, N) {
    char s[55];
    scanf("%s", s);
    llint mask = 0;
    REP(j, M) {
      if (s[j] == '#') mask |= 1LL<<j;
    }
    a.push_back(mask);
  }

  sort(a.begin(), a.end());
  REP(i, N) REP(j, N) {
    if (a[i] != a[j] && (a[i] & a[j]) != 0) {
      puts("No");
      return 0;
    }
  }

  puts("Yes");
  return 0;
}
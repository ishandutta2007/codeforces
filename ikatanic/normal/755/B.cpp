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
  set<string> A;
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) {
    char buf[505];
    scanf("%s", buf);
    A.insert(buf);
  }

  int both = 0;
  REP(i, m) {
    char buf[505];
    scanf("%s", buf);
    if (A.count(buf)) both++;
  }

  n -= both, m -= both;
  bool turn = true;
  while (true) {
    if (turn) {
      if (both > 0) both--;
      else if (n > 0) n--;
      else break;
    } else {
      if (both > 0) both--;
      else if (m > 0) m--;
      else break;
    }
    turn ^= 1;
  }

  puts(turn ? "NO" : "YES");
  
  return 0;
}
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
  ios_base::sync_with_stdio(false);
  int n, ax, ay, bx, by, cx, cy;
  cin >> n;
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> cx >> cy;

  if ((bx < ax) == (cx < ax) && (by < ay) == (cy < ay)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
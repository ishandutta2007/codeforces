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

bool isprime(llint x) {
  for (llint j = 2; j * j <= x; ++j)
    if (x % j == 0) return false;
  return true;
}

int main(void) {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    llint a, b;
    cin >> a >> b;

    if (a - b == 1 && isprime(a + b)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
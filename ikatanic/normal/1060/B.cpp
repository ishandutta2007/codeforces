#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  ios_base::sync_with_stdio(false);

  string c;
  cin >> c;

  int n = c.size();

  int ret = 0;
  for (int s = 0; s < (1 << (n - 1)); ++s) {
    vector<int> carry(n + 1, 0);
    REP(i, n - 1) carry[i + 1] = (s >> i) & 1;

    bool ok = true;
    int digit_sum = 0;
    REP(i, n) {
      int need = c[n - i - 1] - '0' - carry[i];
      if (carry[i + 1]) need += 10;

      if (need < 0 || need > 18) {
        ok = false;
        break;
      }
      digit_sum += need;
    }

    if (ok) {
      ret = max(ret, digit_sum);
    }
  }

  cout << ret << "\n";
  return 0;
}
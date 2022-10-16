#include <bits/stdc++.h>
using namespace std;

int i, x, y, xx, yy, n, m;

int main() {
  ios_base::sync_with_stdio(0);

  cin >> x >> y >> xx >> yy;

  n = max(abs(x - xx) + 1, 2);
  m = max(abs(y - yy) + 1, 2);
  cout << 2 * n + 2 * m << '\n';

  return 0;
}
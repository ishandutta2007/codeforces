#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

using i64 = int64_t;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    i64 x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    i64 x = abs(x2 - x1), y = abs(y2 - y1);

    i64 ret = 0;
    if (x == 0)
      ret = y;
    else if (y == 0)
      ret = x;
    else
      ret = x + y + 2;

    cout << ret << '\n';
  }

  return 0;
}
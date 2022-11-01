#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
  using int64 = long long;
  int64 a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a * d == b * c) {
    cout << 0 << endl;
    return 0;
  }
  int64 det = abs(a * d - b * c);
  int64 div = 0;
  div = max(div, abs(a + b + c + d));
  div = max(div, abs(-a + b + c - d));
  div = max(div, abs(a + b - c - d));
  div = max(div, abs(a - b + c - d));
  printf("%.9lf\n", 1.0 * det / div);
}
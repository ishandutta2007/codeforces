#include <iostream>
#include <algorithm>
using namespace std;

int prec[] = {0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401};

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if ((a + 1) & a) {
      a |= a >> 1;
      a |= a >> 2;
      a |= a >> 4;
      a |= a >> 8;
      a |= a >> 16;
      cout << a << endl;
    } else {
      int t = 0;
      while (a > 0) {
        a /= 2;
        t += 1;
      }
      cout << prec[t - 1] << endl;
    }
  }
  return 0;
}
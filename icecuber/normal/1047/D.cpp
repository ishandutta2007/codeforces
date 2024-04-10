#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n < m) swap(n, m);
  int r;
  if (m == 1) {
    r = min(n%6, 6-n%6);
  } else if (m == 2) {
    if (n == 2) r = 4;
    else if (n == 3) r = 2;
    else if (n == 7) r = 2;
    else r = 0;
  } else if (n%2 == 0 || m%2 == 0) {
    r = 0;
  } else {
    r = 1;
  }
  cout << 1LL*n*m-r << endl;
}
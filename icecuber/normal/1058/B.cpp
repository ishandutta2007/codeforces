#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n, d, m;
  cin >> n >> d >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x+y >= d && x+y <= n*2-d && abs(x-y) <= d)
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
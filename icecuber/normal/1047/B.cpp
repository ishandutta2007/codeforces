#include <iostream>

using namespace std;

int main() {
  int ma = 0;
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    ma = max(ma, x+y);
  }
  cout << ma << endl;
}
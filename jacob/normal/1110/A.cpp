#include <iostream>
using namespace std;
int main() {
  int b, k;
  ios::sync_with_stdio(false);
  cin >> b >> k;
  int rem = 0;
  for (int i = 0; i < k;  ++i) {
    int d;
    cin >> d;
    rem = (rem * b + d) % 2;
  }
  cout << (rem == 0 ? "even" : "odd") << endl;
  return 0;
}
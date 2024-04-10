#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if ((n-2)%3) {
    cout << 1 << ' ' << 1 << ' ' << n-2 << endl;
  } else {
    cout << 2 << ' ' << 1 << ' ' << n-3 << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

int a[105], b[105];

int main() {
  int x, y;
  for (int i = 1; i <= 100; i++) {
    a[i] = i, b[i] = i << 7;
  }
  cout << '?';
  for (int i = 1; i <= 100; i++) {
    cout << ' ' << a[i];
  }
  cout << endl;
  cout.flush();
  cin >> x;
  cout << '?';
  for (int i = 1; i <= 100; i++) {
    cout << ' ' << b[i];
  }
  cout << endl;
  cin >> y;
  int v = (x ^ y) & ~127;
  cout << "! " << (v ^ y) << endl;
  return 0;
}
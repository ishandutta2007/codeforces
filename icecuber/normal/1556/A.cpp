#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int c, d;
    cin >> c >> d;
    if (c == 0 && d == 0) {
      cout << 0 << endl;
    } else if (c == d) {
      cout << 1 << endl;
    } else if (c%2 == d%2) {
      cout << 2 << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
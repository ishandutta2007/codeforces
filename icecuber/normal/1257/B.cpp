#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    cout << (x >= y || x >= 2 && y <= 3 || x >= 4 ? "YES" : "NO") << endl;
  }
}
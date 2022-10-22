#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    a += b;
    y -= x;
    if (y%a == 0) cout << y/a << endl;
    else cout << -1 << endl;
  }
}
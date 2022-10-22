#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    ll ans = abs(x1-x0)+abs(y1-y0);
    if (x1 != x0 && y1 != y0) ans += 2;
    cout << ans << endl;
  }
}
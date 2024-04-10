#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll m, d, w;
    cin >> m >> d >> w;
    w /= gcd(d-1,w);
    //if (m > 1e4) break;

    /*int ans = 0;
    for (int y = 0; y < min(m,d); y++) {
      ans += y/w;
      }*/
    m = min(m,d);
    ll ans = (m/w)*(m/w-1)/2*w+(m/w)*(m%w);
    cout << ans << endl;
  }
}
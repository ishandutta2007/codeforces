#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    ll pow10 = 10;
    for (; pow10-1 <= b; pow10 *= 10) {
      ans += a;
    }
    cout << ans << endl;
  }
}
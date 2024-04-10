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
    ll d = abs(b-a);
    ll ans = 0;
    for (ll i = 1; d > 0 || d%2; i++) {
      d -= i;
      ans++;
    }
    cout << ans << endl;
  }
}
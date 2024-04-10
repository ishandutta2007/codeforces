#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll ans = 1e9;
    auto add = [&](int i) {
      if (i <= k)
	ans = min(ans, n/i);
    };
    for (ll i = 1; i*i <= n; i++) {
      if (n%i == 0) {
	add(i);
	add(n/i);
      }
    }
    cout << ans << endl;
  }
}
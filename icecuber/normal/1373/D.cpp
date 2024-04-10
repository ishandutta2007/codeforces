#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i%2 == 0) {
	sum += a[i];
	a[i] *= -1;
      }
    }
    ll best[2] = {(ll)1e18,(ll)1e18};
    ll ans = 0, acc = 0;
    for (int i = 0; i < n; i++) {
      best[i%2] = min(best[i%2], acc);
      acc += a[i];
      ans = max(ans, acc-best[1-i%2]);
    }
    cout << sum+ans << endl;
  }
}
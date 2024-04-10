#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    sort(a.rbegin(), a.rend());
    int ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum >= (i+1)*x) ans = i+1;
    }
    cout << ans << endl;
  }
}
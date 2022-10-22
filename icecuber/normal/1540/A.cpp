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
    vector<ll> d(n);
    for (ll&v : d) cin >> v;
    sort(d.begin(), d.end());
    ll ans = d.back();
    ll acc = 0;
    for (int i = 0; i < n; i++) {
      ans -= d[i]*i-acc;
      acc += d[i];
    }
    cout << ans << endl;
  }
}
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
    vector<ll> c(n);
    for (ll&v : c) cin >> v;

    ll mi[2] = {c[0],c[1]};
    ll sum[2] = {c[0],c[1]};
    ll ans = 1e18;
    for (int k = 2; k <= n; k++) {
      ll ra = (k+1)/2, rb = k/2;
      ans = min(ans, mi[0]*(n-ra)+sum[0] + mi[1]*(n-rb)+sum[1]);
      if (k == n) break;
      mi[k%2] = min(mi[k%2], c[k]);
      sum[k%2] += c[k];
    }
    cout << ans << endl;
  }
}
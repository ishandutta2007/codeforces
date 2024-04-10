#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, u, v;
    cin >> n >> u >> v;
    vector<ll> a(n);
    for (ll&ai : a) cin >> ai;
    ll ma = 0;
    for (int i = 1; i < n; i++) {
      ma = max(ma, abs(a[i]-a[i-1]));
    }
    if (ma == 0) cout << min(u,v)+v << endl;
    else if (ma == 1) cout << min(u,v) << endl;
    else cout << 0 << endl;
  }
}
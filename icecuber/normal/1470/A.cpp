#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    vector<ll> c(m);
    for (int i = 0; i < n; i++) {
      cin >> k[i];
      k[i]--;
    }
    for (ll&v : c) cin >> v;

    sort(k.rbegin(), k.rend());
    ll ans = 0;
    for (int i = 0; i < n; i++)
      ans += c[k[i]];

    int p = 0;
    for (int i = 0; i < n; i++) {
      if (p < k[i]) {
        ans += c[p++] - c[k[i]];
      }
    }

    cout << ans << endl;
  }
}
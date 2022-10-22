#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll base = 0;
    for (ll&v : a) cin >> v, base += abs(v);
    int g = 0;
    for (int i = 0; i < m; i++) {
      int v;
      cin >> v;
      g = gcd(g,v);
    }
    vector<ll> mi(g, 1e9), ok(g);
    for (int i = 0; i < n; i++) { 
      ok[i%g] ^= (a[i] < 0);
      mi[i%g] = min(mi[i%g], abs(a[i]));
    }
    ll ans = -1e18;
    for (int k : {0,1}) {
      ll score = base;
      for (int i = 0; i < g; i++) {
        if (ok[i] == k) score -= 2*mi[i];
      }
      ans = max(ans, score);
    }
    cout << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll&v : a) cin >> v;
    for (ll&v : b) cin >> v;
    vector<ll> c[2];
    for (int i = 0; i < n; i++) {
      c[a[i]].push_back(b[i]);
    }
    int mi = min(c[0].size(), c[1].size());
    sort(c[0].rbegin(), c[0].rend());
    sort(c[1].rbegin(), c[1].rend());
    ll ans = 0;
    for (int k : {0,1}) 
      for (int i = 0; i < (int)c[k].size(); i++) 
        ans += c[k][i] * (1+(i<mi));
    if (c[0].size() == c[1].size())
      ans -= min(c[0][mi-1],c[1][mi-1]);
    cout << ans << endl;
  }
}
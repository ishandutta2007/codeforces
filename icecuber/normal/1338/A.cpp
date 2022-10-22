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
    ll ma = -1e15, need = 0;
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      ma = max(a, ma);
      need = max(need, ma-a);
    }
    ll ans = 0;
    while ((1ll<<ans)-1 < need) ans++;
    cout << ans << endl;
  }
}
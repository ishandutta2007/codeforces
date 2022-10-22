#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, ma, mb, n;
    cin >> a >> b >> ma >> mb >> n;
    ll ans = 1e18;
    for (int k : {0,1}) {
      ll na = max(a-n, ma);
      ll nb = max(b-(n-(a-na)), mb);
      ans = min(ans, na*nb);
      swap(a,b), swap(ma,mb);
    }
    cout << ans << endl;
  }
}
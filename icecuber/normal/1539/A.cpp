#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, x, t;
    cin >> n >> x >> t;
    ll ma = min(t/x, n);
    ll ans = ma*(ma-1)/2+(n-ma)*ma;
    cout << ans << endl;
  }
}
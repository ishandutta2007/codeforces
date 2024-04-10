#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;

    ll ans = 0;
    for(int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ans += x;
    }
    int mx = 0;
    for(int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ans += x;
      mx = max(mx, x);
    }
    ans -= mx;
    cout << ans << '\n';
  }

  return 0;
}
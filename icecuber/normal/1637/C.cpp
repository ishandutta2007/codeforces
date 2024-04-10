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
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int odds = 0, hasbig = 0, haseven = 0;
    for (int i = 1; i < n-1; i++) {
      odds += a[i]%2;
      haseven |= a[i]%2==0;
      hasbig |= a[i] >= 2;
    }
    if (!haseven && !(hasbig && odds > 1)) {
      cout << -1 << endl;
      continue;
    }
    ll ans = 0;
    for (int i = 1; i < n-1; i++) {
      ans += (a[i]+1)/2;
    }
    cout << ans << endl;
  }
}
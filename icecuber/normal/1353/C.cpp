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
    n /= 2;
    ll cnt = 8, ans = 0;
    for (int d = 1; d <= n; d++) {
      ans += cnt*d;
      cnt += 8;
    }
    cout << ans << endl;
  }
}
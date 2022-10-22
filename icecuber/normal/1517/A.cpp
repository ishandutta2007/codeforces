#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n%2050) {
      cout << -1 << endl;
      continue;
    }
    n /= 2050;
    int ans = 0;
    for (char c : to_string(n)) ans += (c-'0');
    cout << ans << endl;
  }
}
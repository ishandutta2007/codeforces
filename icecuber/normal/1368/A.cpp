#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, n;
    cin >> a >> b >> n;
    if (a < b) swap(a, b);
    int ans = 0;
    while (max(a,b) <= n) {
      b += a;
      ans++;
      swap(a,b);
    }
    cout << ans << endl;
  }
}
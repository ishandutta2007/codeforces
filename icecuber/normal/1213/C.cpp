#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    n /= m;
    while (n > 50) {
      ll f = (n-30)/10;
      for (int i = 1; i <= 10; i++) {
	ans += m*i%10*f;
      }
      n -= 10*f;
    }
    for (int i = 1; i <= n; i++) {
      ans += m*i%10;
    }
    cout << ans << endl;
  }
}
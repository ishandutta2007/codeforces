#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll g;
  cin >> g;
  for (int i = 1; i < n; i++) {
    ll a;
    cin >> a;
    g = __gcd(a,g);
  }
  ll ans = 0;
  for (ll d = 1; d*d <= g; d++) {
    if (g%d) continue;
    ans += (d*d!=g)+1;
  }
  cout << ans << endl;
}
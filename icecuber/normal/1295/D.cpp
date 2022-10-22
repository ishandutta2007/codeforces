#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, m;
    cin >> a >> m;
    ll q = m/__gcd(a, m);
    ll phi = q;
    for (ll i = 2; i*i <= q; i++) {
      if (q%i == 0) {
	phi = phi/i*(i-1);
	while (q%i == 0) q /= i;
      }
    }
    if (q > 1) phi = phi/q*(q-1);
    cout << phi << endl;
  }
}
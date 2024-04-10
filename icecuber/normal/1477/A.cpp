#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (ll&v : x) cin >> v;
    ll b = x[0];
    k -= b;
    for (ll&v : x) v -= b;
    ll g = 0;
    for (ll v : x) g = gcd(g,v);
    cout << ((g == 0 && k) || (g != 0 && k%g) ? "NO" : "YES") << endl;
  }
}
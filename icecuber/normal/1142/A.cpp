#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k, a, b;
  cin >> n >> k >> a >> b;
  ll mi = 1e18, ma = -1e18;
  for (int i = -1; i < 2; i += 2)
    for (int j = -1; j < 2; j += 2)
      for (ll x = n; x < n*2; x++) {
	ll l = x*k+a*i+b*j;
	ll y = k*n/__gcd(k*n, l);
	mi = min(mi, y);
	ma = max(ma, y);
      }
  cout << mi << ' ' << ma << endl;
}
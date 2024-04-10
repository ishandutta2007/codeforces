#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll x;
  cin >> x;
  ll best = x, a = 1, b = x;
  for (ll i = 1; i <= 1e6; i++) {
    if (x%i) continue;
    ll j = x/i;
    if (__gcd(i, j) != 1) continue;
    if (x%i == 0 && max(i, j) < best) {
      best = max(i, j);
      a = i;
      b = j;
    }
  }
  cout << a << ' ' << b << endl;
}
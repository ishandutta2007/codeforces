#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);

ll gcd(ll x, ll y) {
  while (x && y) {
    if (x > y) x %= y;
    else y %= x;
  }
  return x + y;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    ll d = gcd(p, q);
    p /= d;
    q /= d;

    if (p == 0) {
      if (x == 0) {
        cout << 0 << endl;
      } else {
        cout << -1 << endl;
      }
      continue;
    }
    if (p == q) {
      if (x == y) {
        cout << 0 << endl;
      } else {
        cout << -1 << endl;
      }
      continue;
    }

    ll left = 1, right = 1e9 + 5;
    while (left < right) {
      ll k = (left + right) >> 1;

      if (x > p * k) {
        left = k + 1;
        continue;
      }
      if (y > k * q) {
        left = k + 1;
        continue;
      }
      if (x + (k * q - y) >= p * k) {
        right = k;
      } else {
        left = k + 1;
      }
    }
    cout << left * q - y << endl;
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll x = a % c, y = b % c;
  if (x + y < c) {
    cout << a / c + b / c << " 0";
  } else {
    cout << a / c + b / c + 1 << ' ' << min((ll) c - x, (ll) c - y);
  }
  return 0;
}
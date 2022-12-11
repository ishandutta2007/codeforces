#include <bits/stdc++.h>
typedef long long ll;
ll a;
int main() {
  std::cin >> a;
  ll x = (2ll * a - 9 * (ll)1e18 % a * 9 % a - 1) % a;
  std::cout << 1 + x << ' ' << (ll)1e18 + x << '\n';
  return 0;
}
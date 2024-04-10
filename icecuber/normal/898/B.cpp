#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, a, b;
  cin >> n >> a >> b;
  for (ll x = 0; x*a <= n; x++) {
    ll y = n-x*a;
    if (y%b) continue;
    y /= b;
    cout << "YES" << endl;
    cout << x << ' ' << y << endl;
    return 0;
  }
  cout << "NO" << endl;
}
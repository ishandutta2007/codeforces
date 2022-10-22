#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll r;
  cin >> r;
  for (ll x = 1; ; x++) {
    ll y = r-x*x-x-1;
    if (y < 2*x) break;
    if (y%(2*x)) continue;
    cout << x << ' ' << y/(2*x) << endl;
    return 0;
  }
  cout << "NO" << endl;
}
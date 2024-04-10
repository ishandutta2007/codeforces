// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  vector<ll> c;
  for (int x=1; x<=10000; x++) {
    c.emplace_back(1ll*x*x*x);
  }

  int t;
  cin >> t;
  while (t--) {
    ll x;
    string k = "NO\n";
    cin >> x;
    for (ll a : c) {
      ll b = x - a;
      if (binary_search(begin(c), end(c), b)) {
        k = "YES\n";
      }
    }

    cout << k;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, k;
    cin >> a >> b >> k;
    ll g = __gcd(a, b);
    a /= g;
    b /= g;
    if (a < b) swap(a, b);
    if (a == 1) {
      cout << "OBEY" << endl;
      continue;
    }
    assert(a > b);
    cout << ((a+b-2)/b < k ? "OBEY" : "REBEL") << endl;
  }
}
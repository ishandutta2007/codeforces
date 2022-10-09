// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    ll sol = 0;
    map<pair<int, int>, int> mp;

    for (int i=0; i<n; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;

      int x = c-a, y = d-b;
      int g = gcd(abs(x), abs(y));
      x /= g;
      y /= g;

      sol += mp[{-x, -y}];
      mp[{x, y}]++;
    }

    cout << sol << '\n';
  }
}
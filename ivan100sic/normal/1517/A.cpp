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
    ll x;
    cin >> x;
    if (x % 2050) {
      cout << "-1\n";
    } else {
      x /= 2050;
      ll z = 0;
      while (x > 0) {
        z += x % 10;
        x /= 10;
      }
      cout << z << '\n';
    }
  }
}
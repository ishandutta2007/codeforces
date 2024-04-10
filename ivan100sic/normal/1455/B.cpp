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
    ll y = 0, i = 1;
    for (;; i++) {
      y += i;
      if (y >= x) {
        break;
      }
    }

    if (y == x) {
      cout << i << '\n';
    } else if (y == x+1) {
      cout << i+1 << '\n';
    } else {
      cout << i << '\n';
    }
  }
}
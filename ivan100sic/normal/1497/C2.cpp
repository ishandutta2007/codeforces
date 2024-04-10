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
    ll n, k;
    cin >> n >> k;
    for (ll i=0; i<k-3; i++) {
      cout << "1 ";
    }

    n -= k-3;
    if (n % 2) {
      cout << "1 " << n/2 << ' ' << n/2 << '\n';
    } else if (n % 4 == 2) {
      cout << "2 " << n/2-1 << ' ' << n/2-1 << '\n';
    } else {
      cout << n/4 << ' ' << n/4 << ' ' << n/2 << '\n';
    }
  }
}
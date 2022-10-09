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
    ll n;
    cin >> n;
    ll x = round(sqrt(n / 2.0));
    if (2*x*x == n) {
      cout << "YES\n";
    } else {
      x = round(sqrt(n / 4.0));
      if (4*x*x == n) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
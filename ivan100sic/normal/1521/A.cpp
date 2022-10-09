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
    ll a, b;
    cin >> a >> b;
    if (b == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n" << a*b << ' ' << a << ' ' << a*b + a << '\n';
    }
  }
}
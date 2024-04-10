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
    ll p, a, b, c;
    cin >> p >> a >> b >> c;
    ll pa = (a - p % a) % a;
    ll pb = (b - p % b) % b;
    ll pc = (c - p % c) % c;

    cout << min({pa, pb, pc}) << '\n';
  }
}
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
    ll r, b, d;
    cin >> r >> b >> d;

    cout << (min(r, b) * d >= abs(r - b) ? "YES\n" : "NO\n");
  }
}
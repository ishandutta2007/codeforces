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
    ll c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    ll a1, a2, a3, a4, a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;

    bool ok = 1;

    if (a3 > c3 || a1 > c1 || a2 > c2) {
      ok = 0;
    } else {
      c1 -= a1;
      c2 -= a2;
      c3 -= a3;
    }

    ll d = min(c1, a4);
    c1 -= d;
    a4 -= d;

    d = min(c2, a5);
    c2 -= d;
    a5 -= d;

    c3 -= a4+a5;

    if (c3 < 0) {
      ok = 0;
    }

    cout << (ok ? "YES\n" : "NO\n");

  }
}
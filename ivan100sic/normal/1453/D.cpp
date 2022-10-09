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
    ll w;
    cin >> w;
    basic_string<int> s;
    if (w % 2) {
      cout << "-1\n";
      continue;
    }

    w -= 2;

    while (w > 0) {
      ll l=1, q=2;
      while (1) {
        ll t = 2*q + 2;
        if (t <= w) {
          l++;
          q = t;
        } else {
          break;
        }
      }

      s += 1;
      s += basic_string<int>(l-1, 0);
      w -= q;
    }

    s += 1;

    cout << s.size() << '\n';
    for (int x : s) cout << x << ' ';
    cout << '\n';
  }
}
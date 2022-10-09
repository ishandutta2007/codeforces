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
    ll w, h, n;
    cin >> w >> h >> n;
    ll z = 1;
    while (w % 2 == 0) {
      w /= 2;
      z *= 2;
    }

    while (h % 2 == 0) {
      h /= 2;
      z *= 2;
    }

    cout << (z >= n ? "YES\n" : "NO\n");
  }
}
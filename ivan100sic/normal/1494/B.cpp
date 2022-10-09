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
    int n, u, r, d, l;
    cin >> n >> u >> r >> d >> l;

    string s = "NO\n";

    for (int mask=0; mask<16; mask++) {
      auto bs = bitset<4>(mask);
      int ul = bs[0], ur = bs[1], dl = bs[2], dr = bs[3];

      int u2 = u - ul - ur;
      int r2 = r - ur - dr;
      int d2 = d - dl - dr;
      int l2 = l - ul - dl;

      if (min({u2, r2, d2, l2}) >= 0 && max({u2, r2, d2, l2}) <= n-2) {
        s = "YES\n";
      }
    }

    cout << s;
  }
}
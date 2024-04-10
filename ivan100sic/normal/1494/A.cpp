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
    string s;
    cin >> s;
    int n = s.size(), z = 0;

    for (int mask=0; mask<8; mask++) {
      int v = 0, k = 1;
      for (int i=0; i<n; i++) {
        int d = (mask >> (s[i] - 'A')) & 1;
        d = 2*d-1;
        v += d;
        if (v < 0) {
          k = 0;
        }
      }
      k &= v == 0;
      if (k) {
        z = 1;
      }
    }

    cout << (z ? "YES\n" : "NO\n");
  }
}
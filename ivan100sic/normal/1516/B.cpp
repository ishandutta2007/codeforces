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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    int z = accumulate(begin(a), end(a), 0, bit_xor<int>());
    if (z == 0) {
      cout << "YES\n";
    } else {
      int e = 0, r = 0;
      for (int x : a) {
        r ^= x;
        if (e < 2 && r == z) {
          e++;
          r = 0;
        }
      }

      cout << (e == 2 ? "YES\n" : "NO\n");
    }
  }
}
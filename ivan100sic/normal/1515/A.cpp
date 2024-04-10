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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    int acc = accumulate(begin(a), end(a), 0);
    if (acc == x) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      if (acc > x) {
        int z = 0;
        for (int i=0; i<n; i++) {
          z += a[i];
          if (z == x) {
            swap(a[i], a[i+1]);
            break;
          }
        }
      }

      for (int x : a) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}
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
    int n, z=0;
    cin >> n;
    map<int, int> a;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      z = max(z, ++a[x]);
    }
    cout << max(n%2, 2*z-n) << '\n';
  }
}
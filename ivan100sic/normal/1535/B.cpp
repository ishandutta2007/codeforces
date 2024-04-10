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
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(begin(a), end(a), [](int x, int y) { return x % 2 < y % 2; });
    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        z += gcd(a[i], 2*a[j]) > 1;
      }
    }
    cout << z << '\n';
  }
}
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
    vector<ll> a(n), z(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=n-1; i>=0; i--) {
      if (i + a[i] < n) {
        z[i] = a[i] + z[i + a[i]];
      } else {
        z[i] = a[i];
      }
    }

    cout << *max_element(begin(z), end(z)) << '\n';
  }
}
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
    vector<int> a(n), b;
    for (int& x : a) cin >> x;
    sort(begin(a), end(a));
    for (int i=0; i<n; i++) {
      if (i == 0 || a[i] != a[i-1]) {
        cout << a[i] << ' ';
      } else {
        b.push_back(a[i]);
      }
    }

    for (int x : b) cout << x << ' ';
    cout << '\n';
  }
}
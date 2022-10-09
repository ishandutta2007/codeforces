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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    while (1) {
      sort(begin(a), end(a));
      if (a[n-1] <= d) {
        cout << "YES\n";
        break;
      }
      int x = a[0] + a[1];
      if (x >= a[n-1]) {
        // kraj
        cout << "NO\n";
        break;
      }
      a[n-1] = x;
    }
  }
}
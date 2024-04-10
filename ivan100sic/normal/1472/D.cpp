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
    ll x=0, y=0;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    sort(begin(a), end(a), greater<int>());

    for (int i=0; i<n; i++) {
      if (i % 2 == 0) {
        if (a[i] % 2 == 0) x += a[i];
      } else {
        if (a[i] % 2 == 1) y += a[i];
      }
    }

    if (x > y) {
      cout << "Alice\n";
    } else if (x < y) {
      cout << "Bob\n";
    } else {
      cout << "Tie\n";
    }
  }
}
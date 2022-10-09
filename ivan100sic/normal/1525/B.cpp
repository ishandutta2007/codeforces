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
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    int z = 0;
    if (is_sorted(begin(a), end(a))) {
      z = 0;
    } else if (a[0] == 1 || a[n-1] == n) {
      z = 1;
    } else {
      z = 2;
      if (a[n-1] == 1 && a[0] == n) {
        z = 3;
      }
    }

    cout << z << '\n';
  }
}
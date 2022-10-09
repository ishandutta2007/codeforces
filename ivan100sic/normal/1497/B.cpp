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
    int n, m, sol = 0;
    cin >> n >> m;
    vector<int> a(m, 0);
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      a[x % m]++;
    }

    sol += !!a[0];
    if (m % 2 == 0) {
      sol += !!a[m/2];
    }

    for (int i=1; 2*i<m; i++) {
      int x = a[i], y = a[m-i];

      if (x+y) {
        sol += max(1, abs(x-y));
      }
    }

    cout << sol << '\n';
  }
}
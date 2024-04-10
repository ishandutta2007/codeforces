// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[200005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    ll z = 0, sol = 1e18;

    for (int i=1; i<n; i++) {
      z += abs(a[i-1] - a[i]);
    }

    sol = min(sol, z - abs(a[0] - a[1]));
    sol = min(sol, z - abs(a[n-2] - a[n-1]));

    for (int i=1; i<n-1; i++) {
      sol = min(sol, z - abs(a[i] - a[i-1]) - abs(a[i] - a[i+1]) + abs(a[i-1] - a[i+1]));
    }

    cout << sol << '\n';
  }
}
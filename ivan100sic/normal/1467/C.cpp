// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll sol = -1e18;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  ll z = 0;
  vector<vector<ll>> b(3);
  for (int i=0; i<3; i++) {
    b[i].resize(a[i]);
    for (int j=0; j<a[i]; j++) {
      cin >> b[i][j];
      z += b[i][j];
    }
    sort(begin(b[i]), end(b[i]));
  }

  // najmanja dva
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (i != j) {
        sol = max(sol, z - 2*(b[i][0]+b[j][0]));
      }
    }
  }

  // jedan ceo red
  for (int i=0; i<3; i++) {
    sol = max(sol, z - 2*accumulate(begin(b[i]), end(b[i]), 0ll));
  }

  cout << sol << "\n";
}
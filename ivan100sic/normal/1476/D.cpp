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
    string s;
    cin >> n >> s;
    vector<int> plus_l(n), plus_r(n), minus_l(n), minus_r(n);
    for (int i=0; i<n; i++) {
      if (s[i] == 'L') {
        minus_l[i] = 1 + (i ? minus_r[i-1] : 0);
      } else {
        minus_r[i] = 1 + (i ? minus_l[i-1] : 0);
      }
    }

    for (int i=n-1; i>=0; i--) {
      if (s[i] == 'L') {
        plus_l[i] = 1 + (i+1 < n ? plus_r[i+1] : 0);
      } else {
        plus_r[i] = 1 + (i+1 < n ? plus_l[i+1] : 0);
      }
    }

    for (int i=0; i<=n; i++) {
      int sol = 1;
      if (i) {
        sol += minus_l[i-1];
      }

      if (i < n) {
        sol += plus_r[i];
      }

      cout << sol << " \n"[i == n];
    }
  }
}
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool ok = 1;
    for (int i=0; i<k; i++) {
      if (s[i] != s[n-1-i]) {
        ok = 0;
      }
    }

    if (2*k == n) {
      ok = 0;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
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
    int n, f = 0;
    string s;
    cin >> n >> s;
    for (int i=0; i<=4 && !f; i++) {
      for (int j=max(i, n-4); j<=n; j++) {
        if (s.substr(0, i) + s.substr(j) == "2020") {
          cout << "YES\n";
          f = 1;
          break;
        }
      }
    }

    if (!f) {
      cout << "NO\n";
    }
  }
}
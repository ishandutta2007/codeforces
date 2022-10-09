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
    bool ok = 1;
    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        for (int k=j+1; k<n; k++) {
          if (s[i] != s[j] && s[i] == s[k]) {
            ok = 0;
          }
        }
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
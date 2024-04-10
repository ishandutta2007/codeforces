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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    int f = 0;

    for (int i=0; i<n; i++) {
      for (int j=i+1; j<n; j++) {
        if (a[i][j] == a[j][i]) {
          // op op
          cout << "YES\n";
          for (int k=0; k<=m; k++) {
            cout << (k%2 ? i : j) + 1 << " \n"[k == m];
          }

          f = 1;
          break;
        }
      }

      if (f) {
        break;
      }
    }

    if (!f && m % 2 == 1) {
      // neparno?
      cout << "YES\n";
      for (int k=0; k<=m; k++) {
        cout << k%2 + 1 << " \n"[k == m];
      }

      f = 1;
    }

    if (!f) {
      // dva uzastopna ista
      for (int i=0; i<n; i++) {
        // izlazni
        map<char, int> izl;
        for (int j=0; j<n; j++) {
          if (j == i) continue;
          izl[a[i][j]] = j;
        }

        if (izl.size() == 2) {
          int x = izl['a'];
          int y = izl['b'];
          int z = i;
          cout << "YES\n";

          for (int i=0; i<=m/2; i++) {
            int d = m/2 - i;
            cout << (d%2 ? x : z) + 1 << " \n"[d > 0];
          }

          for (int i=m/2+1; i<=m; i++) {
            int d = i - m/2;
            cout << (d%2 ? y : z) + 1 << " \n"[d > 0];
          }

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
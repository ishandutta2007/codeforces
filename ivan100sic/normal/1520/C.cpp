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
    if (n == 1) {
      cout << "1\n";
    } else if (n == 2) {
      cout << "-1\n";
    } else if (n == 3) {
      cout << "2 9 7\n4 6 3\n1 8 5\n";
    } else {
      vector<vector<int>> a(n, vector<int>(n));
      int k = 0;
      for (int p : {0, 1}) {
        for (int q : {0, 1}) {
          for (int i=p; i<n; i+=2) {
            for (int j=q; j<n; j+=2) {
              a[i][j] = ++k;
            }
          }
        }
      }

      for (auto v : a) {
        for (int x : v) {
          cout << x << ' ';
        }
        cout << '\n';
      }
    }
  }
}
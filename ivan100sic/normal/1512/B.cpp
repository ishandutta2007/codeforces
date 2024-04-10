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
    vector<string> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    int p=-1, q=-1, r=-1, s=-1;
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        if (a[i][j] == '*') {
          if (p == -1) {
            p = i;
            q = j;
          } else {
            r = i;
            s = j;
          }
        }
      }
    }

    if (p == r) {
      int y = (p+1) % n;
      a[y][q] = a[y][s] = '*';
    } else if (q == s) {
      int x = (q+1) % n;
      a[p][x] = a[r][x] = '*';
    } else {
      a[p][s] = a[r][q] = '*';
    }

    for (int i=0; i<n; i++) {
      cout << a[i] << '\n';
    }
  }
}
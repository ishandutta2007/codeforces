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
    int n, ok = 0;
    cin >> n;
    vector<int> b(n+2);
    for (int i=0; i<n+2; i++) {
      cin >> b[i];
    }
    sort(begin(b), end(b));
    ll z = accumulate(begin(b), end(b), 0ll);
    for (int i=n; i<n+2 && !ok; i++) {
      for (int j=0; j<n+2; j++) {
        if (i != j && b[i] == z - b[i] - b[j]) {
          ok = 1;
          for (int k=0; k<n+2; k++) {
            if (k != i && k != j) {
              cout << b[k] << ' ';
            }
          }
          cout << '\n';
          break;
        }
      }
    }

    if (!ok) {
      cout << "-1\n";
    }
  }
}
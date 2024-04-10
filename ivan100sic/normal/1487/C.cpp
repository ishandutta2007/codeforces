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
    if (n % 2) {
      for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
          cout << (j-i <= n/2 ? 1 : -1) << ' ';
        }
      }
      cout << '\n';
    } else {
      for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
          if (j-i == n/2) {
            cout << "0 ";
          } else {
            cout << (j-i < n/2 ? 1 : -1) << ' ';
          }
        }
      }
      cout << '\n';
    }
  }
}
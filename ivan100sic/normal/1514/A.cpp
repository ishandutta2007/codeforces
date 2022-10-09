// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int sq[10005];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  for (int i=1; i<=100; i++) {
    sq[i*i] = 1;
  }

  int t;
  cin >> t;
  while (t--) {
    int n, k = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      if (!sq[x]) {
        k = 1;
      }
    }

    cout << (k ? "YES\n" : "NO\n");
  }
}
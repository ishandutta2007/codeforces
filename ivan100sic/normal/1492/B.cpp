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
    vector<int> a(n), b(n+1), p(n+1);

    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    b[0] = -1;
    for (int i=0; i<n; i++) {
      b[i+1] = max(b[i], a[i]);
      p[a[i]] = i;
    }

    int r = n;

    while (r > 0) {
      int l = p[b[r]];
      for (int i=l; i<r; i++) {
        cout << a[i] << ' ';
      }
      r = l;
    }

    cout << '\n';
  }
}
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
    vector<int> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    sort(begin(a), end(a));

    if (k == 0) {
      cout << n << '\n';
      continue;
    }

    if (a[n-1] == n-1) {
      // 0 .. n-1
      cout << n + k << '\n';
    } else {
      int mex = n;
      for (int i=0; i<n; i++) {
        if (!binary_search(begin(a), end(a), i)) {
          mex = i;
          break;
        }
      }

      int hi = *max_element(begin(a), end(a));

      int w = (mex + hi + 1) / 2;

      if (binary_search(begin(a), end(a), w)) {
        cout << n << '\n';
      } else {
        cout << n+1 << '\n';
      }
    }
  }
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll bk2(ll x) {
  return x*(x-1) / 2;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, m=3, k=2;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(begin(a), end(a));

    if (m == 1) {
      cout << n << '\n';
      continue;
    }

    ll sol = 0;

    int r = 0;
    for (int l=0; l<n; l++) {
      while (r+1 < n && a[r+1] - a[l] <= k) {
        r++;
      }

      sol += bk2(r-l);
    }

    cout << sol << '\n';
  }
}
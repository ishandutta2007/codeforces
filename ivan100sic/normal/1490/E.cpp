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
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }

    sort(begin(a), end(a));

    auto win = [&](int p) {
      ll z = 0;
      int q = p+1;
      for (int i=0; i<=p; i++) {
        z += a[i].first;
      }

      while (q < n && z >= a[q].first) {
        z += a[q].first;
        q++;
      }

      return q == n;
    };

    int l = 0, r = n-2, o = n-1;
    while (l <= r) {
      int m = (l+r) / 2;
      if (win(m)) {
        o = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    basic_string<int> s;
    for (int i=o; i<n; i++) {
      s += a[i].second;
    }

    sort(begin(s), end(s));
    cout << s.size() << '\n';
    for (int x : s) cout << x+1 << ' ';
    cout << '\n';
  }
}
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
    for (int i=0; i<n; i++) cin >> a[i].first;
    for (int i=0; i<n; i++) cin >> a[i].second;

    for (int i=0; i<n; i++) {
      auto [r, c] = a[i];
      a[i] = {r-c+1, c};
    }

    sort(begin(a), end(a), [](auto a, auto b) { return a.first + a.second < b.first + b.second; });

    if (a[0] != pair(1, 1)) {
      a.insert(a.begin(), {1, 1});
    }

    int z = 0;
    for (int i=1; i<(int)a.size(); i++) {
      auto [x1, y1] = a[i-1];
      auto [x2, y2] = a[i];
      if (x1 == x2) {
        if (x1 % 2 == 1) {
          z += y2 - y1;
        }
      } else {
        z += (x2-1)/2 - (x1-1)/2;
      }
    }

    cout << z << '\n';
  }
}
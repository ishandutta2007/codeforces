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
    vector<vector<ll>> a(n), z(n);
    vector<int> u(n);
    for (int& x : u) cin >> x;
    for (int i=0; i<n; i++) {
      int x;
      cin >> x;
      a[u[i] - 1].push_back(x);
    }

    sort(begin(a), end(a), [](const auto& v, const auto& w) { return v.size() > w.size(); });

    for (int i=0; i<n; i++) {
      sort(begin(a[i]), end(a[i]), greater<ll>());
      z[i].resize(a[i].size() + 1);
      partial_sum(begin(a[i]), end(a[i]), begin(z[i]) + 1);
    }

    for (int k=1; k<=n; k++) {
      ll w = 0;
      for (int i=0; i<n; i++) {
        if ((int)a[i].size() < k) {
          break;
        }
        w += z[i][a[i].size() / k * k];
      }

      cout << w << " \n"[k == n];
    }
  }
}
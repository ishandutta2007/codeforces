// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void set_clamped(int& x, int low, int hi, int val) {
  if (val < low || val > hi) {
    throw 1;
  }
  x = val;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int& x : c) cin >> x;

    vector<int> sol(m);

    map<int, vector<int>> to_paint;
    map<int, int> has_equal;
    for (int i=0; i<n; i++) {
      if (a[i] != b[i]) {
        to_paint[b[i]].push_back(i);
      } else {
        has_equal[a[i]] = i;
      }
    }

    int waste = -1, ok = 1;

    for (int i=m-1; i>=0; i--) {
      int x = c[i];
      if (to_paint[x].size()) {
        int j = to_paint[x].back();
        to_paint[x].pop_back();
        set_clamped(sol[i], 0, n-1, j);
        waste = j;
      } else if (has_equal.count(x)) {
        set_clamped(sol[i], 0, n-1, has_equal[x]);
        waste = has_equal[x];
      } else if (waste != -1) {
        set_clamped(sol[i], 0, n-1, waste);
      } else {
        ok = 0;
        break;
      }
    }

    for (auto [k, v] : to_paint) {
      if (v.size()) {
        ok = 0;
        break;
      }
    }

    if (ok) {
      cout << "YES\n";
      for (int i=0; i<m; i++) {
        int w = sol[i] + 1;
        if (w < 1 || w > n) {
          throw 2;
        }

        cout << w << " \n"[i == m-1];
      }
    } else {
      cout << "NO\n";
    }
  }
}
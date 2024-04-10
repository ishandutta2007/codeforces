// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

map<char, pair<int, int>> mp = {
  {'L', {-1, 0}},
  {'R', {1, 0}},
  {'U', {0, 1}},
  {'D', {0, -1}}
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int f = 0;
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, int>> a(n), q(n+1);
    for (int i=0; i<n; i++) {
      a[i] = mp[s[i]];
    }

    for (int i=0; i<n; i++) {
      q[i+1].first = q[i].first + a[i].first;
      q[i+1].second = q[i].second + a[i].second;
    }

    for (int i=1; i<=n; i++) {
      auto [xb, yb] = q[i];
      int x = 0, y = 0;
      for (int i=0; i<n; i++) {
        auto [dx, dy] = a[i];
        if (x+dx == xb && y+dy == yb) {
          // nista
        } else {
          x += dx;
          y += dy;
        }
      }

      if (x == 0 && y == 0) {
        cout << xb << ' ' << yb << '\n';
        f = 1;
        break;
      }
    }

    if (!f) {
      cout << "0 0\n";
    }
  }
}
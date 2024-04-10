#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define int long long

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> tip(n);
    bool issm = true;
    for (int &el : tip) {
      cin >> el;
      issm &= tip[0] == el;
    }
    if (issm) {
      cout << 1 << '\n';
      for (int i = 0; i < n; ++i)
        cout << 1 << ' ';
      cout << '\n';
      continue;
    }
    int ind = 0;
    for (int i = 0; i < n; ++i) {
      int j = (i + 1) % n;
      if (tip[i] == tip[j]) {
        ind = j;
        break;
      }
    }
    vector<int> color(n);
    int clr = 0;
    for (int i = 0; i < n; ++i) {
      int j = (ind + i) % n;
      color[j] = clr;
      clr = 1 - clr;
    }
    int pr = (ind - 1 + n) % n;
    if (color[pr] != color[ind] || tip[pr] == tip[ind]) {
      cout << 2 << '\n';
      for (int c : color)
        cout << c + 1 << ' ';
      cout << '\n';
    } else {
      color[pr] = 2;
      cout << 3 << '\n';
      for (int c : color)
        cout << c + 1 << ' ';
      cout << '\n';
    }
  }
  return 0;
}
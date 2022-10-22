#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for (auto&[x,y] : p) cin >> x >> y;
    sort(p.begin(), p.end());
    string ans;
    int cx = 0, cy = 0, ok = 1;
    for (auto [x,y] : p) {
      if (x < cx || y < cy) {
	cout << "NO" << endl;
	ok = 0;
	break;
      }
      while (cx < x) cx++, ans += 'R';
      while (cy < y) cy++, ans += 'U';
    }
    if (ok) {
      cout << "YES" << endl;
      cout << ans << endl;
    }
  }
}
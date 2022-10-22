#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string p, h;
    cin >> p >> h;
    sort(p.begin(), p.end());
    int ok = 0;
    for (int i = 0; i+p.size() <= h.size(); i++) {
      string s = h.substr(i, p.size());
      sort(s.begin(), s.end());
      if (s == p) ok = 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}
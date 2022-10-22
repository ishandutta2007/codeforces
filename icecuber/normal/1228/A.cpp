#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int l, r;
  cin >> l >> r;
  for (int x = l; x <= r; x++) {
    string s = to_string(x);
    sort(s.begin(), s.end());
    if (unique(s.begin(), s.end()) == s.end()) {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
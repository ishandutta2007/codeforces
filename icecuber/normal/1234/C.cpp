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
    string s[2];
    cin >> s[0] >> s[1];
    int ok[2] = {1,0};
    for (int i = 0; i < n; i++) {
      int x = s[0][i] <= '2', y = s[1][i] <= '2';
      if (!x && !y)
	swap(ok[0],ok[1]);
      else {
	if (!x) ok[0] &= 0;
	if (!y) ok[1] &= 0;
      }
    }
    cout << (ok[1] ? "YES" : "NO") << '\n';
  }
}
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
    string s;
    cin >> s;
    int ans = n-1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '<') ans = min(ans, n-1-i);
      if (s[i] == '>') ans = min(ans, i);
    }
    cout << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int it = 0; it < m; it++) {
      string nxt = s;
      for (int i = 0; i < n; i++) {
        if ((i && s[i-1] == '1') + (i+1 < n && s[i+1] == '1') == 1)
          nxt[i] = '1';
      }
      if (nxt == s) break;
      s = nxt;
    }
    cout << s << endl;
  }
}
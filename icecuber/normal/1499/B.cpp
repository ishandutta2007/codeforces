#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ok = 0;
    for (int m = 0; m <= s.size(); m++) {
      int last = -10, cok = 1;
      for (int i = 0; i < s.size(); i++) {
        if (s[i]-'0' != (i>=m)) {
          if (last == i-1) cok = 0;
          last = i;
        }
      }
      ok |= cok;
    }
    cout << (ok ? "YES" : " NO") << endl;
  }
}
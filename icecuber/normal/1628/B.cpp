#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    set<string> has;
    int ok = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      string r = s;
      reverse(r.begin(), r.end());
      has.insert(s);
      if (has.count(r)) ok = 1;
      if (s.size() == 2) {
        for (char c = 'a'; c <= 'z'; c++) {
          string cat = r+string(1,c);
          if (has.count(cat)) ok = 1;
        }
      } else if (s.size() == 3) {
        if (has.count(r.substr(0,2))) ok = 1;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
}
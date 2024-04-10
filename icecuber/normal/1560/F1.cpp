#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ok(string s, int d) {
  sort(s.begin(), s.end());
  return unique(s.begin(), s.end())-s.begin() <= d;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    int d;
    cin >> s >> d;
    if (ok(s, d)) {
      cout << s << endl;
      continue;
    }
    for (int i = (int)s.size()-1; i >= 0; i--) {
      for (s[i]++; s[i] <= '9'; s[i]++) {
        for (char j = '0'; j <= '9'; j++) {
          for (int k = i+1; k < (int)s.size(); k++) s[k] = j;
          if (ok(s, d)) {
            cout << s << endl;
            goto next;
          }
        }
      }
      s[i] = '0';
    }
next:;
  }
}
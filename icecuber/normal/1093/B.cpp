#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s[s.size()-1]) cout << -1 << endl;
    else cout << s << endl;
  }
}
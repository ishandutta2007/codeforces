#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  string ans;
  int ones = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    char c = s[i];
    if (c == '1') ones++;
    else if (c == '0') ans += '0';
    else if (c == '2') {
      ans += c;
    } else assert(0);
  }
  string ans2;
  for (char c : ans) {
    if (c == '2') {
      while (ones) ans2 += '1', ones--;
    }
    ans2 += c;
  }
  while (ones) ans2 += '1', ones--;
  cout << ans2 << endl;
}
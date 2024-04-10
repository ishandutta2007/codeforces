#include <bits/stdc++.h>
using namespace std;

bool isPalindrom(string x) {
  auto y = x;
  reverse(y.begin(), y.end());
  return x == y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    for (int length = s.size(); length >= 2; length--) {
      for (int start = 0; start + length <= (int)s.size(); start++) {
        string x = s.substr(start, length);
        if (!isPalindrom(x)) {
          cout << length << '\n';
          return 0;
        }
      }
    }
    cout << 0 << '\n';
}
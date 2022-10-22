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
    if (s[0] == '0' || s[n-1] == '0' || count(s.begin(), s.end(), '1')%2) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
    string a = "(", b = "(";
    int x = 1, y = 1;
    for (int i = 1; i < n-1; i++) {
      if (s[i] == '0') {
        if (x == y) {
          a += '(';
          b += ')';
          x++, y--;
        } else {
          assert(x-y == 2);
          a += ')';
          b += '(';
          x--, y++;
        }
      } else {
        if (x+y == 2) {
          a += '(';
          b += '(';
          x++, y++;
        } else {
          assert(x+y == 4);
          a += ')';
          b += ')';
          x--, y--;
        }
      }
    }
    a += ')';
    b += ')';
    cout << a << endl;
    cout << b << endl;
  }
}
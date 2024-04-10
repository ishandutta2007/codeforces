// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int a, b, ok = 1;
    cin >> a >> b;
    string s;
    cin >> s;

    int n = s.size();
    // obavezne zamene
    for (int i=0, j=n-1; i<j; i++, j--) {
      if ((s[i] == '?') != (s[j] == '?')) {
        s[i] = s[j] = min(s[i], s[j]);
      }
    }

    for (char c : s) {
      if (c == '0') {
        a--;
      } else if (c == '1') {
        b--;
      }
    }

    if (n % 2 == 1) {
      if (a % 2) {
        if (s[n/2] == '?') {
          s[n/2] = '0';
          a--;
        } else {
          ok = 0;
        }
      } else if (b % 2) {
        if (s[n/2] == '?') {
          s[n/2] = '1';
          b--;
        } else {
          ok = 0;
        }
      }
    }

    for (int i=0, j=n-1; i<j; i++, j--) {
      if (s[i] == '?') {
        if (a > 0) {
          s[i] = s[j] = '0';
          a -= 2;
        } else if (b > 0) {
          s[i] = s[j] = '1';
          b -= 2;
        }
      }
    }

    if (a == 0 && b == 0 && ok && equal(s.begin(), s.end(), s.rbegin())) {
      cout << s << '\n';
    } else {
      cout << "-1\n";
    }
  }
}
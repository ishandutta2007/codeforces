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
    int n;
    string s;
    cin >> n >> s;
    // l = 1?
    int f = 0;
    for (char x='a'; x<='z'; x++) {
      if (count(begin(s), end(s), x) == 0) {
        cout << x << '\n';
        f = 1;
        break;
      }
    }

    if (f) continue;

    for (char x='a'; x<='z'; x++) {
      for (char y='a'; y<='z'; y++) {
        string t = {x, y};
        if (s.find(t) == string::npos) {
          cout << t << '\n';
          x = y = 'z' + 1;
          f = 1;
          break;
        }
      }
    }

    if (f) continue;

    for (char x='a'; x<='z'; x++) {
      for (char y='a'; y<='z'; y++) {
        for (char z='a'; z<='z'; z++) {
          string t = {x, y, z};
          if (s.find(t) == string::npos) {
            cout << t << '\n';
            x = y = z = 'z' + 1;
            break;
          }
        }
      }
    }
  }
}
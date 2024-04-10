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
    int x;
    cin >> x;
    string s;
    for (int i=9; i>=1; i--) {
      int d = min(i, x);
      s = to_string(d) + s;
      x -= d;
      if (!x) break;
    }

    if (x) s = "-1";
    cout << s << '\n';
  }
}
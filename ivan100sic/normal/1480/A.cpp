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
    string s;
    cin >> s;
    int n = s.size();
    for (int i=0; i<n; i++) {
      if (i % 2 == 0) {
        s[i] = s[i] == 'a' ? 'b' : 'a';
      } else {
        s[i] = s[i] == 'z' ? 'y' : 'z';
      }
    }
    cout << s << '\n';
  }
}
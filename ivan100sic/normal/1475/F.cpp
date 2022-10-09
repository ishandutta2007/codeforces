// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool dva(set<string> s) {
  string a = *s.begin();
  string b = *next(s.begin());
  for (int i=0; i<(int)a.size(); i++) {
    if (a[i] == b[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    for (int i=0; i<n; i++) {
      string b;
      cin >> b;
      for (int j=0; j<n; j++) {
        a[i][j] ^= b[j] - '0';
      }
    }
    set<string> s(begin(a), end(a));
    if (s.size() == 1 || (s.size() == 2 && dva(s))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
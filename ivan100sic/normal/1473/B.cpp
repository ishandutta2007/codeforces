// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

bool deli(string a, string b) {
  if (a.size() % b.size()) return false;
  for (int i=0; i<(int)a.size(); i++) {
    if (a[i] != b[i%b.size()]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    string a, b;
    int f = 0;
    cin >> a >> b;
    for (int x=1; x<=20; x++) {
      string t;
      for (int i=0; i<x; i++) {
        t += a;
      }

      if (deli(t, b)) {
        cout << t << '\n';
        f = 1;
        break;
      }
    }

    if (!f) {
      cout << "-1\n";
    }
  }
}
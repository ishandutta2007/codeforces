// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  string s;
  cin >> s;

  vector<int> a;
  for (char c : s) {
    a.push_back(c - 'A');
  }

  for (int i=2; i<(int)s.size(); i++) {
    if ((a[i-2] + a[i-1] - a[i]) % 26) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
}
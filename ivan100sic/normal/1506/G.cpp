// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string solve(string a) {
  set<char> s(begin(a), end(a));
  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    char x = *it;
    int i = a.find(x);
    if (set<char>(begin(a) + i, end(a)) == s) {
      // moze
      string t;
      copy_if(begin(a) + i + 1, end(a), back_inserter(t), [&](char c) { return c != x; });
      return string(1, x) + solve(t);
    }
  }
  return "";
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << '\n';
  }
}
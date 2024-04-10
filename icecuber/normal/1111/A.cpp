#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cerr << #x << " = " << (x) << endl;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string vowel = "aeiou";
  set<char> vow;
  for (char c : vowel) vow.insert(c);
  string s, t;
  int ok = 0;
  cin >> s >> t;
  if (s.size() == t.size()) {
    ok = 1;
    for (int i = 0; i < s.size(); i++) {
      if (vow.count(s[i]) != vow.count(t[i])) ok = 0;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}
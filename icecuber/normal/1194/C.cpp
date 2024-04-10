#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s, t, p;
    cin >> s >> t >> p;
    int i = 0;
    for (char c : t)
      if (i < s.size() && c == s[i]) i++;
    int count[26] = {};
    for (char c : s) count[c-'a']++;
    for (char c : p) count[c-'a']++;
    for (char c : t) count[c-'a']--;
    int ok = i == s.size();
    for (int i = 0; i < 26; i++)
      ok &= count[i] >= 0;
    cout << (ok ? "YES" : "NO") << endl;
  }
}
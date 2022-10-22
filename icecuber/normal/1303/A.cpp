#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    while (s.size() && s[0] == '0') s = s.substr(1, s.size()-1);
    while (s.size() && s.back() == '0') s = s.substr(0, s.size()-1);
    cout << s.size() - count(s.begin(), s.end(), '1') << endl;
  }
}
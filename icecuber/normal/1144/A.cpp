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
    map<char, int> m;
    int ok = 1;
    for (char c : s) if (m[c]++) ok = 0;
    cout << (m.rbegin()->first-m.begin()->first == int(s.size())-1 && ok ? "Yes" : "No") << endl;
  }
}
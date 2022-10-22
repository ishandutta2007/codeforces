#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    vector<int> a, b;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == 'A') a.push_back(i);
      else b.push_back(i);
    }
    int ok = a.size() >= b.size() && b.size() && s.back() == 'B';
    for (int i = 0; ok && i < (int)b.size(); i++) ok &= a[i] < b[i];
    cout << (ok ? "YES" : "NO") << endl;
  }
}
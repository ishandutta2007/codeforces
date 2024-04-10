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
    int cnt[256] = {};
    for (char c : s) cnt[c]++;
    for (int i = 0; i < (int)s.size(); i++) {
      if (cnt[s[i]]-- == 1) {
        cout << s.substr(i) << endl;
        break;
      }
    }
  }
}
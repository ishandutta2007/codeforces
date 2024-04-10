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
    if (s.size() == 2) cout << s[1] << endl;
    else cout << *min_element(s.begin(), s.end()) << endl;
  }
}
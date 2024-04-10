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
    for (int i = 0; i < (int)s.size(); i += 2)
      cout << s[i];
    cout << s.back();
    cout << endl;
  }
}
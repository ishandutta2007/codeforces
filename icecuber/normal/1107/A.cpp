#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    string s;
    cin >> n >> s;
    if (n == 2 && s[0] >= s[1]) {
      cout << "NO" << endl;
    } else cout << "YES" << endl << 2 << endl << s[0] << ' ' << s.substr(1,n-1) << endl;
  }
}
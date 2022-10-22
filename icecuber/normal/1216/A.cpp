#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n; i += 2) {
    if (s[i] == s[i+1]) {
      s[i+1] ^= 'a'^'b';
      ans++;
    }
  }
  cout << ans << endl;
  cout << s << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int ans = 0;
  for (int i = 0; i < x; i++) {
    ans += s[i]-'0' != (i==y);
  }
  cout << ans << endl;
}
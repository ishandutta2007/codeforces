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
    int cnt[256] = {};
    for (char c : s) {
      cnt[c]++;
    }
    string ans;
    int lr = min(cnt['L'], cnt['R']), ud = min(cnt['U'], cnt['D']);
    if (ud == 0) lr = min(lr, 1);
    if (lr == 0) ud = min(ud, 1);
    for (int i = 0; i < lr; i++)
      ans += "L";
    for (int i = 0; i < ud; i++)
      ans += "U";
    for (int i = 0; i < lr; i++)
      ans += "R";
    for (int i = 0; i < ud; i++)
      ans += "D";
    cout << ans.size() << '\n';
    cout << ans << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  string ans;
  for (int i = 0; i < n; i++) {
    if (i < n-1 && s[i] == s[i+1]) continue;
    if (i < n-1) {
      ans += s[i];
      ans += s[i+1];
      i++;
    }
  }
  cout << s.size()-ans.size() << endl << ans << endl;
}
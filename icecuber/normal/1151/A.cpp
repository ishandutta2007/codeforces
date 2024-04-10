#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = "ACTG";
  int ans = 1e9;
  for (int i = 0; i+4 <= s.size(); i++) {
    int v = 0;
    for (int j = 0; j < 4; j++) {
      v += min((s[i+j]-t[j]+26)%26, (-s[i+j]+t[j]+26)%26);
    }
    ans = min(ans, v);
  }
  cout << ans << endl;
}
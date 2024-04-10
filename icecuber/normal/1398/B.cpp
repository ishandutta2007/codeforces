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
    vector<int> streak = {0};
    for (char c : s) {
      if (c == '1') streak.back()++;
      else streak.push_back(0);
    }
    sort(streak.rbegin(), streak.rend());
    int ans = 0;
    for (int i = 0; i < streak.size(); i += 2)
      ans += streak[i];
    cout << ans << endl;
  }
}
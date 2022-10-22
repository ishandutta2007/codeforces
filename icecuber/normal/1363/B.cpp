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
    int n = s.size();
    vector<int> acc = {0};
    for (int i = 0; i < n; i++) {
      acc.push_back(s[i]-'0'+acc[i]);
    }
    int ans = n;
    for (int i = 0; i <= n; i++) {
      ans = min(ans, acc[i]+n-i-(acc[n]-acc[i]));
      ans = min(ans, i-acc[i]+(acc[n]-acc[i]));
    }
    cout << ans << endl;
  }
}
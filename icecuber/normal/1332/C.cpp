#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int,string> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      int j = i%k;
      j = min(j,k-1-j);
      m[j] += s[i];
    }
    int ans = 0;
    for (auto [j,str] : m) {
      int cnt[26] = {};
      int ma = 0, sum = str.size();
      for (char c : str)
	ma = max(ma, ++cnt[c-'a']);
      ans += sum-ma;
    }
    cout << ans << endl;
  }
}
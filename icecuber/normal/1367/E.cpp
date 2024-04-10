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
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s)
      cnt[c-'a']++;
    int ans = 1;
    for (int x = 1; x <= n; x++) {
      int g = gcd(x, k);
      int got = 0;
      for (int c = 0; c < 26; c++) {
	got += cnt[c]/(x/g);
      }
      if (got >= g) ans = x;
    }
    cout << ans << endl;
  }
}
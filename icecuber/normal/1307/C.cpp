#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  vector<ll> cnt(26);
  vector<vector<ll>> cnt2(26, vector<ll>(26));
  ll ans = 0;
  for (char c : s) {
    int d = c-'a';
    for (int i = 0; i < 26; i++)
      ans = max(ans, cnt2[i][d] += cnt[i]);
    ans = max(ans, ++cnt[d]);
  }
  cout << ans << endl;
}
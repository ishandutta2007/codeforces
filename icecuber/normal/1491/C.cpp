#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int& v : s) cin >> v;

    vector<ll> cnt(n);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll need = max(s[i]-1 - cnt[i], 0ll);
      ans += need;
      cnt[i] += need;

      for (int j = 2; j <= s[i] && i+j < n; j++) {
        cnt[i+j]++;
      }
      if (i+1 < n)
        cnt[i+1] += cnt[i] - (s[i]-1);
      //cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << endl;
    }

    cout << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m;
    cin >> n >> m;
    vector<int> cnt(64);
    for (int i = 0; i < m; i++) {
      ll a;
      cin >> a;
      cnt[63-__builtin_clzll(a)]++;
    }
    int left = 0, ans = 0;
    for (int i = 0; i < 64; i++) {
      left /= 2;
      left += cnt[i];
      if (n>>i&1) {
	if (left) {
	  left--;
	} else {
	  int j = i;
	  while (j < 64 && !cnt[j]) j++;
	  if (j == 64) {
	    cout << -1 << endl;
	    goto fail;
	  }
	  while (j > i) {
	    cnt[j]--;
	    cnt[j-1] += 2;
	    ans++;
	    j--;
	  }
	  cnt[i]--;
	}
      }
    }
    cout << ans << endl;
    continue;
  fail:;
  }
}
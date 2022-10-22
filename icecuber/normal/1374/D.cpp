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
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[(k-a%k)%k]++;
    }
    ll ans = 0;
    for (auto [r,c] : cnt) {
      if (!r) continue;
      ans = max(ans, ll(c-1)*k+r+1);
    }
    cout << ans << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll cnt[4] = {};
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    cnt[(x%4==2)*2+(y%4==2)]++;
  }
  ll ans = 0;
  for (int i = 0; i < 4; i++) {
    ans += cnt[i]*(cnt[i]-1)*(cnt[i]-2)/6;
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      ans += cnt[i]*(cnt[i]-1)/2*cnt[j];
    }
  }
  cout << ans << endl;
}
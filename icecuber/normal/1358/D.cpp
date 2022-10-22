#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll x;
  cin >> x;
  vector<ll> d(n);
  for (ll&v : d) cin >> v;
  auto cp = d;
  for (ll v : cp) d.push_back(v);
  n *= 2;
  ll hugs = 0, ans = 0, len = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    hugs += d[i]*(d[i]+1)/2;
    len += d[i];
    while (len > x) {
      hugs -= d[j]*(d[j]+1)/2;
      len -= d[j];
      j++;
    }
    ll score = hugs;
    if (j) {
      ll skips = d[j-1]+len-x;
      score += d[j-1]*(d[j-1]+1)/2-skips*(skips+1)/2;
    }
    ans = max(ans, score);
  }
  cout << ans << endl;
}
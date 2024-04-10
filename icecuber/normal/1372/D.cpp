#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  vector<ll> acc[2];
  for (int k : {0,1}) {
    acc[k].resize(n+1);
    for (int i = 0; i < n; i++) {
      acc[k][i+1] = acc[k][i]+(i%2 == k ? a[i] : 0);
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll score = acc[i%2][n]-acc[i%2][i]+acc[1-i%2][i];
    ans = max(ans, score);
  }
  cout << ans << endl;
}
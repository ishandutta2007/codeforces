#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (ll&v : a) cin >> v;
  for (ll&v : b) cin >> v, v--;
  vector<int> order, done(n);
  function<void(int)> dfs = [&](int p) {
    if (p < 0 || done[p]++) return;
    dfs(b[p]);
    order.push_back(p);
  };
  for (int i = 0; i < n; i++) dfs(i);
  ll ans = 0;
  vector<int> path, adone(n);
  reverse(order.begin(), order.end());
  for (int i : order) {
    if (a[i] > 0) {
      adone[i] = 1;
      ans += a[i];
      path.push_back(i);
      if (b[i] >= 0)
	a[b[i]] += a[i];
    }
  }
  reverse(order.begin(), order.end());
  for (int i : order) {
    if (!adone[i]) {
      ans += a[i];
      path.push_back(i);
      if (b[i] >= 0)
	a[b[i]] += a[i];
    }
  }
  cout << ans << endl;
  for (int i : path) cout << i+1 << ' ';
  cout << endl;
}
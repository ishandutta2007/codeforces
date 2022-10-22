#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  auto f =
    [&](ll l, ll p) {
      return (l%p) * (l/p+1)*(l/p+1) + (p-l%p) * (l/p)*(l/p);
    };
  ll ans = 0;
  vector<array<ll,3>> a(n);
  priority_queue<array<ll,3>> pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i][1];
    a[i][2] = 1;
    a[i][0] = f(a[i][1], a[i][2])-f(a[i][1], a[i][2]+1);
    pq.push(a[i]);
    ans += a[i][1] * a[i][1];
  }
  for (int i = n; i < k; i++) {
    auto [gain, l, p] = pq.top();
    pq.pop();
    ans -= gain;
    p++;
    gain = f(l, p)-f(l, p+1);
    pq.push({gain, l, p});
  }
  cout << ans << endl;
}
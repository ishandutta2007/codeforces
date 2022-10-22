#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  for (ll&v : a) cin >> v;
  for (ll&v : b) cin >> v;
  ll fail = -1, pass = 1e13;
  while (pass-fail > 1) {
    ll mid = pass+fail>>1;
    vector<ll> c = a;
    priority_queue<pair<ll,int>> pq;
    for (int i = 0; i < n; i++)
      pq.push({-(c[i]/b[i]), i});
    int ok = 1;
    for (int t = 0; t < k-1; t++) {
      int i = pq.top().second;
      pq.pop();
      c[i] += mid;
      pq.push({-(c[i]/b[i]), i});
      if (-pq.top().first <= t) ok = 0;
    }
    if (ok) pass = mid;
    else fail = mid;
  }
  cout << (pass == 1e13 ? -1 : pass) << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans = 1e9;
ll bw, bh;
set<pair<int,int>> seen;
void rec(ll w, ll h, vector<ll>&a, int i) {
  if (w < h) swap(w,h);
  if (w >= bw && h >= bh) {
    ans = min(ans, i);
    return;
  }
  if (i == a.size()) return;
  if (seen.count({w,h})) return;
  seen.insert({w,h});
  rec(w*a[i], h, a, i+1);
  rec(w, h*a[i], a, i+1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll aw, ah, n;
  cin >> bw >> bh >> aw >> ah >> n;
  if (bw < bh) swap(bw,bh);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.rbegin(), a.rend());
  rec(aw, ah, a, 0);
  cout << (ans == 1e9 ? -1 : ans) << endl;
}
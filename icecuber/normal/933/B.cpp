#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll p, k;
  cin >> p >> k;
  vector<ll> ans;
  ll r = p;
  while (r) {
    ans.push_back((r%k+k)%k);
    r = (ans.back()-r)/k;
  }
  cout << ans.size() << endl;
  for (ll i : ans) cout << i << ' ';
  cout << endl;
}
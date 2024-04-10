#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a = {0};
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    a.push_back(a.back()+v);
  }
  set<ll> in;
  int j = 0;
  ll ans = 0;
  for (ll v : a) {
    while (in.count(v)) in.erase(a[j++]);
    in.insert(v);
    ans += in.size()-1;
  }
  cout << ans << endl;
}
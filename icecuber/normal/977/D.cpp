#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  set<ll> pos;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos.insert(a[i]);
  }
  map<ll,ll> prev;
  ll last = -1;
  for (int i = 0; i < n; i++) {
    if (pos.count(a[i]*2))
      prev[a[i]*2] = a[i];
    else if (a[i]%3 == 0 && pos.count(a[i]/3))
      prev[a[i]/3] = a[i];
    else last = a[i];
  }
  vector<ll> ans;
  for (int i = 0; i < n; i++){
    ans.push_back(last);
    last = prev[last];
  }
  reverse(ans.begin(), ans.end());
  for (ll v : ans)
    cout << v << ' ';
  cout << endl;
}
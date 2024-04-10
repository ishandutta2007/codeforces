#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<ll,ll>> bt(n);
  for (auto&p : bt)
    cin >> p.second >> p.first;
  sort(bt.rbegin(), bt.rend());
  multiset<int> s;
  ll sum = 0, beauty = 1e9, ans = 0;
  for (auto p : bt) {
    beauty = min(beauty, p.first);
    s.insert(p.second);
    sum += p.second;
    if (s.size() > k) {
      sum -= *s.begin();
      s.erase(s.begin());
    }
    ans = max(ans, beauty*sum);
  }
  cout << ans << endl;
}
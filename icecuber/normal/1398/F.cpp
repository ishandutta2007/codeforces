#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<array<int,2>> inv;
  inv.push_back({0,0});
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') inv.back()[1]++;
    else inv.push_back({i+1,i+1});
  }
  vector<array<int,2>> filter;
  filter.push_back({0,0});
  for (auto&[l,r] : inv) {
    if (l == 0 || r == n || s[l-1] == s[r]);
    else filter.push_back({l,r});
  }
  filter.push_back({n,n});
  //for (auto [l,r] : filter) cout << l << ' ' << r << endl;
  set<int> left;
  for (int i = 1; i < (int)filter.size(); i++) left.insert(i);
  for (int x = 1; x <= n; x++) {
    vector<int> rem;
    int prev = 0;
    int ans = 0;
    for (int i : left) {
      auto [l,r] = filter[i];

      if (filter[i-1][0] <= prev && filter[i-1][1] >= prev);
      else prev = l;

      int put = (r-prev)/x*x+prev;
      if (put >= l && put <= r);
      else put = l;
      ans += (put-prev)/x;
      prev = put;

      if (r-filter[i-1][0] <= x && i+1 < (int)filter.size() && filter[i+1][1]-l <= x)
	rem.push_back(i);
    }
    for (int i : rem) left.erase(i);
    cout << ans << ' ';
  }
  cout << endl;
}
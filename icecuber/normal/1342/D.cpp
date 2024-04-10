#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.rbegin(), a.rend());
  vector<int> c(k);
  for (int&v : c) cin >> v;
  vector<vector<int>> path;
  set<pair<int,int>> tc;
  for (int w : a) {
    if (tc.empty() || tc.begin()->first == c[w-1]) {
      tc.emplace(0,path.size());
      path.push_back({});
    }
    auto [cnt,i] = *tc.begin();
    tc.erase(tc.begin());
    tc.emplace(cnt+1,i);
    path[i].push_back(w);
  }
  cout << tc.size() << endl;
  for (auto v : path) {
    cout << v.size();
    for (int i : v) cout << ' ' << i;
    cout << endl;
  }
}
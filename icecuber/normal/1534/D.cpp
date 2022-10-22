#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
map<int,vector<int>> mem;
vector<int> query(int p) {
  if (mem.count(p)) return mem[p];
  cout << "? " << p+1 << endl;
  vector<int> r(n);
  for (int&v : r) cin >> v;
  return mem[p] = r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> base = query(0);
  vector<int> group[2];
  for (int i = 0; i < n; i++) {
    group[base[i]%2].push_back(i);
  }
  if (group[0].size() > group[1].size()+1) swap(group[0], group[1]);
  vector<array<int,2>> ans;
  for (int i : group[0]) {
    auto d = query(i);
    for (int j = 0; j < n; j++) 
      if (d[j] == 1) 
        ans.push_back({i,j});
  }
  cout << "!" << endl;
  for (auto [a,b] : ans) cout << a+1 << ' ' << b+1 << endl;
}
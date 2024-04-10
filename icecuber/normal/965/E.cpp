#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5+10;
vector<map<char,int>> tree;
int w[nax];

multiset<int> dfs(int p, int d = 0) {
  multiset<int> r;
  for (auto [c,i] : tree[p]) {
    auto b = dfs(i, d+1);
    if (b.size() > r.size()) swap(b,r);
    for (int x : b) r.insert(x);
  }
  if (w[p]) {
    r.insert(d);
  } else if (r.size() && p) {
    r.erase(r.find(*r.rbegin()));
    r.insert(d);
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  tree.push_back({});
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int p = 0;
    for (char c : s) {
      if (!tree[p].count(c)) {
	tree[p][c] = tree.size();
	tree.push_back({});
      }
      p = tree[p][c];
    }
    w[p]++;
  }
  auto r = dfs(0);
  int ans = 0;
  for (int d : r) ans += d;
  cout << ans << endl;
}
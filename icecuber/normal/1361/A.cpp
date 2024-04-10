#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 5e5;
vector<int> node[nax];

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  vector<vector<int>> pos(n);
  vector<int> target(n);
  for (int i = 0; i < n; i++) {
    cin >> target[i];
    target[i]--;
    pos[target[i]].push_back(i);
  }
  vector<int> ans;
  for (int t = 0; t < n; t++) {
    for (int i : pos[t]) {
      set<int> taken;
      for (int j : node[i]) {
	taken.insert(target[j]);
      }
      for (int x = 0; x < target[i]; x++) {
	if (!taken.count(x)) fail();
      }
      if (taken.count(target[i])) fail();
      ans.push_back(i+1);
    }
  }
  for (int v : ans) cout << v << ' ';
  cout << endl;
}
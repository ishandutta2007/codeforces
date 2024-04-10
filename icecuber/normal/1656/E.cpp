#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> node(n);
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
      node[b].push_back(a);
    }
    vector<int> ans(n);
    function<void(int,int,int)> dfs = [&](int p, int par, int s) {
      ans[p] = (int)node[p].size()*s;
      for (int i : node[p]) {
        if (i == par) continue;
        dfs(i,p, -s);
      }
    };
    dfs(0,-1,1);
    for (int i : ans) cout << i << ' ';
    cout << endl;
  }
}
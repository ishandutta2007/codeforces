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
    vector<vector<int>> node(n), rnode(n);
    for (int k : {0,1}) {
      vector<array<int,2>> a(n);
      for (int i = 0; i < n; i++) {
        a[i][1] = i;
        cin >> a[i][0];
      }
      sort(a.begin(), a.end());
      for (int i = 1; i < n; i++) {
        node[a[i][1]].push_back(a[i-1][1]);
        rnode[a[i-1][1]].push_back(a[i][1]);
      }
    }
    vector<int> done1(n), topo;
    function<void(int)> dfs1 = [&](int p) {
      if (done1[p]++) return;
      for (int i : node[p]) dfs1(i);
      topo.push_back(p);
    };
    for (int i = 0; i < n; i++) dfs1(i);

    vector<int> done2(n);
    function<void(int)> dfs2 = [&](int p) {
      if (done2[p]++) return;
      for (int i : rnode[p]) dfs2(i);
    };
    dfs2(topo.back());
    for (int i = 0; i < n; i++) cout << !!done2[i];
    cout << endl;
  }
}